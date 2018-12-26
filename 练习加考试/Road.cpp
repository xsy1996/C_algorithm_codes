#include<stdio.h>
#include<math.h>
double x[1001],y[1001],cost[1001][1001],dis[1001],v[1001],min;
double d(long i,long j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j])*1.0);
}
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    long i,j,k,n,q,w,s;
    double a,b;
    scanf("%lf%lf",&b,&a);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    while(1)
    {
        scanf("%d%d",&q,&w);
        if(q==0 && w==0)
            break;
        cost[q][w]=1;
        cost[w][q]=1;
    }
    scanf("%lf%lf",&x[0],&y[0]);
    n++;
    scanf("%lf%lf",&x[n],&y[n]);
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        {
            if(cost[i][j])
                cost[i][j]=d(i,j)*a;
            else
                cost[i][j]=d(i,j)*b;
        }
    for(i=1;i<=n;i++)
        dis[i]=2147483000;
    dis[0]=0;
    while(1)
    {
        min=2147480000;
        for(j=0;j<=n;j++)
            if(v[j]==0 && dis[j]<min)
            {
                min=dis[j];
                s=j;
            }
        if(min==2147480000)
            break;
        v[s]=1;
        for(j=0;j<=n;j++)
            if(v[j]==0 && cost[s][j]+dis[s]<dis[j])
                dis[j]=cost[s][j]+dis[s];
    }
    printf("%0.4lf",dis[n]);
    return 0;
}
