#include<stdio.h>
long map[1001][1001],q[1001][1001],x[1000001],y[1000001],f,l,toward[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int main()
{
    freopen("climbing.in","r",stdin);
    freopen("climbing.out","w",stdout);
    long i,j,k,n,m,x1,y1,max=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(q[i][j]==0)
            {
                f=0;l=1;
                x[1]=i;
                y[1]=j;
                q[i][j]=1;
                while(f<l)
                {
                    f++;
                    for(k=0;k<=3;k++)
                    {   
                        x1=x[f]+toward[k][0];
                        y1=y[f]+toward[k][1];
                        if(q[x[f]][y[f]]+1>q[x1][y1] && map[x[f]][y[f]]>map[x1][y1])
                        {
                            l++;
                            x[l]=x1;
                            y[l]=y1;
                            q[x1][y1]=q[x[f]][y[f]]+1;
                        }
                    }
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(q[i][j]>max)
                max=q[i][j];
    printf("%d\n",max);
    return 0;
}
