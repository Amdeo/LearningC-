#include <iostream>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

using namespace std;

//主要用于两个不相关的进程

int main()
{
    int id = msgget(key_t(12345678), IPC_CREAT | 0666);
    while (1)
    {
        char msg[512];
        memset(msg, 0, sizeof(msg));

        if (msgrcv(id, (void *)&msg, 512, 1, 0) < 0)
        {
            cout << "error" << endl;
        }

        cout << "msg: " << msg << endl;

        if (strcmp(msg, "QUIT") == 0)
        {
            break;
        }
    }

    return 0;
}