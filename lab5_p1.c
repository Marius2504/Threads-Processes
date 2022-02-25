#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
    const char *shm_name = "shared_file";
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    printf("Starting parent %d\n", getpid());
    if (ftruncate(shm_fd, SHM_SIZE) == -1)
    {
        perror(NULL);
        shm_unlink(shm_name);
        return errno;
    }
    char *shm_ptr_rdonly = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    if (shm_ptr_rdonly == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name);
        return errno;
    }
    ///

    int offset = 200;
    pid_t pid;

    for (int i = 1; i < argc; i++)
    {
        char *numar = argv[i];
        int nr = atoi(numar);
        pid = fork();

        if (pid < 0)
            return errno;
        else if (pid == 0)
        {
            char *shm_ptr_child = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
            char *buff = (char *)malloc(1024 * sizeof(char));
            //char *buffnr=(char*)malloc(100*sizeof(char));
            char *text = (char *)malloc(1024 * sizeof(char));

            sprintf(buff, "%d:%d", nr, nr);
            strcpy(text, buff);

            while (nr != 1)
            {
                if (nr % 2 == 0)
                    nr /= 2;
                else
                    nr = nr * 3 + 1;
                //strcat(text," ");
                sprintf(buff, " %d", nr);
                strcat(text, buff);
            }
            printf("\nDone Parent %d Me %d", getppid(), getpid());
            //sprintf(buff,);

            strcat(text, buff);
            strcat(shm_ptr_child + offset * i, text);
            munmap(shm_ptr_child, SHM_SIZE);
            break;
        }
    }
    if (pid > 0)
    {
        for (int i = 0; i < argc; i++)
            wait(NULL);
        //while (wait(NULL) > 0);
        for (int i = 0; i < argc; i++)
        {
            printf("%s\n", shm_ptr_rdonly + i * offset);
        }
        munmap(shm_ptr_rdonly, SHM_SIZE);
        shm_unlink(shm_name);
    }

    return 0;
}
///
/*
    if (pid == 0)
    {
        strcpy(shm_ptr, "hello world");
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("%s\n", shm_ptr);
    }
    shm_unlink(shm_name);
    munmap(shm_ptr, SHM_SIZE);

    return 0;
}*/
