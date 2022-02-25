//Exercitiul 1 lab 7

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *thread_routine(void *arg)
{
    char *cuv = (char *)malloc(sizeof(char));
    cuv = (char *)arg;
    int n = strlen(cuv);
    char aux;
    for (int i = 0; i < n / 2; i++)
    {
        aux=cuv[i];
        cuv[i]=cuv[n-i-1];
        cuv[n-i-1]=aux;
    }
    return (void*)cuv;
}

int main(int argc, char *argv[])
{
    char *cuv = argv[1];
    void *cuv2;

    pthread_t thread;
    pthread_create(&thread, NULL, thread_routine, cuv);
    pthread_join(thread, &cuv2);

    printf("%s ", (char *)cuv2);
}