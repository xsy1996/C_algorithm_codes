#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long a[10001],m,n;
char s[1001];
void add()
{
    long f=0,i,b[10001];
    for(i=1;i<=n+1;i++)
        b[i]=a[i];
    for(i=1;i<=n;i++)
    {
        b[i]+=a[n-i+1];
        if(b[i]>=m)
        {
            b[i]-=m;
            b[i+1]++;
            if(i==n)
                f=1;
        }
    }
    n+=f;
    for(i=1;i<=n;i++)
        a[i]=b[i];
    return;
} 
long check()
{
    long i;
    for(i=1;i<=n;i++)
        if(a[i]!=a[n-i+1])
            return 0;
    return 1;
}
int main()
{
    long i,j,k,flag=0;
    scanf("%d",&m);
    getchar();
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
            a[i]=s[i]-'0';
        else if(s[i]>='A' && s[i]<='Z')
            a[i]=s[i]+10-'A';
        else if(s[i]>='a' && s[i]<='z')
            a[i]=s[i]+10-'a';
    }
    if(check())
    {
        printf("0\n");
        flag=1;
    }
    else
        for(i=1;i<=30;i++)
        {
            add();
            if(check())
            {
                flag=1;
                printf("%d\n",i);
                break;
            }
        }
    if(flag==0)
        printf("Impossible!\n");
    system("pause");
    return 0;
}