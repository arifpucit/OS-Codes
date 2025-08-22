# OS Assignment 02: Re-engineering the ls Utility

## 📋 Overview

This assignment is a comprehensive, hands-on project that guides students through the step-by-step implementation of a Unix `ls` command clone. Starting from a basic C implementation, students will incrementally add advanced features, mirroring the capabilities of the standard `ls` command in a GNU/Linux environment.

## 🎯 Learning Objectives

By completing this assignment, students will demonstrate proficiency in:

- **System Call Programming**: Using essential system calls like `stat()`, `lstat()`, `readdir()`, `getpwuid()`, and `getgrgid()`
- **Data Structures & Algorithms**: Implementing dynamic arrays and using `qsort()` for file system data management
- **Command-Line Argument Parsing**: Handling options like `-l`, `-x`, and `-R`
- **Output Formatting**: Creating professional, column-aligned, and colorized output
- **Build Automation**: Using Makefiles for C application compilation
- **Professional Git Workflow**: Using feature branches and creating versioned releases

## 🏗️ Project Structure

Your project repository should follow this structure:

```
ROLL_NO-OS-A02/
├── src/
│   └── ls-v1.0.0.c
├── bin/
├── obj/
├── man/
├── Makefile
└── REPORT.md
```

## 🚀 Features Implementation Timeline

### Feature 1: Project Setup (5 marks)
- **Branch**: `main`
- **Deliverable**: Initial project structure and build system
- **Key Concepts**: Git/GitHub, Project Scaffolding, Makefile

### Feature 2: Long Listing Format - v1.1.0 (15 marks)
- **Branch**: `feature-long-listing-v1.1.0`
- **Flag**: `-l`
- **Key Concepts**: File metadata, `stat()`, user/group resolution, time formatting

### Feature 3: Column Display - v1.2.0 (15 marks)
- **Branch**: `feature-column-display-v1.2.0`
- **Behavior**: Default "down then across" column layout
- **Key Concepts**: Terminal I/O (`ioctl`), dynamic memory, output formatting

### Feature 4: Horizontal Display - v1.3.0 (15 marks)
- **Branch**: `feature-horizontal-display-v1.3.0`
- **Flag**: `-x`
- **Behavior**: Left-to-right column layout
- **Key Concepts**: State management, alternative display modes

### Feature 5: Alphabetical Sort - v1.4.0 (15 marks)
- **Branch**: `feature-alphabetical-sort-v1.4.0`
- **Behavior**: All outputs sorted alphabetically
- **Key Concepts**: `qsort()`, function pointers, string comparison

### Feature 6: Colorized Output - v1.5.0 (10 marks)
- **Branch**: `feature-colorized-output-v1.5.0`
- **Behavior**: Color-coded file types
- **Key Concepts**: ANSI escape codes, file type detection

### Feature 7: Recursive Listing - v1.6.0 (20 marks)
- **Branch**: `feature-recursive-listing-v1.6.0`
- **Flag**: `-R`
- **Behavior**: Recursive directory traversal
- **Key Concepts**: Recursion, path construction, directory traversal

## 🔧 Build Instructions

```bash
# Clone your repository
git clone https://github.com/yourusername/ROLL_NO-OS-A02.git
cd ROLL_NO-OS-A02

# Build the project
make

# Run the ls utility
./bin/ls [options] [directory]
```

## 📝 Usage Examples

```bash
# Basic listing
./bin/ls

# Long listing format
./bin/ls -l

# Horizontal layout
./bin/ls -x

# Recursive listing
./bin/ls -R

# Long format with recursive listing
./bin/ls -lR
```

## 🎨 Color Scheme

The colorized output follows these conventions:
- **Blue**: Directories
- **Green**: Executable files
- **Red**: Archives (.tar, .gz, .zip)
- **Pink**: Symbolic links
- **Reverse Video**: Special files (devices, sockets)

## 📋 Development Workflow

1. **Create Feature Branch**: `git checkout -b feature-name-vX.Y.Z`
2. **Implement Feature**: Write code and test functionality
3. **Commit Changes**: `git add . && git commit -m "feat: descriptive message"`
4. **Merge to Main**: `git checkout main && git merge feature-name-vX.Y.Z`
5. **Tag Release**: `git tag -a vX.Y.Z -m "Version X.Y.Z: Feature Description"`
6. **Push to GitHub**: `git push origin main --tags`
7. **Create GitHub Release**: Upload binary and publish release

## 📊 Grading Rubric (100 Total Marks)

| Feature | Marks | Focus Areas |
|---------|-------|-------------|
| Project Setup | 5 | Repository structure, build system |
| Long Listing (-l) | 15 | System calls, metadata formatting |
| Column Display | 15 | Terminal handling, memory management |
| Horizontal Display (-x) | 15 | State management, option parsing |
| Alphabetical Sort | 15 | Sorting algorithms, data structures |
| Colorized Output | 10 | ANSI codes, file type detection |
| Recursive Listing (-R) | 20 | Recursion, path handling |
| Final Submission & Viva | 5 | Report quality, code defense |

## 📚 Required Resources

- **Starter Code**: Available in this repository as `ls-v1.0.0`
- **Helper Examples**: Repository with focused code examples for complex features
- **Video Tutorial**: "Making of ls" - mandatory viewing before starting

## 🔍 System Calls Reference

Key system calls you'll be using:
- `opendir()`, `readdir()`, `closedir()` - Directory operations
- `stat()`, `lstat()` - File metadata
- `getpwuid()`, `getgrgid()` - User/group name resolution
- `ioctl()` with `TIOCGWINSZ` - Terminal size detection

## 📋 Report Questions

Each feature includes specific questions to be answered in `REPORT.md`. These questions test your understanding of:
- System call differences and usage
- Bitwise operations on file permissions
- Algorithmic complexity comparisons
- Implementation design decisions

## ⚡ Quick Start Checklist

- [ ] Fork/clone the starter repository
- [ ] Set up proper project structure
- [ ] Verify initial build works
- [ ] Watch the required "Making of ls" video
- [ ] Create your first feature branch
- [ ] Begin implementing features incrementally

## 🤝 Submission Guidelines

1. **Repository Naming**: Must be `ROLL_NO-OS-A02` (e.g., `BSDSF23A001-OS-A02`)
2. **All Branches**: Push all feature branches to GitHub for grading
3. **Complete Report**: Answer all questions in `REPORT.md`
4. **Tagged Releases**: Each version must have corresponding GitHub release with binary
5. **Viva Preparation**: Be ready to explain and defend your implementation choices

## 📞 Support

For technical questions and clarifications, refer to:
- Course discussion forums
- Office hours
- Helper code examples in the resource repository

---

**Happy Coding!** 🚀

*Remember: This is not just about getting the code to work—it's about understanding systems programming, following professional development practices, and building robust, maintainable software.*