#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    char *msg="Hello World!";
    write(STDOUT_FILENO,msg,strlen(msg));
    return 0;
}
