#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        cout << "error" << endl;
    }

    if (pid == 0)
    {
        cout << "子进程" << endl;
    }
    else
    {
        cout << "父进程" << endl;
    }
    return 0;
}