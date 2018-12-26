/*
ID:xsy19962
TASK:numtri
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long t[1010][1010],f[1001][1001];
int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    long n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            scanf("%d",&t[i][j]);
    f[1][1]=t[1][1];
    for(i=2;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            if(f[i-1][j]>f[i-1][j-1])
                f[i][j]=t[i][j]+f[i-1][j];
            else
                f[i][j]=t[i][j]+f[i-1][j-1];
        }
    k=0;
    for(i=1;i<=n;i++)
        if(k<f[n][i])
            k=f[n][i];
    printf("%d\n",k);
    return 0;
}
