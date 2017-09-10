# MakeFileGenerator
This is source code for Generation of makefile for .c and .cpp files. The makefile has default clean and run blocks.

# Steps to install MakeFileGenerator command in Linux based system
1. Afer compiling the project rename binary to MakeFileGenerator (without any extension).
2. Run the binary from terminal as ./MakeFileGenerator -addcmd (This will add command in your system)

# Usages: 
1. MakeFileGenerator -> generate makefile using current dir contents. (.c or .cpp).
2. MakeFileGenerator -o -> generate makefile using files specified.
    eg. MakeFileGenerator -o main.c add.c sub.c 
3. MakeFileGenerator -v -> show version and author of the program.
