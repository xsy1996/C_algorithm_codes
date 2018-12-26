/*
ID:xsy19962
TASK:money
LANG:C++
*/
#include<stdio.h>
long long n,m,a[101],f[10001];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    long long i,j,k;
    scanf("%I64d%I64d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    f[0]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<=m-a[i];j++)
            f[j+a[i]]+=f[j];
    printf("%I64d\n",f[m]);
    return 0;    
}
