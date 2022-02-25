#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#define MAX_RESOURCES 5
int available_resources = MAX_RESOURCES, i;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;

int decrease_count(int count)
{
    if (available_resources < count)
        return -1;
    else
    {

        available_resources -= count;

    }
    return 0;
}
int increase_count(int count)
{
    pthread_mutex_lock(&mutex1);
    available_resources += count;
    pthread_mutex_unlock(&mutex1);
    return 0;
}
void *thread_routine(void *arg)
{
    int n = *(int *)arg;
    pthread_mutex_lock(&mutex);
    if (decrease_count(n) != -1)
    {
        printf("Got %d resources %d remaing\n", n, available_resources);
        increase_count(n);
        printf("Released %d resources %d remaing\n", n, available_resources);
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_t threads[10];
    int arg[10];
    void *ar;
    for (i = 0; i < 10; i++){
        arg[i]=i;
        //printf("%d ",*ar);
        pthread_create(&threads[i], NULL, thread_routine, &arg[i]);
        }

    for (i = 0; i < 10; i++)
        pthread_join(threads[i], &ar);
    return 0;
}
