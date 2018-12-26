#include<stdio.h>
long long t,x[7001],y[7001],n=0,m=0,a[101],b[101],f[1001][1001],dp[1001][1001];
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long long c(long long k)
{
    return k*(k-1)*(k-2)/6;
}
long long ans(long i)
{
    return c((x[i]+1)*(y[i]+1))-(x[i]+1)*c(y[i]+1)-(y[i]+1)*c(x[i]+1)-2*dp[x[i]][y[i]];
}
int main()
{
    freopen("Count.in","r",stdin);
    freopen("Count.out","w",stdout);
    long long i,j,k;
    scanf("%I64d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%I64d%I64d",&x[i],&y[i]);
        if(x[i]>n)
            n=x[i];
        if(y[i]>m)
            m=y[i];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+gcd(i,j)-1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+f[i][j];
    for(i=1;i<=t;i++)
        printf("%I64d\n",ans(i));
    return 0;
}
