#include<stdio.h>
long men[1001][2],house[1001][2],cost[2001][2001],n,m,sm,sh,x[2001],y[2001],v[2001],min,ans;
long jdz(long a)
{
    if(a<0)
        return -1*a;
    return a;
}
long match(long a)
{
    long i,j,k;
    v[a]=1;
    for(i=1;i<=sh;i++)
        if(cost[a][i]==x[a]+x[i+sm] && v[i+sm]==0)
        {
            v[i+sm]=1;   
            if(y[i]==-1 || match(y[i]))
            {
                y[i]=a;
                return 1;
            }
        }
    return 0;
}
int main()
{
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    long i,j,k;
    char c;
    scanf("%d%d",&n,&m);
    while(n!=0 && m!=0)
    {
        ans=0;
        sm=0;
        sh=0;
        getchar();
        for(i=1;i<=n;i++,getchar())
            for(j=1;j<=m;j++)
            {
                scanf("%c",&c);
                if(c=='m')
                {
                    sm++;
                    men[sm][0]=i;
                    men[sm][1]=j;
                }
                if(c=='H')
                {
                    sh++;
                    house[sh][0]=i;
                    house[sh][1]=j;
                }
            }
        for(i=1;i<=sh;i++)
            y[i]=-1;
        for(i=1;i<=sm;i++)
            x[i]=2147483600;
        for(i=1;i<=sh;i++)
            x[i+sm]=0;
        for(i=1;i<=sm;i++)
            for(j=1;j<=sh;j++)
            {
                cost[i][j]=jdz(men[i][0]-house[j][0])+jdz(men[i][1]-house[j][1]);
                if(cost[i][j]<x[i])
                    x[i]=cost[i][j];
            }
         for(i=1;i<=sm;i++)
            while(match(i)==0)
            {
                min=2147483600;
                for(j=1;j<=sm;j++)
                    if(v[j]==1)
                        for(k=1;k<=sh;k++)
                            if(v[k+sm]==0 && cost[j][k]-x[j]-x[k+sm]<min)
                                min=cost[j][k]-x[j]-x[k+sm];
                for(j=1;j<=sm;j++)
                    if(v[j]==1)
                        x[j]+=min;
                for(j=1;j<=sh;j++)
                    if(v[j+sm]==1)
                        x[j+sm]-=min;
                for(j=1;j<=sm+sh;j++)
                    v[j]=0;
            }
        for(i=1;i<=sm+sh;i++)
            ans+=x[i];
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
