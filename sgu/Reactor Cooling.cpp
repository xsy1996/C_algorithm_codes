#include<stdio.h>
long n,d[501],flag=0,c[501][501],f[501][501],m,s[501],path[501],t=0,x[501],y[501],mark[501],mm[501];
void find()
{
    long i,j,k,min=2147483600;
    for(i=1;i<t;i++)
        if(c[path[i]][path[i+1]]-f[path[i]][path[i+1]]<min)
            min=c[path[i]][path[i+1]]-f[path[i]][path[i+1]];
    for(i=1;i<t;i++)
    {
        f[path[i]][path[i+1]]+=min;
        f[path[i+1]][path[i]]-=min;
    }    
    return;
}
void dfs(long a)
{
    long i,j,k=0,min=100000000;
    if(flag==1)
        return;
    if(a==n)
    {
        find();
        return;
    }   
    for(i=0;i<=n;i++)
        if(f[a][i]<c[a][i] && (d[i]==d[a]-1 || i==n))
        {
            k=1;
            t++;
            path[t]=i;
            dfs(i);
            if(d[i]<min)
                min=d[i];
            t--;
        }
    mark[d[a]]--;
    if(mark[d[a]]<=0 && min+1!=d[a] && d[a]!=0)
        flag=1;
    if(k==1)
        d[a]=min+1;
    else
        d[a]++;
    mark[d[a]]++;
    return;
} 
void sap()
{
    while(flag==0 && d[0]<=n)
    {
        t=1;
        path[1]=0;
        dfs(0);
    }
    return;
}
int main()
{
  //  freopen("r.in","r",stdin);
  //  freopen("r.out","w",stdout);
    long i,j,k,max;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&mm[i],&max);
        c[x[i]][y[i]]+=max-mm[i];
        s[x[i]]-=mm[i];
        s[y[i]]+=mm[i];
    }
    for(i=1;i<=n;i++)
        if(s[i]>0)
            c[0][i]=s[i];
        else
            c[i][n+1]=s[i]*-1;
    n++;
    sap();
   /* for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            if(c[i][j]>0)
                printf("%d %d %d\n",i,j,f[i][j]);*/
    k=0;
    for(i=1;i<n;i++)
        if(f[0][i]!=c[0][i])
        {
            k=1;
            break;
        }
    for(i=1;i<n;i++)
        if(f[i][n]!=c[i][n])
        {
            k=1;
            break;
        }
    if(k==1)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(i=1;i<=m;i++)
            printf("%d\n",f[x[i]][y[i]]+mm[i]);
    }
    return 0;
}
