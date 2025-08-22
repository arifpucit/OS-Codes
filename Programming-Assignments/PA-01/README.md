# OS Assignment 01: Core C Utilities Library

## Overview

This assignment is a comprehensive hands-on project that teaches the complete professional workflow for building multi-file C projects. You will create a general-purpose utility library named `libmyutils` and learn how C programs are built, linked, and distributed in real software development environments.

## Learning Objectives

By completing this assignment, students will demonstrate proficiency in:

- **Modular Programming**: Structuring C code into reusable modules with separate header (.h) and source (.c) files
- **Static & Dynamic Libraries**: Creating both static (.a) and dynamic (.so) libraries
- **The Linking Process**: Understanding -I, -L, and -l compiler flags
- **Build Automation**: Writing professional Makefiles for complex build workflows
- **Documentation**: Creating standard Linux man pages
- **Binary Analysis**: Using tools like nm, ar, readelf, and ldd
- **Version Control Workflow**: Professional Git practices with branching and releases
- **Software Distribution**: Creating tagged releases with compiled assets

## Project Structure

Your project repository should follow this structure:

```
ROLL_NO-OS-A01/
├── include/
│   ├── mystrfunctions.h
│   └── myfilefunctions.h
├── src/
│   ├── mystrfunctions.c
│   ├── myfilefunctions.c
│   └── main.c
├── lib/
├── bin/
├── obj/
├── man/
│   └── man3/
├── Makefile
└── REPORT.md
```

## Library Components

### libmyutils Library Modules

**String Functions Module** (`mystrfunctions.h/.c`):
- Custom string manipulation functions
- Common text processing utilities

**File Functions Module** (`myfilefunctions.h/.c`):
- File-based operations
- Word counting and pattern searching utilities

**Driver Program** (`main.c`):
- Tests and demonstrates all library functions
- Serves as example usage for the library

## Features Implementation Timeline

### Feature 1: Project Scaffolding (5 marks)
- **Branch**: `main`
- **Key Concepts**: Linux File Hierarchy, Git/GitHub setup
- **Deliverable**: Complete project structure under version control

### Feature 2: Multi-file Compilation - v0.1.1 (20 marks)
- **Branch**: `multifile-build`
- **Deliverable**: Direct compilation from all source files
- **Key Concepts**: Multi-file compilation, Makefile basics, Git branching
- **Tag**: `v0.1.1-multifile`
- **Assets**: `bin/client` executable

### Feature 3: Static Library - v0.2.1 (25 marks)
- **Branch**: `static-build`
- **Deliverable**: Static library (.a) with linked executable
- **Key Concepts**: Static libraries, archiving (ar, ranlib)
- **Tag**: `v0.2.1-static`
- **Assets**: `lib/libmyutils.a`, `bin/client_static`

### Feature 4: Dynamic Library - v0.3.1 (25 marks)
- **Branch**: `dynamic-build`
- **Deliverable**: Dynamic library (.so) with linked executable
- **Key Concepts**: Shared objects, PIC, LD_LIBRARY_PATH
- **Tag**: `v0.3.1-dynamic`
- **Assets**: `lib/libmyutils.so`, `bin/client_dynamic`

### Feature 5: Documentation & Installation - v0.4.1 (15 marks)
- **Branch**: `man-pages`
- **Deliverable**: Man pages and installation system
- **Key Concepts**: groff formatting, install targets
- **Tag**: `v0.4.1-final`

## Build Instructions

### Multi-file Build
```bash
git checkout multifile-build
make
./bin/client
```

### Static Library Build
```bash
git checkout static-build
make
./bin/client_static
```

### Dynamic Library Build
```bash
git checkout dynamic-build
make
export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH
./bin/client_dynamic
```

### Installation
```bash
sudo make install
client          # Run from anywhere
man mycat       # View documentation
```

## Development Workflow

1. **Create Feature Branch**: `git checkout -b branch-name`
2. **Implement Feature**: Write code following requirements
3. **Build & Test**: Use `make` to build and test functionality
4. **Commit Changes**: `git add . && git commit -m "descriptive message"`
5. **Create Tag**: `git tag -a vX.Y.Z-suffix -m "Version description"`
6. **Push Everything**: `git push origin branch-name --tags`
7. **GitHub Release**: Create release with compiled assets
8. **Merge to Main**: `git checkout main && git merge branch-name`

## Library Analysis Commands

### Static Library Analysis
```bash
# List library contents
ar -t lib/libmyutils.a

# View symbols in library
nm lib/libmyutils.a

# Analyze executable symbols
nm bin/client_static

# Detailed binary analysis
readelf -h bin/client_static
```

### Dynamic Library Analysis
```bash
# Check library dependencies
ldd bin/client_dynamic

# View shared library symbols
nm -D lib/libmyutils.so

# Compare executable sizes
ls -lh bin/client_static bin/client_dynamic
```

## Key Technical Concepts

### Static vs Dynamic Linking

**Static Libraries (.a)**:
- Code copied into final executable
- Larger executable size
- No runtime dependencies
- Created with `ar` command

**Dynamic Libraries (.so)**:
- Code loaded at runtime
- Smaller executable size
- Requires library at runtime
- Created with `-shared` flag

### Position-Independent Code (PIC)
- Required for shared libraries
- Compiled with `-fPIC` flag
- Allows code to run at any memory address

### Library Path Resolution
- `LD_LIBRARY_PATH`: Runtime library search path
- `/usr/lib`, `/lib`: System library directories
- `ldd`: Tool to view library dependencies

## Grading Rubric (100 Total Marks)

| Feature | Component | Marks | Focus Areas |
|---------|-----------|-------|-------------|
| **Scaffolding** | Project Structure | 5 | Directory layout, Git setup |
| **Multi-file** | Code Implementation | 5 | Function correctness |
| | Makefile | 5 | Build automation |
| | Git Workflow | 5 | Branching, commits |
| | Release | 5 | Tags, GitHub release |
| **Static Library** | Makefile | 10 | Library creation, linking |
| | Functionality | 5 | Working executable |
| | Git Workflow | 5 | Branch management |
| | Release | 5 | Tagged release with assets |
| **Dynamic Library** | Makefile | 10 | Shared library creation |
| | Functionality | 5 | Runtime linking |
| | Git Workflow | 5 | Branch management |
| | Release | 5 | Tagged release with assets |
| **Documentation** | Man Pages | 5 | groff formatting |
| | Install Target | 5 | System installation |
| | Git Workflow | 5 | Final branch merge |
| **Final Submission** | Report Quality | 5 | Technical understanding |
| | Git Workflow | 5 | Complete project history |

## Report Questions by Feature

Each feature includes specific technical questions in `REPORT.md`:

**Multi-file Build**:
- Makefile linking rules vs library linking
- Git tags: simple vs annotated
- GitHub releases and binary distribution

**Static Library**:
- Makefile differences for library creation
- Purpose of `ar` and `ranlib` commands
- Symbol analysis with `nm`

**Dynamic Library**:
- Position-Independent Code requirements
- Executable size differences
- LD_LIBRARY_PATH and dynamic loader

## Required Tools & Commands

### Build Tools
- `gcc`: C compiler
- `make`: Build automation
- `ar`: Archive utility for static libraries
- `ranlib`: Library indexing

### Analysis Tools
- `nm`: Symbol table viewer
- `readelf`: ELF file analyzer
- `ldd`: Dynamic library dependencies
- `man`: Documentation viewer

### Version Control
- `git`: Version control system
- GitHub: Remote repository and releases

## Quick Start Checklist

- [ ] Create GitHub repository with exact naming: `ROLL_NO-OS-A01`
- [ ] Clone repository and create project structure
- [ ] Watch any provided instructional videos
- [ ] Start with `multifile-build` branch
- [ ] Implement all library functions
- [ ] Create comprehensive Makefiles
- [ ] Test each build type thoroughly
- [ ] Create tagged releases with assets
- [ ] Complete all REPORT.md questions
- [ ] Push all branches to GitHub

## Submission Guidelines

1. **Repository Naming**: Must be `ROLL_NO-OS-A01` (e.g., `BSDSF23A001-OS-A01`)
2. **All Branches**: Push all feature branches to GitHub for grading
3. **Tagged Releases**: Each version must have GitHub release with binaries
4. **Complete Report**: Answer all technical questions thoroughly
5. **Professional Commits**: Use clear, descriptive commit messages

## Common Issues & Solutions

**Library Not Found**: 
```bash
export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH
```

**Permission Denied on Install**:
```bash
sudo make install
```

**Man Page Not Displaying**:
```bash
man -l man/man3/function.3  # Preview locally
```

---

**Professional Software Development Practices**

This assignment emphasizes not just getting code to work, but understanding the complete software development lifecycle: modular design, build automation, testing, documentation, version control, and distribution. These skills are fundamental to professional C/C++ development and system programming.

---

*Remember: Each feature builds upon the previous one. Complete them in order and maintain clean Git history throughout the project.*