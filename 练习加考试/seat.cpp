#include<stdio.h>
long f[3001][3001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long i,j,k,n,m,ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++)
        f[i][0]=1;
    for(i=0;i<=m;i++)
        f[0][i]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1];
            f[i][j]%=19900801;
        }
    printf("%d\n",f[n][m]);
    return 0;
}
