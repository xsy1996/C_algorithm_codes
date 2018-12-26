#include<stdio.h>
long f[1001][1001],s[1001][1001],a[1001],d[1001];
int main()
{
    freopen("Traffic.in","r",stdin);
    freopen("Traffic.out","w",stdout);
    long n,i,j,k,min=2147483640; 
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        d[i]=d[i-1]+a[i];
        s[i][i]=i;
    }
    for(j=1;j<=n-1;j++)
        for(i=1;i<=n-j;i++)
            for(k=s[i][i+j-1];k<=s[i+1][i+j];k++)
            {
                if(f[i][i+j]==0 || (f[i][i+j]>f[i][k]+f[k+1][i+j]+d[i+j]-d[i-1]))
                {
                    f[i][i+j]=f[i][k]+f[k+1][i+j]+d[i+j]-d[i-1];
                    s[i][i+j]=k;
                }
                if(f[i][i+j]==f[i][k]+f[k+1][i+j]+d[i+j]-d[i-1] && k>s[i][i+j])
                    s[i][i+j]=k;
            }
    printf("%d\n",f[1][n]);
    return 0;
}
