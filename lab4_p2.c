#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char* argv[])
{
    char *nr=argv[1];
    int n=strlen(nr),i=0,numar=0;

    while(i<n)
    {
        numar = numar*10 + (int)nr[i] - (int)'0';
        i++;
    }
    pid_t pid = fork();

    if(pid == 0)
    {
        while (numar != 1)
        {
            printf("%d ",numar);
            if(numar%2==0)
                numar/=2;
            else
                numar=numar*3 + 1;
        }
        printf("%d\n",1);
    }
    return 0;
}
