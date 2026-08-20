# Operating Systems — Course Code Repository 💻

[![Course](https://img.shields.io/badge/Course-Operating%20Systems-blue.svg)](https://www.arifbutt.me/courses/)
[![Language](https://img.shields.io/badge/Language-C%20%7C%20x86--64%20Assembly-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Linux%20x86__64-lightgrey.svg)](#2-set-up-your-lab-environment)
[![License](https://img.shields.io/badge/License-Educational-green.svg)](#-license)

Welcome to the **Operating Systems** course repository. This collection contains the C
and x86-64 assembly source codes and Proof-of-Concepts (PoCs) discussed during our
undergraduate-level Operating Systems lectures.

> 📘 **Lecture slides, quizzes and assignments:** <https://www.arifbutt.me/courses/> → *Operating Systems (New)*
> 📄 [git cheat sheet](https://www.arifbutt.me/wp-content/uploads/2025/08/git-cheatsheet.pdf) · [Linux commands cheat sheet](https://www.arifbutt.me/wp-content/uploads/2025/08/Linux-Commands-Cheatsheet.pdf)

---

## ⚡ Quick Start

If you already have a Linux machine (or VM) with `sudo` rights, you are four commands away
from a working lab:

```bash
git clone https://github.com/arifpucit/OS-Codes.git
cd OS-Codes
chmod +x setup-os-lab.sh
./setup-os-lab.sh
```

Then confirm everything landed:

```bash
./setup-os-lab.sh --verify
```

Don't have Linux yet? Start at [§2 Set up your lab environment](#2-set-up-your-lab-environment).

---

## 📑 Table of Contents

1. [Clone the repository](#1-clone-the-repository)
2. [Set up your lab environment](#2-set-up-your-lab-environment)
3. [Install the course toolchain](#3-install-the-course-toolchain)
4. [Verify your setup](#4-verify-your-setup)
5. [Tools used in this course](#5-tools-used-in-this-course)
6. [Repository structure](#6-repository-structure)
7. [Build & run cheat sheet](#7-build--run-cheat-sheet)
8. [Programming assignments](#8-programming-assignments)
9. [Troubleshooting](#9-troubleshooting)
10. [Learning approach](#-learning-approach)

---

## 1. Clone the Repository

### If you only want to read and run the code

```bash
# Clone over HTTPS (no GitHub account needed)
git clone https://github.com/arifpucit/OS-Codes.git
cd OS-Codes
```

Pull the latest lecture code before every class:

```bash
git pull origin main
```

### If you want to submit your own work (recommended)

You cannot push to the instructor's repository, so **fork it first**. This also gives you a
place to practise the git/GitHub workflow from Lec-1.5.

1. Click **Fork** at the top-right of <https://github.com/arifpucit/OS-Codes>.
2. Clone *your* fork and add the original as an `upstream` remote:

```bash
git clone https://github.com/<your-github-username>/OS-Codes.git
cd OS-Codes
git remote add upstream https://github.com/arifpucit/OS-Codes.git
git remote -v                      # origin = your fork, upstream = instructor's repo
```

3. Whenever new lecture code is pushed, sync your fork:

```bash
git fetch upstream
git merge upstream/main            # or: git rebase upstream/main
git push origin main
```

4. Do your own experiments on a branch, so your work never collides with course updates:

```bash
git switch -c my-experiments
```

> 💡 **About the `.gitignore`:** it is written so that *files without an extension are ignored*.
> Since compiled binaries are usually extensionless (`./hello`, `./a.out`), your executables and
> `*.o` files stay out of git automatically. Source files are always tracked.

---

## 2. Set Up Your Lab Environment

Everything in this course assumes a **Linux, x86-64** machine with a real terminal. Pick
whichever path matches the computer you own:

| # | Your machine | Recommended path | Notes |
|---|---|---|---|
| A | Windows or macOS (Intel) | **VirtualBox + Ubuntu 24.04 LTS** | The path demonstrated in Lec-1.1. Works for all six modules. |
| B | Windows 10/11 | **WSL2 + Ubuntu** | Lighter than a VM. Needs one extra step for `systemd` (Lec-3.2). |
| C | macOS on Apple Silicon (M1–M4) | **UTM / Docker with x86-64 emulation** | Native ARM **cannot** run the Module 1 x86-64 assembly. See below. |
| D | Any machine, quick throwaway lab | **Docker container** | Fastest to build. Not suitable for the `systemd` topics. |
| E | Already on Linux | **Nothing to do** | Jump straight to [§3](#3-install-the-course-toolchain). |

---

### Option A — VirtualBox VM (the path shown in Lec-1.1)

1. Install [VirtualBox 7.x](https://www.virtualbox.org/wiki/Downloads) for your host OS.
2. Download the [Ubuntu 24.04 LTS Desktop ISO](https://ubuntu.com/download/desktop).
3. Create the VM with settings that actually matter for this course:

   | Setting | Value | Why it matters |
   |---|---|---|
   | RAM | 4 GB minimum (8 GB comfortable) | gdb + GEF and VS Code are memory hungry |
   | **CPUs** | **2 or more** | Module 5 race conditions are far more visible on multiple cores |
   | Disk | 40 GB dynamically allocated | toolchain + kernel headers + your own builds |
   | Enable PAE/NX, VT-x/AMD-V | On | required for 64-bit guests |

4. Install Ubuntu, then install **Guest Additions** (`Devices → Insert Guest Additions CD Image`)
   for shared clipboard, shared folders and a resizable window.
5. Open a terminal inside the VM and continue with [§3](#3-install-the-course-toolchain).

---

### Option B — WSL2 on Windows

```powershell
# In PowerShell as Administrator
wsl --install -d Ubuntu-24.04
```

Reboot, let Ubuntu finish first-time setup, then open the **Ubuntu** terminal.

`systemd` is off by default in WSL, which breaks the `systemctl` demos in Lec-3.2. Turn it on:

```bash
sudo tee /etc/wsl.conf > /dev/null <<'EOF'
[boot]
systemd=true
EOF
```

Then from PowerShell: `wsl --shutdown`, and reopen Ubuntu.

> ⚠️ Keep the repository inside the **Linux** file system (`~/OS-Codes`), not under `/mnt/c/...`.
> Building on the Windows drive is slow and the DrvFs mount does not honour UNIX permission bits,
> which quietly breaks the Module 2 `chmod`/`umask`/SUID demonstrations.

---

### Option C — Apple Silicon Macs (M1 / M2 / M3 / M4)

Module 1 is **x86-64 assembly** (`nasm -felf64`, `syscall`, `rax/rdi/rsi/rdx`). An ARM64 Linux
VM will happily install `nasm` and then refuse to run anything you assemble. You need x86-64
emulation:

- **UTM** (<https://mac.getutm.app>) → create an **Emulate** (not Virtualise) x86_64 VM and
  install Ubuntu 24.04. Correct but slow.
- **Docker Desktop** with Rosetta → build the image with `--platform linux/amd64` (see Option D).
  Usually the fastest option on Apple Silicon.
- **A cloud VM** (any x86-64 Linux instance) via `ssh`.

Modules 2–6 are portable C and will run natively on ARM, so an ARM VM is fine for those — but
you will still hit differences in pointer/stack layout output whenever a lecture prints addresses.

---

### Option D — Docker container

A [`Dockerfile`](Dockerfile) is included in this repository.

```bash
docker build -t os-lab .

docker run -it --rm \
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
    -v "$PWD":/home/student/OS-Codes \
    os-lab
```

On Apple Silicon: `docker build --platform linux/amd64 -t os-lab .`

> ⚠️ Two things to know about containers:
> - `--cap-add=SYS_PTRACE --security-opt seccomp=unconfined` is **not optional**. Without it
>   `gdb`, `strace` and `ltrace` are blocked from attaching, and most of Module 1 stops working.
> - Containers do not run `systemd`, so the daemon/`systemctl` part of **Lec-3.2** needs a real
>   VM or WSL2. Everything else — files, processes, threads, IPC, sockets, semaphores — works.

---

## 3. Install the Course Toolchain

From the root of your cloned repository:

```bash
chmod +x setup-os-lab.sh
./setup-os-lab.sh
```

The script installs every command line tool used across Modules 1–6, then runs a verification
checklist and a compile-and-run smoke test.

**Options:**

| Command | Effect |
|---|---|
| `./setup-os-lab.sh` | Everything, plus the GEF debugger wrapper *(default)* |
| `./setup-os-lab.sh --minimal` | Compiler, assembler, debugger, make and git only |
| `./setup-os-lab.sh --with-peda` | Also install PEDA alongside GEF |
| `./setup-os-lab.sh --no-gef` | Plain `gdb`, no wrapper |
| `./setup-os-lab.sh --verify` | Run the checklist only, install nothing |

### Prefer to type it yourself?

Nothing is hidden — this is the same package set in one command:

```bash
sudo apt update && sudo apt install -y \
  build-essential gcc g++ make gdb nasm binutils file \
  manpages manpages-dev manpages-posix manpages-posix-dev man-db \
  cmake autoconf automake libtool pkg-config gcc-multilib libc6-dev \
  valgrind electric-fence splint strace ltrace \
  hexedit xxd bsdmainutils binutils-multiarch \
  util-linux procps psmisc htop lsof sysstat ncurses-bin schedtool bc acl attr \
  netcat-openbsd telnet iproute2 net-tools dnsutils tcpdump openssh-client \
  git curl wget vim nano tree unzip python3 python3-pip
```

### GDB wrappers (Lec-1.3)

The lectures use **GEF** on top of `gdb`. Install it manually with:

```bash
wget -O ~/.gdbinit-gef.py https://gef.blah.cat/py
echo "source ~/.gdbinit-gef.py" >> ~/.gdbinit
```

If you also want **PEDA**, do *not* source both from `~/.gdbinit` — they conflict. Give PEDA its
own init file and an alias instead:

```bash
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" > ~/.gdbinit-peda
echo "alias gdb-peda='gdb -q -nx -x ~/.gdbinit-peda'" >> ~/.bashrc
```

Now `gdb` gives you GEF and `gdb-peda` gives you PEDA.

### Not on Debian/Ubuntu?

The script targets `apt`. On other distributions install the equivalents:

```bash
# Fedora / RHEL
sudo dnf install gcc gcc-c++ make gdb nasm binutils glibc-devel man-pages \
     cmake autoconf automake libtool valgrind strace ltrace splint \
     util-linux procps-ng psmisc htop lsof nmap-ncat iproute net-tools git vim

# Arch
sudo pacman -S base-devel gdb nasm cmake valgrind strace ltrace \
     man-pages man-db util-linux procps-ng psmisc htop lsof gnu-netcat git vim
```

---

## 4. Verify Your Setup

```bash
./setup-os-lab.sh --verify
```

You should see `OK` against each tool, grouped by the module that needs it, followed by:

```
[+] All 48 checks passed — your lab environment is ready.
[+] C + pthreads toolchain works.
[+] nasm + ld toolchain works (x86-64).
```

Then prove it end to end with real lecture code:

```bash
cd Module-1/Lec-1.3/hello
gcc hello.c -o hello && ./hello

cd ../../Lec-1.2
nasm -felf64 syscalls.nasm -o syscalls.o && ld syscalls.o -o syscalls && ./syscalls
# → Learning is fun with Arif
```

---

## 5. Tools Used in This Course

| Tool | Package | Where it is used |
|---|---|---|
| `gcc`, `cpp`, `as`, `ld` | `build-essential` | Lec-1.3 — the four phases of C compilation |
| `nasm` | `nasm` | Lec-1.2 — x86-64 assembly (`nasm -felf64`) |
| `gdb` + **GEF** / **PEDA** | `gdb` | Lec-1.2, 1.3, 1.6 — debugging C and assembly |
| `ar`, `ranlib` | `binutils` | Lec-1.3 — building static libraries |
| `readelf`, `objdump`, `nm`, `strings`, `strip`, `objcopy`, `size` | `binutils` | Lec-1.3 — inspecting ELF binaries |
| `file`, `hexedit`, `xxd` | `file`, `hexedit` | Lec-1.3 — identifying and editing binary content |
| `ldd`, `ldconfig` | `libc-bin` | Lec-1.3 — shared libraries, PLT and GOT |
| `make` | `make` | Lec-1.4 — the make utility, PA-03 |
| `cmake`, `autoconf`, `automake`, `libtool` | `cmake`, `autoconf`… | Lec-1.4 — building open-source software |
| `git` | `git` | Lec-1.5 — version control and the GitHub workflow |
| `valgrind`, `splint`, Electric Fence | `valgrind`, `splint`, `electric-fence` | Lec-1.6 — heap and `malloc` debugging |
| `strace`, `ltrace` | `strace`, `ltrace` | Modules 1–4 — tracing system and library calls |
| `stat`, `chmod`, `chown`, `umask`, `ln`, `tree` | `coreutils`, `tree` | Lec-2.1, 2.3 — permissions, links, file attributes |
| `stty`, `tty`, `mknod` | `coreutils`, `util-linux` | Lec-2.4 — terminal drivers, canonical vs non-canonical mode |
| `ps`, `top`, `htop`, `pstree`, `ulimit` | `procps`, `htop`, `psmisc` | Lec-3.1, 3.2 — process management |
| `nice`, `renice`, `taskset`, `chrt`, `schedtool` | `coreutils`, `util-linux`, `schedtool` | Lec-3.5 — scheduling policies and affinity |
| `systemctl` | `systemd` | Lec-3.2 — daemons |
| `ipcs`, `ipcrm` | `util-linux` | Lec-4.3 — System-V message queues and shared memory |
| `mkfifo` | `coreutils` | Lec-4.2 — named pipes (FIFOs) |
| `nc` (netcat), `telnet`, `ss`, `ip`, `tcpdump` | `netcat-openbsd`, `telnet`, `iproute2`, `tcpdump` | Lec-4.4 — TCP/IP sockets, testing your servers |
| `man` (sections 2 & 3) | `manpages-dev`, `manpages-posix-dev` | Every lecture — `man 2 fork`, `man 3 pthread_create` |

> 🔎 **`manpages-dev` and `manpages-posix-dev` matter more than students expect.** Without them
> `man 2 open` shows nothing and you lose the single most useful reference in the entire course.

---

## 6. Repository Structure

```
OS-Codes/
├── Module-1/                     Toolchain: Source Code → Program → Process
│   ├── Lec-1.2/                  x86-64 assembly: syscalls, libcalls, jumps, function calls
│   │   └── gdb/                  assembly programs to step through inside gdb
│   ├── Lec-1.3/                  C compilation & linking
│   │   ├── hello/                the four phases (.i → .s → .o → binary)
│   │   ├── syscalls/             system call with and without a wrapper
│   │   ├── multi_file/           multi-file compilation
│   │   ├── staticlib/            build and use your own .a with ar
│   │   ├── dynamiclib/           build and use your own .so
│   │   ├── plt-got/              lazy binding, PLT vs GOT
│   │   └── gdb-gef/              gdb + GEF walkthrough and command list
│   ├── Lec-1.4/                  make utility: ex0–ex5, autotools template
│   └── Lec-1.6/                  process layout
│       ├── stack/                command line arguments, environment variables
│       ├── heap/                 brk/sbrk, heap bugs, allocated blocks
│       └── func-calling-convention/
│
├── Module-2/                     File Management
│   ├── Lec-2.2/                  universal I/O: open-read-write-close (file_io1–8)
│   ├── Lec-2.3/                  dup/dup2 redirection, lseek, stat, directories
│   └── Lec-2.4/                  special files & terminal drivers (termios, canonical modes)
│
├── Module-3/                     Process Management & Scheduling
│   ├── Lec-3.1/                  fork, ids, exit handlers, orphans and zombies
│   ├── Lec-3.2/                  wait/waitpid, exec family, system(), daemons
│   └── Lec-3.3/                  POSIX threads: creation, joining, attributes, arrays
│
├── Module-4/                     Inter-Process Communication
│   ├── Lec-4.1/                  signals: sending, handling, masking
│   ├── Lec-4.2/                  unnamed pipes and FIFOs
│   ├── Lec-4.3/                  System-V message queues and shared memory
│   └── Lec-4.4/                  TCP/IP sockets: echo & daytime client/server, bind shell
│
├── Module-5/                     Synchronization & Deadlocks
│   ├── Lec-5.1/                  race conditions
│   ├── Lec-5.2/                  mutex, spinlock, barrier, condition variables
│   └── Lec-5.3/                  named and unnamed POSIX semaphores
│
├── Module-6/                     Memory Management
│
├── Programming-Assignments/
│   ├── PA-01/
│   ├── PA-02/                    lsv1.0.0.c — write your own `ls`
│   └── PA-03/                    base-assignment-03 — write your own shell
│
├── setup-os-lab.sh               one-shot lab environment installer
├── Dockerfile                    containerised lab environment
└── README.md
```

---

## 7. Build & Run Cheat Sheet

Compilation is not uniform across modules — several lectures need extra flags. Keep this handy.

### Plain C (Modules 2, 3, 4)

```bash
gcc program.c -o program
./program
```

Always develop with warnings and debug symbols on:

```bash
gcc -g -Wall -Wextra program.c -o program
```

### x86-64 assembly (Lec-1.2)

Which linker you use depends on what the program calls:

```bash
# Program uses raw system calls and defines _start
nasm -felf64 syscalls.nasm -o syscalls.o
ld syscalls.o -o syscalls
./syscalls

# Program calls C library functions (printf, exit) and defines main
nasm -felf64 libcalls.nasm -o libcalls.o
gcc -no-pie libcalls.o -o libcalls
./libcalls
```

> Each `.nasm` file in this repository carries its own assemble/link/usage recipe in the header
> comment — read the top four lines before you build.

### Threads and semaphores (Lec-3.3, 5.2, 5.3)

```bash
gcc race1.c -o race1 -lpthread          # -lpthread is required
gcc solrace_processes.c -o sol -lpthread
```

### Static and dynamic libraries (Lec-1.3)

```bash
# Static library
gcc -c myadd.c mysub.c mymul.c mydiv.c
ar rcs libarifmath.a myadd.o mysub.o mymul.o mydiv.o
gcc driver.c -L. -larifmath -o driver

# Dynamic library
gcc -c -fPIC myadd.c mysub.c mymul.c mydiv.c
gcc -shared -o libarifmath.so myadd.o mysub.o mymul.o mydiv.o
gcc driver.c -L. -larifmath -o driver
LD_LIBRARY_PATH=. ./driver          # or copy the .so to /usr/local/lib && sudo ldconfig
```

### Projects with a Makefile (Lec-1.4, PA-03)

```bash
make            # build
make clean      # remove objects and binaries
```

### Inspecting what you just built

```bash
file ./program            # ELF type, dynamically vs statically linked, PIE or not
readelf -h ./program      # ELF header
readelf -S ./program      # section headers
objdump -d ./program      # disassembly
nm ./program              # symbol table
strings ./program         # printable strings
ldd ./program             # shared library dependencies
strace ./program          # system calls made at run time
ltrace ./program          # library calls made at run time
valgrind --leak-check=full ./program
```

### Debugging

```bash
gcc -g -O0 program.c -o program     # -g for symbols, -O0 so the source still matches
gdb -q ./program                    # GEF loads automatically
gdb -q ./program -tui               # split source/assembly view (used in Lec-1.2)
```

### Cleaning up System-V IPC objects (Lec-4.3)

Message queues and shared memory segments **outlive the process that created them**. If your
program crashes before cleaning up, remove the leftovers by hand:

```bash
ipcs                      # list message queues, shared memory, semaphores
ipcrm -q <msqid>          # remove a message queue
ipcrm -m <shmid>          # remove a shared memory segment
```

---

## 8. Programming Assignments

| # | Task | Handout |
|---|---|---|
| PA-01 | make utility | [PA-01.pdf](https://www.arifbutt.me/wp-content/uploads/2025/09/PA-01.pdf) |
| PA-02 | Write your own `ls` (`lsv1.0.0.c`) | [PA-02.pdf](https://www.arifbutt.me/wp-content/uploads/2025/09/PA-02.pdf) |
| PA-03 | Write your own UNIX shell | [PA-03.pdf](https://www.arifbutt.me/wp-content/uploads/2025/09/PA-03.pdf) |

The `Programming-Assignments/` directory holds the base code you build on. Work on **your own
fork**, commit in small logical steps, and use tags/releases as demonstrated in Lec-1.5 — the
git history is part of what is being assessed.

---

## 9. Troubleshooting

<details>
<summary><b><code>gcc: command not found</code> / <code>nasm: command not found</code></b></summary>

The toolchain was never installed, or you installed it in a different environment (host vs VM vs
container). Run `./setup-os-lab.sh --verify` inside the machine where you are compiling.
</details>

<details>
<summary><b><code>undefined reference to 'pthread_create'</code></b></summary>

Missing link flag. Add `-lpthread` **at the end** of the command:
`gcc race1.c -o race1 -lpthread`
</details>

<details>
<summary><b><code>man 2 open</code> shows "No manual entry"</b></summary>

Install the developer man pages: `sudo apt install manpages-dev manpages-posix-dev`
</details>

<details>
<summary><b>gdb: "ptrace: Operation not permitted" (inside Docker)</b></summary>

Re-run the container with `--cap-add=SYS_PTRACE --security-opt seccomp=unconfined`.
</details>

<details>
<summary><b>Assembly assembles but dies with "Exec format error" or illegal instruction</b></summary>

You are on ARM (Apple Silicon or a Raspberry Pi). `nasm -felf64` emits x86-64 code that ARM
cannot execute. See [Option C](#option-c--apple-silicon-macs-m1--m2--m3--m4).
</details>

<details>
<summary><b><code>./program: error while loading shared libraries: libarifmath.so</code></b></summary>

The loader cannot find your shared object. Either
`LD_LIBRARY_PATH=. ./program`, or copy the `.so` into `/usr/local/lib` and run `sudo ldconfig`.
</details>

<details>
<summary><b>My shared memory / message queue program fails on the second run</b></summary>

A previous run left the IPC object behind. List with `ipcs` and delete with
`ipcrm -m <shmid>` or `ipcrm -q <msqid>`.
</details>

<details>
<summary><b>"Address already in use" when restarting a socket server (Lec-4.4)</b></summary>

The port is in `TIME_WAIT`. Either wait ~60 seconds, or set `SO_REUSEADDR` with `setsockopt()`
before `bind()` — which is exactly the lesson that error is trying to teach.
</details>

<details>
<summary><b>My race-condition program never shows a race</b></summary>

Give the VM at least 2 CPUs (`nproc` to check), and run the program in a loop — races are
probabilistic by nature.
</details>

<details>
<summary><b>Addresses printed by my program change on every run</b></summary>

That is ASLR, and it is normal. To compare addresses across runs while studying process layout:
`setarch $(uname -m) -R ./program`. Inside `gdb`, ASLR is already disabled by default.
</details>

---

## 📖 Learning Approach

> **Important Note:** While these source codes are provided to save your typing effort, I
> **strongly recommend** that you:
>
> - ✅ Type the programs yourself for better understanding
> - ✅ Compile and execute them independently
> - ✅ Make modifications and experiment with the code
> - ✅ Do "Scuba Diving" into the underlying concepts

### 🎯 Learning Philosophy

*"The best way to learn programming is by programming!"*

Don't just copy-paste the code. Engage with it, modify it, break it, and fix it. This hands-on
approach will deepen your understanding of operating system concepts.

---

## 🤝 Contributing

Found a bug, a typo, or a program that does not build on your setup?

- Open an [issue](https://github.com/arifpucit/OS-Codes/issues)
- Submit a pull request from your fork
- Or contact the instructor directly

---

## 👨‍🏫 Meet Your Instructor

### Dr. Muhammad Arif Butt

**Assistant Professor, Department of Data Science**
**University of the Punjab, Lahore**

#### 🎓 Educational Background
- **Pakistan Military Academy, Kakul** — Graduate
- **MPhil Computer Science** — University of the Punjab, Lahore
- **PhD Computer Science** — University of the Punjab, Lahore

#### 💼 Professional Experience
- 🎖️ **Pakistan Army** — Served in field/staff/instructional posts
- 👨‍🏫 **Assistant Professor** — Department of Data Science
- 🚀 **Founder** — [Excaliat](https://excaliat.com/en)
- 🦅 **Founder** — [FalconHunt](https://falconhunt.org/)
- 🔧 **Co-Founder** — [Tbox Solutionz](https://tboxsolutionz.com/)

#### 🔬 Research Interests
- Embedded and Real-Time Operating Systems
- Vulnerability Analysis, Binary Exploitation & Exploit Development
- AI-Driven Cybersecurity and Securing AI Systems

#### 📞 Connect
- 📧 **Email:** <arif@pucit.edu.pk>
- 🌐 **Website:** <https://arifbutt.me>
- 📺 **YouTube:** [Learn with Arif](https://youtube.com/learnwitharif)
- 💻 **GitHub:** [@arifpucit](https://github.com/arifpucit)
- 💼 **LinkedIn:** [Dr. Arif Butt](https://www.linkedin.com/in/dr-arif-butt/)

---

## 📜 License

This repository is for educational purposes. Please respect academic integrity guidelines when
using this code for assignments or projects.

---

## 🎉 Final Words

Happy Coding! Remember, every expert was once a beginner. Keep practicing, keep learning, and
most importantly, keep coding!

⭐ **Star this repository if you find it helpful!**
