#include "function.h"

void generate_makefile(string& targetName, string& compilerName, string& dirList)
{
    // comment in the makefile
    string makeFile = "# Generated using MakeFileGenerator (GIT: Plochie)\n\n";
    // count of files sepated using space char
    int fileCount = count(dirList.begin(), dirList.end(), ' ');

    // create src string using passed parameters
    size_t index = dirList.find_first_of(" ");
    string rawFileName = dirList.substr(0, index);
    string tmp = dirList.substr(index+1);

    // SRC variable in makefile
    string srcString = "SRC=";
    for(int i = 0; i < fileCount; i++)
    {
        // append filename in srcString
        // DO NOT APPEND DIRECTLY THE USER DATA
        // as it may comtain filename without extension
        if(compilerName == GCC)
            srcString = srcString + rawFileName + ".c ";
        else
            srcString = srcString + rawFileName + ".cpp ";
        // seperate filename from extension
        index = tmp.find_first_of(" ");
        rawFileName = tmp.substr(0, index);
        tmp = tmp.substr(index+1);
    }

    // create obj string using passed parameters
    index = dirList.find_first_of(" ");
    rawFileName = dirList.substr(0, index);
    tmp = dirList.substr(index+1);

    // OBJ variable in makefile
    string objString = "OBJ=";
    for(int i = 0; i < fileCount; i++)
    {
        // append filename in srcString
        // DO NOT APPEND DIRECTLY THE USER DATA
        // as it may comtain filename without extension
        objString = objString + "obj/" + rawFileName + ".o ";
        // seperate filename from extension
        index = tmp.find_first_of(" ");
        rawFileName = tmp.substr(0, index);
        tmp = tmp.substr(index+1);
    }

    // append target variables, src variables, obj variables
    // compiler variable and cflag variables
    makeFile = makeFile + "TARGET=binary/" + targetName + ".out\n";
    makeFile = makeFile + srcString + "\n";
    makeFile = makeFile + objString + "\n";
    makeFile = makeFile + "CC=" + compilerName + "\n";
    makeFile = makeFile + "CFLAGS=-Wall -ggdb3\n";

    // add target copiler command line
    makeFile = makeFile + "\n$(TARGET): $(OBJ)\n\tmkdir -p binary && $(CC) -o $(TARGET) $(OBJ)\n\n";


    index = dirList.find_first_of(" ");
    rawFileName = dirList.substr(0, index);
    tmp = dirList.substr(index+1);

    // create separate block for each .o file
    for(int i = 0; i < fileCount; i++)
    {
        // DO NOT DIRECTLY USE THE USER DATA
        // as it may comtain filename without extension
        // create .o file and move it in obj/ dir
        if(i == 0)
        {
            // if compiler is gcc
            if(compilerName == GCC)
            {
                makeFile = makeFile + "obj/" + rawFileName + ".o: " + rawFileName + ".c\n";
                makeFile = makeFile + "\tmkdir -p obj/ && $(CC) -c $(CFLAGS) " + rawFileName + ".c && mv " + rawFileName + ".o obj/" + "\n\n";
            }
            // if compiler is g++
            else
            {
                makeFile = makeFile + "obj/" + rawFileName + ".o: " + rawFileName + ".cpp\n";
                makeFile = makeFile + "\tmkdir -p obj/ && $(CC) -c $(CFLAGS) " + rawFileName + ".cpp && mv " + rawFileName + ".o obj/" + "\n\n";
            }
        }
        else
        {
            // if compiler is gcc
            if(compilerName == GCC)
            {
                makeFile = makeFile + "obj/" + rawFileName + ".o: " + rawFileName + ".c\n";
                makeFile = makeFile + "\t$(CC) -c $(CFLAGS) " + rawFileName + ".c && mv " + rawFileName + ".o obj/" + "\n\n";
            }
            // if compiler is g++
            else
            {
                makeFile = makeFile + "obj/" + rawFileName + ".o: " + rawFileName + ".cpp\n";
                makeFile = makeFile + "\t$(CC) -c $(CFLAGS) " + rawFileName + ".cpp && mv " + rawFileName + ".o obj/" + "\n\n";
            }
            
        }
        // seperate filename from extension
        index = tmp.find_first_of(" ");
        rawFileName = tmp.substr(0, index);
        tmp = tmp.substr(index+1);
    }

    // run and clean commands
    makeFile = makeFile + "run:\n\t./$(TARGET)\n";
    makeFile = makeFile + "\nclean:\n\trm -rf obj/ binary/";

    const char* ptr = makeFile.c_str();

    if(fileCount > 0)
    {
        FILE *fp = fopen("makefile", "w");
        fwrite(ptr, 1, makeFile.length(), fp);
        fclose(fp);
    }   
}