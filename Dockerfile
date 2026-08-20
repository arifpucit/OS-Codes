# ---------------------------------------------------------------------------
# Operating Systems Course — containerised lab environment
# Course : https://www.arifbutt.me/courses/   (Operating Systems - New)
# Repo   : https://github.com/arifpucit/OS-Codes
#
# Build:
#   docker build -t os-lab .
#
# Run (SYS_PTRACE + unconfined seccomp are REQUIRED for gdb/strace/ltrace):
#   docker run -it --rm \
#       --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
#       -v "$PWD":/home/student/OS-Codes \
#       os-lab
#
# On Apple Silicon add:  --platform linux/amd64
# ---------------------------------------------------------------------------
FROM ubuntu:24.04

LABEL org.opencontainers.image.title="OS Course Lab (Dr. Arif Butt)"
LABEL org.opencontainers.image.source="https://github.com/arifpucit/OS-Codes"

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Karachi

# Module 1: C toolchain, x86-64 assembler, debugger, binutils, make/cmake/autotools
# Module 1: heap debugging (valgrind, electric-fence, splint) and tracing
# Modules 2-3: file system, terminal, process and scheduling utilities
# Module 4: IPC, sockets and network tools
RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential gcc g++ make gdb nasm binutils file \
      manpages manpages-dev manpages-posix manpages-posix-dev man-db less \
      cmake autoconf automake libtool pkg-config gcc-multilib libc6-dev \
      valgrind electric-fence splint strace ltrace \
      hexedit xxd bsdmainutils binutils-multiarch \
      util-linux procps psmisc htop lsof sysstat ncurses-bin schedtool bc acl attr \
      netcat-openbsd telnet iproute2 net-tools dnsutils tcpdump \
      openssh-client git curl wget vim nano tree unzip ca-certificates \
      python3 python3-pip \
 && rm -rf /var/lib/apt/lists/*

# GEF — the gdb wrapper used in Lec-1.3
RUN wget -q -O /root/.gdbinit-gef.py https://gef.blah.cat/py \
 && echo "source /root/.gdbinit-gef.py" > /root/.gdbinit

# Work as a normal user, NOT root: root bypasses file permission checks, which
# would make the Module 2 permission demos (chmod/umask/SUID) behave misleadingly.
# Ubuntu 24.04 already occupies UID 1000 with a default 'ubuntu' user, so remove it.
RUN (userdel -r ubuntu 2>/dev/null || true) \
 && useradd -m -s /bin/bash -u 1000 student \
 && cp /root/.gdbinit-gef.py /home/student/.gdbinit-gef.py \
 && echo "source /home/student/.gdbinit-gef.py" > /home/student/.gdbinit \
 && chown student:student /home/student/.gdbinit /home/student/.gdbinit-gef.py

USER student
WORKDIR /home/student/OS-Codes

CMD ["/bin/bash"]
