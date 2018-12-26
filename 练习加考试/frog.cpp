#include<stdio.h>
#include<math.h>
double f[1001][1001][2],x[1001],y[1001];
double dis(long i,long j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double min(double x,double y)
{
    if(x<y)
        return x;
    else
        return y;
}
int main()
{
    freopen("frog.in","r",stdin);
    freopen("frog.out","w",stdout);
    long i,j,n;
    double k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    for(j=1;j<=n;j++)
        for(i=1;i<=n-j+1;i++)
        {
            f[i][j][0]=min(f[i+1][j-1][0]+dis(i+1,i),f[i+1][j-1][1]+dis(i,i+j-1));
            f[i][j][1]=min(f[i][j-1][1]+dis(i+j-1,i+j-2),f[i][j-1][0]+dis(i,i+j-1));
        }    
    k=f[1][n][0];
    if(f[1][n][1]<k)
        k=f[1][n][1];
    printf("%0.3lf\n",k);
    return 0;
}
