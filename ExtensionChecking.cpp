#include "function.h"

string check_extension()
{
    // check extension for each file
    // store extension of first file and check it with other files
    DIR* mydir;
    struct dirent* myfile;
    bool fileExtensionStored = false;
    mydir = opendir(".");
    string storedExtension = "";

    while((myfile = readdir(mydir)) != NULL)
    {
        string str = myfile->d_name;
         // seperate filename from extension
        size_t lastIndex = str.find_last_of(".");
        if(lastIndex < 256)
        {
            string rawFileName = str.substr(0, lastIndex);
            string fileExtension = str.substr(lastIndex);

            if( (fileExtension == ".c" || fileExtension == ".cpp") && fileExtensionStored == false)
            {
                storedExtension = fileExtension;
                fileExtensionStored = true;
            }
            else if((fileExtension == ".c" || fileExtension == ".cpp") && fileExtensionStored == true)
            {
                if(storedExtension != fileExtension)
                {
                    cout << RED_LINE("This Directory Contains Multiple Extension Files") << endl;
                    cout << RED_LINE("Use -o Flag to Add Files Manually") << endl;
                    exit(10);
                }
            }
        }
    }
    closedir(mydir);

    return storedExtension;
}

void check_extension_files(string& fileNames)
{
    // count of files sepated using space char
    int fileCount = count(fileNames.begin(), fileNames.end(), ' ');

    string tmp = "";
    string storedExtension = "";

    for(int i = 0; i < fileCount; i++)
    {
        if( i == 0)
        {
            // create src string using passed parameters
            size_t index = fileNames.find_first_of(" ");
            string fileName = fileNames.substr(0, index);
            tmp = fileNames.substr(index+1);

            string storedExtension = "";

            // seperate filename from extension
            size_t lastIndex = fileName.find_last_of(".");
            string rawFileName = fileName.substr(0, lastIndex);
            string fileExtension = fileName.substr(lastIndex);

            storedExtension = fileExtension;
        }
        else
        {
            // create src string using passed parameters
            size_t index = tmp.find_first_of(" ");
            string fileName = tmp.substr(0, index);
            tmp = fileNames.substr(index+1);

            string storedExtension = "";

            // seperate filename from extension
            size_t lastIndex = fileName.find_last_of(".");
            string rawFileName = fileName.substr(0, lastIndex);
            string fileExtension = fileName.substr(lastIndex);

            if(storedExtension != fileExtension)
            {
                cout << RED_LINE("Different Extension Files") << endl;
                cout << RED_LINE("Use Same Extension Files For make Generation") << endl;
                exit(20);
            }
        }
    }
}