#include<stdio.h>
long dis[101][101],n,e[101][101];
int main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    long i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&dis[i][j]);
    for(i=1;i<=n;i++)
        e[i][i]=-1;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(k!=i && j!=k && i!=j)
            {
                if(dis[i][k]+dis[k][j]==dis[i][j])
                    e[i][j]=-1;
                else if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    printf("impossible\n");
                    return 0;
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(e[i][j]!=-1)
                sum++;
    printf("%d\n",sum);
    return 0;
}
