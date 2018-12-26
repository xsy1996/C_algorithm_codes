#include<stdio.h>
#include<string.h>
long v[100],s[1001];
char a[5001];
int main()
{
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    long i,j,k,n,min,max;
    scanf("%s",a+1);
    n=strlen(a+1);
    for(i=2;i<=200;i++)
        if(s[i]==0)
            for(j=i*2;j<=200;j+=i)
                s[j]=1;
    s[0]=1;
    s[1]=1;
    for(i=1;i<=n;i++)
    {
        if(a[i]<'a')
            a[i]+='a'-'A';
        v[a[i]-'a'+1]++;
    }
    min=2147483600;
    max=-1;
    for(i=1;i<=50;i++)
    {
        if(v[i]<min && v[i]!=0)
            min=v[i];
        if(v[i]>max)
            max=v[i];
    }
   /* for(i=1;i<=100;i++)
        if(s[i]==0)
            printf("%d ",i);
    printf("\n");*/
    if(s[max-min]==0)
        printf("Lucky Word\n%d\n",max-min);
    else
        printf("No Answer\n0\n");
    return 0;
}
