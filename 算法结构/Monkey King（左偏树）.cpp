#include<stdio.h>
long tree[100001][2],a[100001],f[100001],dis[100001];
long q(long x)
{
    if(f[x]==x)
        return x;
    return q(f[x]);
}
void unite(long x,long y)
{
    long i,j,k;
    if(a[x]>a[y])
    {
        if(tree[x][1]==0)
        {
            tree[x][1]=y;
            f[y]=x;
        }
        else   
        {
            f[tree[x][1]]=tree[x][1];
            unite(tree[x][1],y);
            k=q(y);
            tree[x][1]=k;
            f[k]=x;
        }
        if(dis[tree[x][1]]>dis[tree[x][0]])
        {
            k=tree[x][0];
            tree[x][0]=tree[x][1];
            tree[x][1]=k;
        }
        dis[x]=dis[tree[x][1]]+1;
        return;
    }
    else
    {
        if(tree[y][1]==0)
        {
            tree[y][1]=x;
            f[x]=y;
        }
        else   
        {
            f[tree[y][1]]=tree[y][1];
            unite(tree[y][1],x);
            k=q(x);
            tree[y][1]=k;
            f[k]=y;
        }
        if(dis[tree[y][1]]>dis[tree[y][0]])
        {
            k=tree[y][0];
            tree[y][0]=tree[y][1];
            tree[y][1]=k;
        }
        dis[y]=dis[tree[y][1]]+1;
        return;
    } 
}
void del(long x)
{
    long k=0;
    f[tree[x][0]]=tree[x][0];
    f[tree[x][1]]=tree[x][1];
    if(tree[x][0]!=0)
        k=tree[x][0];
    else if(tree[x][1]!=0)
        k=tree[x][1];
    if(tree[x][0]!=0 && tree[x][1]!=0)
        unite(tree[x][0],tree[x][1]);
    a[x]/=2;
    f[x]=x;
    tree[x][0]=0;
    tree[x][1]=0;
    if(k!=0)
        unite(x,q(k));
    return;
}
int main()
{
    long i,j,k,x,y,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            tree[i][0]=0;
            tree[i][1]=0;
            f[i]=i;
            dis[i]=0;
        }
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            if(q(x)==q(y))
                printf("-1\n");
            else
            {   
                del(q(x));
                del(q(y));
                unite(q(x),q(y));
                printf("%d\n",a[q(x)]);
               /* for(j=1;j<=n;j++)
                    printf("%d ",a[j]);
                printf("\n");*/
            }
        }  
    }     
    return 0;
}
