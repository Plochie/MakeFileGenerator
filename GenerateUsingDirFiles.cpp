#include "function.h"

void generate_using_dir(string& target, string& compiler)
{
    DIR* mydir;
    struct dirent* myfile;
    string listDir = "";

    mydir = opendir(".");

    while((myfile = readdir(mydir)) != NULL)
    {
        string str = myfile->d_name;

         // seperate filename from extension
        size_t lastIndex = str.find_last_of(".");
        if(lastIndex < 256)
        {
            string rawFileName = str.substr(0, lastIndex);
            string fileExtension = str.substr(lastIndex);
            if(fileExtension == ".c" || fileExtension == ".cpp")
                listDir = listDir + rawFileName + " ";
        }
    }

    closedir(mydir);

    generate_makefile(target, compiler, listDir);
}

void generate_using_files(string& target, string& compiler, const char* files[], int fileCount)
{
    string listDir = "";

    for(int i = 2; i < fileCount; i++)
    {
        string str = files[i];

         // seperate filename from extension
        size_t lastIndex = str.find_last_of(".");
        if(lastIndex < 256)
        {
            string rawFileName = str.substr(0, lastIndex);
            string fileExtension = str.substr(lastIndex);
            if(fileExtension == ".c" || fileExtension == ".cpp")
                listDir = listDir + rawFileName + " ";
        }
    }

    generate_makefile(target, compiler, listDir);
}