#include<stdio.h>
long tree[501][2],cost[501],f[501][501],key[501],map[501][501],n,d[501],s,l,v[501];
void dfs(long x,long y)
{
    long i,j,k;
    if(f[x][y]>0 || x==0)
        return;
    dfs(tree[x][1],y);
    f[x][y]=f[tree[x][1]][y];
    for(i=cost[x];i<=y;i++)
    {
        dfs(tree[x][0],i-cost[x]);
        dfs(tree[x][1],y-i);
        if(f[x][y]<f[tree[x][0]][i-cost[x]]+key[x]+f[tree[x][1]][y-i])
            f[x][y]=f[tree[x][0]][i-cost[x]]+key[x]+f[tree[x][1]][y-i];
    } 
    return;
}
int main()
{
    freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);
    long i,j,k,x,y,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&cost[i],&key[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
        map[y][x]=1;
    }
    s=0;l=1;
    d[1]=1;
    v[1]=1;
    while(s<l)
    {
        s++;
        i=d[s];
        j=1;
        while((map[i][j]==0 || v[j]==1) && j<=n+1)
            j++;
        if(map[i][j]==1 || v[j]==0 && j<=n)
        {
            tree[i][0]=j;
            l++;
            d[l]=j;
            v[j]=1;
        }
        k=j;
        j++;
        for(;j<=n;j++)
            if(map[i][j]==1 && v[j]==0)
            {
                tree[k][1]=j;
                k=j;
                l++;
                d[l]=j;
                v[j]=1;
            }
    }
    dfs(1,m);
    printf("%d\n",f[1][m]);
    return 0;
}
