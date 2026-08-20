#!/usr/bin/env bash
#
# setup-os-lab.sh — Build the lab environment for the Operating Systems course
# Course : https://www.arifbutt.me/courses/  (Operating Systems - New)
# Repo   : https://github.com/arifpucit/OS-Codes
# Author : Dr. Muhammad Arif Butt
#
# Installs every command line tool used across Modules 1-6 on a Debian/Ubuntu
# based machine (bare metal, VirtualBox/UTM VM, WSL2 or a Docker container).
#
# Usage:
#   chmod +x setup-os-lab.sh
#   ./setup-os-lab.sh                 # install everything + GEF
#   ./setup-os-lab.sh --minimal       # compiler/debugger/assembler only
#   ./setup-os-lab.sh --with-peda     # also install the PEDA gdb wrapper
#   ./setup-os-lab.sh --no-gef        # skip the GEF gdb wrapper
#   ./setup-os-lab.sh --verify        # only run the verification checklist
#
set -uo pipefail

# ----------------------------------------------------------------------------- 
# Options
# -----------------------------------------------------------------------------
MINIMAL=0; WITH_GEF=1; WITH_PEDA=0; VERIFY_ONLY=0

for arg in "$@"; do
  case "$arg" in
    --minimal)   MINIMAL=1 ;;
    --with-peda) WITH_PEDA=1 ;;
    --no-gef)    WITH_GEF=0 ;;
    --verify)    VERIFY_ONLY=1 ;;
    -h|--help)   sed -n '2,20p' "$0"; exit 0 ;;
    *) echo "Unknown option: $arg (try --help)"; exit 1 ;;
  esac
done

GREEN='\033[0;32m'; RED='\033[0;31m'; YELLOW='\033[0;33m'; BLUE='\033[0;34m'; NC='\033[0m'
info()  { echo -e "${BLUE}[*]${NC} $*"; }
ok()    { echo -e "${GREEN}[+]${NC} $*"; }
warn()  { echo -e "${YELLOW}[!]${NC} $*"; }
fail()  { echo -e "${RED}[-]${NC} $*"; }

# Use sudo only when we are not already root (inside Docker we usually are).
SUDO=""
[ "$(id -u)" -ne 0 ] && SUDO="sudo"

# -----------------------------------------------------------------------------
# Package groups — mapped to the module that needs them
# -----------------------------------------------------------------------------

# Module 1: C toolchain, assembler, debugger, binary inspection, make, git
CORE_PKGS=(
  build-essential gcc g++ make gdb nasm binutils file
  manpages manpages-dev manpages-posix manpages-posix-dev
  git curl wget vim nano tree unzip ca-certificates
)

# Module 1: linking, libraries, open-source build systems, heap debugging
TOOLCHAIN_PKGS=(
  cmake autoconf automake libtool pkg-config
  gcc-multilib libc6-dev
  valgrind electric-fence splint strace ltrace
  hexedit xxd bsdmainutils binutils-multiarch
)

# Modules 2-3: file system, terminals, process management and scheduling
SYSTEM_PKGS=(
  util-linux procps psmisc htop lsof sysstat
  ncurses-bin schedtool bc acl attr
)

# Module 4: IPC, sockets, network services
NETWORK_PKGS=(
  netcat-openbsd telnet iproute2 net-tools dnsutils
  openssh-client openssh-server tcpdump
)

# Optional extras
EXTRA_PKGS=( python3 python3-pip ripgrep man-db less )

# -----------------------------------------------------------------------------
# Pre-flight checks
# -----------------------------------------------------------------------------
preflight() {
  if ! command -v apt-get >/dev/null 2>&1; then
    fail "This script targets Debian/Ubuntu (apt-get not found)."
    warn "On Fedora/RHEL use dnf, on Arch use pacman — see the README for the package list."
    exit 1
  fi

  local arch; arch="$(dpkg --print-architecture)"
  info "Detected architecture: ${arch}"
  if [ "$arch" != "amd64" ]; then
    warn "Module 1 of this course is x86-64 assembly (nasm -felf64)."
    warn "On ${arch} (e.g. Apple Silicon) those programs will NOT assemble or run natively."
    warn "Use an x86_64 VM/container — see 'Apple Silicon' in the README."
    echo
  fi
}

# -----------------------------------------------------------------------------
# Install
# -----------------------------------------------------------------------------
# NOTE: `env` is spelled out explicitly. Writing `$SUDO VAR=x apt-get ...` breaks
# when $SUDO is empty (running as root): the shell resolves the command word before
# re-scanning for assignments, so `VAR=x` itself becomes the command and exits 127.
apt_get() { $SUDO env DEBIAN_FRONTEND=noninteractive apt-get "$@"; }

install_pkgs() {
  info "Updating package index ..."
  apt_get update -qq || { fail "apt-get update failed — check your network."; exit 1; }

  local pkgs=( "${CORE_PKGS[@]}" )
  if [ "$MINIMAL" -eq 0 ]; then
    pkgs+=( "${TOOLCHAIN_PKGS[@]}" "${SYSTEM_PKGS[@]}" "${NETWORK_PKGS[@]}" "${EXTRA_PKGS[@]}" )
  fi

  info "Installing ${#pkgs[@]} packages (this takes a few minutes) ..."

  # Fast path: one bulk transaction.
  if apt_get install -y -qq --no-install-recommends "${pkgs[@]}" >/dev/null 2>&1; then
    ok "All ${#pkgs[@]} packages installed."
    return
  fi

  # Slow path: a package is unavailable on this release/architecture. Retry
  # individually so one bad name cannot abort the whole run.
  warn "Bulk install failed — retrying package by package ..."
  local missed=()
  for p in "${pkgs[@]}"; do
    apt_get install -y -qq --no-install-recommends "$p" >/dev/null 2>&1 || missed+=( "$p" )
  done

  if [ ${#missed[@]} -gt 0 ]; then
    warn "Could not install: ${missed[*]}"
    warn "Most often this means the 'universe' repo is disabled. Fix with:"
    warn "  sudo add-apt-repository universe && sudo apt-get update"
    warn "On non-amd64 hosts, gcc-multilib and binutils-multiarch are expected to fail."
  else
    ok "Package installation finished."
  fi
}

# -----------------------------------------------------------------------------
# GDB enhancers (Lec-1.3 uses gdb with GEF; PEDA is the alternative)
# -----------------------------------------------------------------------------
install_gef() {
  info "Installing GEF (GDB Enhanced Features) ..."
  if wget -q -O "$HOME/.gdbinit-gef.py" https://gef.blah.cat/py; then
    grep -q 'gdbinit-gef.py' "$HOME/.gdbinit" 2>/dev/null || \
      echo "source $HOME/.gdbinit-gef.py" >> "$HOME/.gdbinit"
    ok "GEF installed. Launch it with:  gdb -q ./a.out"
  else
    warn "GEF download failed (no internet?). Install later with:"
    warn "  wget -O ~/.gdbinit-gef.py https://gef.blah.cat/py && echo 'source ~/.gdbinit-gef.py' >> ~/.gdbinit"
  fi
}

install_peda() {
  info "Installing PEDA (Python Exploit Development Assistance) ..."
  if [ ! -d "$HOME/peda" ]; then
    git clone -q https://github.com/longld/peda.git "$HOME/peda" || {
      warn "PEDA clone failed."; return; }
  fi
  # GEF and PEDA must not be sourced together — give PEDA its own init file.
  echo "source $HOME/peda/peda.py" > "$HOME/.gdbinit-peda"
  cat >> "$HOME/.bashrc" <<'EOF'

# OS course: run gdb with the PEDA wrapper instead of GEF
alias gdb-peda='gdb -q -nx -x ~/.gdbinit-peda'
EOF
  ok "PEDA installed. Launch it with:  gdb-peda ./a.out   (restart your shell first)"
}

# -----------------------------------------------------------------------------
# Verification
# -----------------------------------------------------------------------------
verify() {
  echo
  echo "==============================================================="
  echo "  Verification — tools used in the Operating Systems course"
  echo "==============================================================="
  local pass=0 miss=0

  check() { # check <command> <module/purpose>
    if command -v "$1" >/dev/null 2>&1; then
      printf "  ${GREEN}%-4s${NC} %-14s %s\n" "OK" "$1" "$2"; pass=$((pass+1))
    else
      printf "  ${RED}%-4s${NC} %-14s %s\n" "--" "$1" "$2"; miss=$((miss+1))
    fi
  }

  echo "-- Module 1: toolchain, assembly, linking, make, git ----------"
  check gcc      "C compiler"
  check cpp      "preprocessor (gcc -E)"
  check as       "GNU assembler"
  check ld       "GNU linker"
  check nasm     "x86-64 assembler (nasm -felf64)"
  check gdb      "debugger (with GEF/PEDA)"
  check make     "Lec-1.4 make utility"
  check cmake    "Lec-1.4 cmake overview"
  check autoconf "Lec-1.4 open-source builds (./configure)"
  check git      "Lec-1.5 version control"
  check ar       "static libraries (ar rcs)"
  check readelf  "ELF headers"
  check objdump  "disassembly"
  check nm       "symbol tables"
  check strings  "printable strings"
  check strip    "strip symbols"
  check objcopy  "copy/transform objects"
  check ldd      "shared library dependencies"
  check hexedit  "hex editor"
  check valgrind "Lec-1.6 heap/malloc debugging"
  check splint   "Lec-1.6 static analysis"
  check strace   "trace system calls"
  check ltrace   "trace library calls"

  echo "-- Modules 2-3: files, terminals, processes, scheduling -------"
  check stat     "file attributes"
  check stty     "Lec-2.4 terminal driver attributes"
  check mknod    "Lec-2.4 device files"
  check ps       "process status"
  check top      "process monitor"
  check htop     "interactive monitor"
  check pstree   "process trees"
  check taskset  "CPU affinity"
  check chrt     "real-time scheduling policy"
  check schedtool "Lec-3.5 scheduling utility"
  check nice     "scheduling priority"
  check systemctl "Lec-3.2 daemons (systemd)"

  echo "-- Module 4: IPC and sockets ----------------------------------"
  check ipcs     "System-V IPC status"
  check ipcrm    "remove System-V IPC objects"
  check mkfifo   "named pipes (FIFOs)"
  check nc       "netcat client/server"
  check ss       "socket statistics"
  check tcpdump  "packet capture"

  echo "-- Development headers (compile-tested) ----------------------"
  check_header() { # check_header <header> <purpose>
    if echo "#include <$1>" | gcc -E -xc - >/dev/null 2>&1; then
      printf "  ${GREEN}%-4s${NC} %-18s %s\n" "OK" "$1" "$2"; pass=$((pass+1))
    else
      printf "  ${RED}%-4s${NC} %-18s %s\n" "--" "$1" "$2"; miss=$((miss+1))
    fi
  }
  check_header pthread.h    "Lec-3.3 POSIX threads"
  check_header semaphore.h  "Lec-5.3 POSIX semaphores"
  check_header sys/shm.h    "Lec-4.3 System-V shared memory"
  check_header sys/msg.h    "Lec-4.3 System-V message queues"
  check_header sys/socket.h "Lec-4.4 BSD sockets"
  check_header termios.h    "Lec-2.4 terminal drivers"
  check_header dirent.h     "Lec-2.3 directory management"

  echo "---------------------------------------------------------------"
  if [ "$miss" -eq 0 ]; then
    ok "All ${pass} checks passed — your lab environment is ready."
  else
    warn "${pass} present, ${miss} missing. Re-run ./setup-os-lab.sh to fix."
  fi

  echo
  info "Smoke test: compiling a threaded C program and an assembly program ..."
  local tmp; tmp="$(mktemp -d)"
  printf '#include <pthread.h>\n#include <stdio.h>\nvoid*f(void*a){puts("pthreads OK");return 0;}\nint main(){pthread_t t;pthread_create(&t,0,f,0);pthread_join(t,0);return 0;}\n' > "$tmp/t.c"
  if gcc "$tmp/t.c" -o "$tmp/t" -lpthread 2>/dev/null && "$tmp/t"; then ok "C + pthreads toolchain works."; else fail "C smoke test failed."; fi

  if command -v nasm >/dev/null 2>&1 && [ "$(dpkg --print-architecture)" = "amd64" ]; then
    printf 'section .text\nglobal _start\n_start:\n mov rax,60\n xor rdi,rdi\n syscall\n' > "$tmp/s.nasm"
    if nasm -felf64 "$tmp/s.nasm" -o "$tmp/s.o" 2>/dev/null && ld "$tmp/s.o" -o "$tmp/s" 2>/dev/null && "$tmp/s"; then
      ok "nasm + ld toolchain works (x86-64)."
    else
      fail "Assembly smoke test failed."
    fi
  fi
  rm -rf "$tmp"
}

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------
echo "==============================================================="
echo "  Operating Systems Course — Lab Environment Setup"
echo "  Dr. Muhammad Arif Butt  |  arifbutt.me/courses"
echo "==============================================================="

if [ "$VERIFY_ONLY" -eq 1 ]; then verify; exit 0; fi

preflight
install_pkgs
[ "$WITH_GEF"  -eq 1 ] && install_gef
[ "$WITH_PEDA" -eq 1 ] && install_peda
verify

echo
ok "Setup complete. Next:  cd OS-Codes/Module-1/Lec-1.3/hello && gcc hello.c -o hello && ./hello"
