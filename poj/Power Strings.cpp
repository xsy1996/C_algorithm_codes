#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000001];
long len,next[1000001];
int main()
{   
    long i,j,k;
    scanf("%s",s+1);
    while(s[1]!='.')
    {
        len=strlen(s+1);
        next[1]=0;i=1;k=0;
        while(i<=len)
        {
            if(k==0 || s[i]==s[k])
            {
                i++;
                k++;
                next[i]=k;
            }
            else
                k=next[k];
        }
        if(len%(len+1-next[len+1])==0)
            printf("%ld\n",len/(len+1-next[len+1]));
        else
            printf("1\n");
        getchar();
        scanf("%s",s+1);
    }
    system("pause");
    return 0;
}
