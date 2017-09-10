#include "function.h"

int main(int argc, char const *argv[])
{
    // if no flag or file names, exit
    if(argc == 1)
    {
        string extension = check_extension();
        // accept target and compiler name from user
        string targetName = "main";
        cout << "Enter Target Name: ";
        cin >> targetName;
        // Generate makefile using dir contents
        if(extension == ".c")
        {
            string tmp = "gcc";
            generate_using_dir(targetName, tmp);  
        }
        else if(extension == ".cpp")
        {
            string tmp = "g++";
            generate_using_dir(targetName, tmp);
        }
        exit(0);
    }

    else
    {
        string str = argv[1];

        if( str == "-addcmd")
        {
            // Make .Plochie in home foder
            // copy MakeFileGenerator binary in .Plochie
            // Set path of MakeFileGenerator in .bashrc
            copy_to_system();
            exit(0);
        }
        else if( str == "-o")
        {
            // check if input contains different extension files
            string fileNames = "";
            for(int i = 2; i < argc; i++)
            {
                fileNames = fileNames + argv[i] + " ";
            }
            check_extension_files(fileNames);
            // accept target and compiler name from user
            string targetName = "main";
            string compilerName = "";
            cout << "Enter Target Name: ";
            cin >> targetName;
            cout << "Enter Compiler Name: ";
            cin >> compilerName;
            // makefile using specified file
            generate_using_files(targetName, compilerName, argv, argc);
            exit(0);
        }
        else if( str == "-v")
        {
            // Print version and general info of the program
            print_verstion();
            exit(0);
        }
    }

    cout << "Nothing To Do" << endl; 

    return 0;
}