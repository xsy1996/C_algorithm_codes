#include<stdio.h>
#include<stdlib.h>
long x,y,tree[10001],f[10001],t,n,v[10001],flag;
long father(long x)
{
    if(f[x]!=x)
        f[x]=father(f[x]);
    return f[x];
}
void dfs(long a)
{
    long i,j,k;
    if(flag==1)
        return;
    v[a]=1;f[a]=a;
    if(v[x]==1 && v[y]==1)
    {
        if(a==x)
            printf("%d\n",father(y));
        if(a==y)
            printf("%d\n",father(x));
        flag=1;
        return;
    }
    for(i=1;i<=n;i++)
        if(tree[i]==a)
        {
            dfs(i);
            f[i]=a;
        }
    return;
}
int main()
{
    long i,j,k,a,b;
    scanf("%d",&t);
    for(;t>=1;t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            v[i]=0;
            tree[i]=0;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            tree[b]=a;
        }
        scanf("%d%d",&x,&y);
        k=0;
        for(i=1;i<=n;i++)
            if(tree[i]==0)
                k=i;
        flag=0;
        dfs(k);
    }
    system("pause");
    return 0;
}
