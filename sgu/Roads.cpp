#include<stdio.h>
long s[1001][3],cost[2001][2001],n,m,s1,s2,x[2001],y[2001],v[2001],min,ans,path[1001],t;
void dfs(long a,long b,long c)
{
    long i,j,k;
    for(i=1;i<n;i++)
    {
        if((s[i][1]==b && s[i][2]==c) || (s[i][1]==c && s[i][2]==b))
        {
            t++;
            path[t]=i;
            for(j=1;j<=t;j++)
            {
                cost[path[j]][a]=s[path[j]][0]-s[a][0];
                if(cost[path[j]][a]<0)
                    cost[path[j]][a]=0;
            }
            t--;
            return;
        }
        else if(s[i][1]==c)
        {
            t++;
            path[t]=i;
            dfs(a,b,s[i][2]);
            t--;
        }
        else if(s[i][2]==c)
        {
            t++;
            path[t]=i;
            dfs(a,b,s[i][1]);
            t--;
        }
    }
    return;
}
long match(long a)
{
    long i,j,k;
    v[a]=1;
    for(i=n;i<=m;i++)
        if(cost[a][i]==x[a]+x[i] && v[i]==0)
        {
            v[i]=1;   
            if(y[i]==0 || (y[i]!=0 && match(y[i])))
            {
                y[i]=a;
                return 1;
            }
        }
    return 0;
}
int main()
{
    freopen("R.in","r",stdin);
    freopen("R.out","w",stdout);
    long i,j,k,q;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][0]);
    for(i=n;i<=m;i++)
    {
        t=0;
        dfs(i,s[i][1],s[i][2]);
    }
  /*  for(k=1;k<n;k++,printf("\n"))
        for(j=n;j<=m;j++)
            printf("%d ",cost[k][j]);*/
    q=m;
    for(i=1;i<n;i++)
        for(j=n;j<=m;j++)
            if(x[i]<cost[i][j])
                x[i]=cost[i][j];
    if(m-n+2<n)
        m=2*n-2;
    for(i=1;i<n;i++)
        while(match(i)==0)
        {
          /*  for(j=1;j<=m;j++)
                printf("%d ",x[j]);
            printf("\n--------------------------\n");
            for(j=n;j<=m;j++)
                printf("%d ",y[j]);
            printf("\n--------------------------\n");*/
            min=2147483600;
            for(j=1;j<=n-1;j++)
                if(v[j]==1)
                    for(k=n;k<=m;k++)
                        if(v[k]==0 && cost[j][k]<min)
                        {
                            min=x[j]+x[k]-cost[j][k];
                        }
           /* for(j=1;j<=m;j++)
                printf("%d ",v[j]);
            printf("\n--------------------------\n");*/
            if(min==2147483600)
                break;
            for(j=1;j<=n-1;j++)
                if(v[j]==1)
                    x[j]-=min;
            for(j=n;j<=m;j++)
                if(v[j]==1)
                    x[j]+=min;
            for(j=1;j<=m;j++)
                v[j]=0;
        }
    for(i=1;i<n;i++)
        printf("%d\n",s[i][0]-x[i]);
    for(i=n;i<=q;i++)
        printf("%d\n",s[i][0]+x[i]);
    return 0;
}
