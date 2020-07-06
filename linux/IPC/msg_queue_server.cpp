#include <iostream>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

using namespace std;

//主要用于两个不相关的进程

int main()
{
    //创建key
    int id = msgget(key_t(12345678), IPC_CREAT | 0666);
    if (id == -1)
    {
        perror("msgget");
        return 0;
    }
    while (1)
    {
        char msg[512];
        memset(msg, 0, sizeof(msg));
        strcpy(msg, "hello world");
        cout << msg << endl;
        if (msgsnd(id, (void *)&msg, 512, 0) < 0)
        {
            cout << "error" << endl;
            return 0;
        }

        if (strcmp(msg, "QUIT") == 0)
        {
            break;
        }
    }

    if (msgctl(id, IPC_RMID, NULL) < 0)
    {
        cout << "del msg error" << endl;
        return 0;
    }
    return 0;
}