#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Starting parent %d\n",getpid());
    pid_t pid;
    for(i=1;i<argc;i++)
    {
        char *numar = argv[i];
        int nr = atoi(numar);
        pid = fork();

        if(pid<0)
            return errno;
        else if(pid==0)
        {
            printf("%d:%d",nr,nr);
            while(nr!=1)
            {
                if(nr%2==0)
                    nr/=2;
                else
                    nr=nr*3+1;
                printf(" %d",nr);
            }
            printf(".\nDone Parent %d Me %d\n",getppid(),getpid());
            break;
        }

    }
    if(pid>0)
        for(i=0;i<argc;i++)
            wait(NULL);
    return 0;
}
