#include<stdio.h>
long c[101][101];
int main()
{
    freopen("prt.in","r",stdin);
    freopen("prt.out","w",stdout);
    long i,j,k,n,ans=0;
    scanf("%d",&n);
    c[1][1]=1;
    for(i=2;i<=n+1;i++)
        for(j=1;j<=i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=19900801;
        }
    for(i=n%2;i<=n;i+=2)
    {
        ans+=c[n+1][i+1]*(n-i)*(n-i-1);
        ans%=19900801;
    }
    printf("%d\n",ans);
    return 0;
}
