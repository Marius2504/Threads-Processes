#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    struct stat stat1;
    char* file1=argv[1];
    char* file2=argv[2];

    if(stat(file1,&stat1)==-1)
    {
        perror("");
        return errno;
    }
    unsigned long st= stat1.st_size;
    int fd=open(file1,O_RDONLY);
    char* buf =(char*)malloc(st*sizeof(char));

    read(fd,buf,st);
    int fd1=open(file2,O_WRONLY);

    if(stat(file2,&stat1)==-1)
    {
        perror("");
        return errno;
    }
    write(file2,buf,st);
    return 0;
}
