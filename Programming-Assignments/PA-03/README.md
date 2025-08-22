# PUFCIT's custom UNIX Shell

A simple command-line interpreter (shell) built in C for an Operating Systems course.

## Quick Start

### Build the Shell

To compile the project, run the `make` command:
```bash
make
```

### Run the Shell

The compiled executable will be located in the `bin/` directory.
```bash
./bin/psh
```

### Clean the Project

To remove all compiled object files and the final executable:
```bash
make clean
```

## Directory Structure

*   `/src`: All C source code files (`.c`).
*   `/include`: All header files (`.h`).
*   `/bin`: Contains the final compiled executable (`psh`).
*   `/obj`: Contains intermediate object files (`.o`) created during compilation.
*   `Makefile`: The build script for the project.