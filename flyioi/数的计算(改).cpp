#include<stdio.h>
#include<stdlib.h>
long f[1001];
void find(long x)
{
    long i;
    if(f[x]!=0)
        return;
    else
    {
        f[x]=1;
        for(i=1;i<=x/2;i++)
        {
            find(i);
            f[x]+=f[i];
        }
    }
    return;
}
int main()
{
    long i,j,k,n;
    scanf("%d",&n);
    find(n);
    printf("%d\n",f[n]);
    system("pause");
    return 0;
}