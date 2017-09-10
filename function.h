#ifndef _FUNCTION_H
#define _FUNCTION_H
	
// check if system is unix or linux
// add required header using predefined MACROS
#ifdef __linux__
    #include <bits/stdc++.h>
#elif __unix__
    #include <bits/stdc++.h>
#endif
// header for all operating systems
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
// supported compilers
#define GCC "gcc"
#define GPP "g++"
// metadata
#define VERSION 1.4

// define colors for terminal errors and success messages
#define RED_LINE(str) ("\033[1;31m" str "\033[0m")

#define GREEN_LINE(str) ("\033[1;32m" str "\033[0m")
#define GREEN_LINE_S "\033[1;32m"
#define GREEN_LINE_E "\033[0m"

using namespace std;


void generate_makefile(string& targetName, string& compilerName, string& dirList);
void copy_to_system();
void print_verstion();
void generate_using_files(string& target, string& compiler, const char* files[], int fileCount);
void generate_using_dir(string& target, string& compiler);
string check_extension();
void check_extension_files(string& fileNames);

#endif