#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Implementati o functie    care  numara aparitiile unui cuvant    intr-un   text  dat.int  count_occurrences(const char*   text,const char* word)

*/
int count_occurrences(const char* text,const char* word);

int main()
{
    FILE* ptr = fopen("text.txt","r");
    const char *text=(char*)malloc(100*sizeof(char));
    int sum=0;
    if (ptr==NULL)
    {
        printf("Nu exista");
        return 0;
    }
    else
    {
        printf("%s","Cuvant:");
        const char *s=(char*)malloc(100*sizeof(char));
        gets(s);


        while(fgets(text, 100, ptr) != NULL)
        {
            sum+=count_occurrences(text,s);
        }
        free(s);
    }
    printf("%d",sum);

    free(text);
    fclose(ptr);

    return 0;
}
int count_occurrences(const char* text,const char* word)
{
    int i,j,n,m;
    n=strlen(text);
    m=strlen(word);

    int sum=0,ok;
    for(i=0; i<n; i++)
    {
        ok=0;
        if((i==0 && *(text+i)==*(word))||(*(text+i)==*(word)&&*(text+i-1)==' '))
        {
            ok=1;
            for(j=0; j<m; j++)
                if(*(text+i+j)==NULL || *(text+i+j)!=*(word+j))ok=0;

            if(ok==1 && *(text+i+m)!=' ')ok==0;
        }
        sum+=ok;
    }
    return sum;
}
