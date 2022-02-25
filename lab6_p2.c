//Exercitiul 2 lab 6

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int a[100][100],b[100][100],c[100][100];
int n1, m1, n2, m2;
struct prom
{
    int x;
    int y;
};
typedef struct prom prom;

void *thread_routine(void *arg)
{
    prom *p = (prom*)arg;
    for(int i=0;i<m1;i++)
        c[p->x][p->y]+=a[p->x][i]*b[i][p->y];
}

int main(int argc, char *argv[])
{
    int i,j;
    scanf("%d",&n1);
    scanf("%d",&m1);
    for(i=0; i<n1; i++)
        for(j=0; j<m1; j++)
            scanf("%d",&a[i][j]);

    scanf("%d",&n2);
    scanf("%d",&m2);
    for(i=0; i<n2; i++)
        for(j=0; j<m2; j++)
            scanf("%d",&b[i][j]);

    if (m1!=n2)
        printf("Matricele nu se pot inmulti\n");
    else
    {
        pthread_t thread[m1*n2];
        int nr=0;
        prom rez[m1*n2];
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                rez[nr].x=i;
                rez[nr].y=j;
                int ok;
                ok = pthread_create(&thread[nr],NULL,thread_routine,(void*)&rez[nr]);
                if(ok!=0)
                    return errno;
                nr++;
            }
        }
        for (i = 0; i < m1*n2; i++)
        {
            pthread_join(thread[i],NULL);
        }
        for(int i=0; i<m1; i++)
        {
            for(int j=0; j<n2; j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }
}
/*

3 4
1 2 3 4
4 5 6 7
8 9 0 1
4 2
1 2
3 4
5 6
0 9


*/
