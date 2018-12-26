#include<stdio.h>
#include<stdlib.h>
long a[1001],t=1,b[1001];
void add()
{
    long i,j,k;
    for(i=1;i<=t;i++)
        b[i]=a[i];
    for(i=1;i<t;i++)
    {
        a[i]+=b[i];
        if(a[i]>=10)
        {
            a[i]-=10;
            a[i+1]++;
        }
    }
    a[t]+=b[t];
    if(a[t]>=10)
    {
        a[t]-=10;
        a[t+1]=1;
        t++;
    }
    return;
}
int main()
{
    long i,j,k,n;
    scanf("%d",&n);
    a[1]=1;
    for(i=1;i<=n;i++)
        add();
    a[1]--;
    add();
    for(i=t;i>=1;i--)
        printf("%d",a[i]);
    printf("\n");
    system("pause");
    return 0;
}
