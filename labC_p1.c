#include <stdio.h>
#include <stdlib.h>
/*
Se  citesc    de la  tastură   un număr    natural    n ce  reprezintă dimensiunea unei   matrice pătratice ṣi elementele unei   matrice pătratice.
Folosind pointeri, să  se  afiṣeze elementele matricei,elementul de la  intersecţia diagonalelor (pentru n impar), iar  apoi  elementele de pe cele   două diagonale.
5
1 2 3 5 7
4 5 6 10 11
7 8 9 22 44
7 8 10 99 55
32 104 22 93 80

*/


int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    int* arr =(int*)malloc(n*n*sizeof(int));

    for(int i=0; i<n*n; i++)
        scanf("%d",arr+i);
    printf("Afisare: \n");
    for(int i=0; i<n*n; i++)
    {
        printf("%d ",*(arr+i));
        if((i+1)%n==0 && i!=0)printf("\n");
    }
    printf("Mijloc: \n");
    if(n%2!=0)printf("%d",*(arr+n*n/2 ));
    printf("\n");
    printf("Diagonala principala: ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i*n+i));
    printf("\nDiagonala secundara: ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+(i+1)*n-i-1));

    free(arr);
    return 0;
}
