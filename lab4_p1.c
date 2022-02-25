#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        const char* path ="/usr/bin/ls";
        char* argv[]={"ls",NULL};
        execve(path,argv, NULL);

    }else if(pid > 0)
    {
        printf("My PID=%d, Child PID=%d\n",getpid(),pid);
        wait(NULL);
        printf("Child %d process finished\n", pid);
    }

    return 0;
}
  /*
    const char* path ="/usr/bin/pwd";
    char* argv[]={"pwd",NULL};
    execve(path,argv, NULL);
    //printf("hellfdfo");*/
