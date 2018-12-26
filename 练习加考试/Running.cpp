#include<stdio.h>
long e[5001][5001],v[5001],s[5001],t=0,flag,n,m;
void dfs(long x,long y)
{
    long i,j,k;
    if(flag==1)
        return;
    if(x==n)
    {
        flag=1;
        return;
    }
    for(i=1;i<=e[x][0];i++)
        if(v[e[x][i]]==0)
        {
            v[e[x][i]]=1;
            dfs(e[x][i],y);
        }
    return;
}
int main()
{
    freopen("Running.in","r",stdin);
    freopen("Running.out","w",stdout);
    long i,j,k,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        e[a][0]++;
        e[a][e[a][0]]=b;
        e[b][0]++;
        e[b][e[b][0]]=a;
    }
    v[1]=1;
    for(i=2;i<n;i++)
    {
        flag=0;
        for(j=2;j<=n;j++)
            v[j]=0;
        v[i]=1;
        dfs(1,i);
        if(flag==0)
        {
            t++;
            s[t]=i;
        }
    }
    printf("%d\n",t);
    for(i=1;i<=t;i++)
        printf("%d ",s[i]);
    printf("\n");
    return 0;
}
