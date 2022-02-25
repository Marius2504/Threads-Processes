#include <stdio.h>
#include <stdlib.h>
/*
Folosind functia    count_occurrences implementati o alta  functie    ce  citeste    doua cuvinte si inlocuieste intr-un   text  introdus de la  tastatura toate
aparitiile primului cuvant    prin   cel  de-aldoilea

*/

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
void change()
{
    const char* cuv1=(char*)malloc(50*sizeof(char));
    const char* cuv2=(char*)malloc(50*sizeof(char));
    char *text=(char*)malloc(100*sizeof(char));
    gets(cuv1);
    gets(cuv2);
    gets(text);

    int n1=strlen(cuv1);
    int n2=strlen(cuv2);
    int n3=strlen(text);

    int i,j,k,ok,p;
    while(count_occurrences(text,cuv1)!=0)
    {
        for(i=0; i<n3; i++)
        {
            ok=0;
            if((i==0 && *(text+i)==*(cuv1))||(*(text+i)==*(cuv1)&&*(text+i-1)==' '))
            {
                ok=1;
                for(j=0; j<n1; j++)
                    if(*(text+i+j)==NULL || *(text+i+j)!=*(cuv1+j))ok=0;

               // if(ok==1 && *(text+i+m)!=' ')ok==0;
            }
            if(ok==1)
            {
                for(j=0;j<n1-1;j++)
                {
                    for(k=i;k<n3-1;k++)
                    {
                        *(text+k)=*(text+k+1);
                    }
                    n3--;
                }
                ///---------
                *(text+n3)=NULL;


                int o=1;
               // int ct=n3-i-1;
                *(text+i)=*(cuv2);
               // printf(text);
               // printf("\n");

                for(j=0;j<n2-1;j++)
                {

                    for(k=n3;k>i+o;k--)
                    {
                        *(text+k)=*(text+k-1);
                    }

                    *(text+i+o)=*(cuv2+o);
                    o++;
                    n3++;
                  //  printf("%s\n",text);
                }
                *(text+n3)=NULL;

            }
        }

    }
    printf(text);
}
int main()
{
    change();
    return 0;
}
/*
are
costel
ana are mere

*/
