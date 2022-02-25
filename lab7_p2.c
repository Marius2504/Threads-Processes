#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREAD 5

pthread_mutex_t mutex;
sem_t sem;
int ct=0;
void *thread_routine(void *arg)
{

    int index = *(int *)arg;
    printf("%d reached the barrier\n",index);
    pthread_mutex_lock(&mutex);
    ct++;
    pthread_mutex_unlock(&mutex);
    if(ct==5)
    {
        for(int i=0;i<5;i++)
            sem_post(&sem);
    }
    sem_wait(&sem);
    printf("%d passed the barrier\n",index);
}

int main()
{
    pthread_t thread[NTHREAD];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem,0,0);
    int arg[NTHREAD];

    for (int i = 0; i < NTHREAD; i++)
    {
        arg[i] = i;
        pthread_create(&thread[i], NULL, thread_routine, &arg[i]);
    }
    for (int i = 0; i < NTHREAD; i++)
        pthread_join(thread[i], NULL);
}
