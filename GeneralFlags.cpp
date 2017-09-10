#include "function.h"

void copy_to_system()
{
    system("mkdir -p ~/.Plochie");
    system("cp MakeFileGenerator ~/.Plochie");

    system("echo \"export PATH=$PATH:~/.Plochie/\" >> ~/.bashrc");
}

void print_verstion()
{
    cout << "AUTHOR: Paresh Lomate" << endl;
    cout << "GIT: Plochie" << endl;
    cout << "VERSION: 1.1" << endl;
}