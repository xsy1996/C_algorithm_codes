#include<stdio.h>
long tree[5000001],l[5000001],r[5000001],n,m,ans;
void find(long x)
{
    if(tree[x]==0)
        ans+=r[x]-l[x]+1;
    else if(tree[x]==2)
    {
        find(x*2);
        find(x*2+1);
    }
    return;
}
void color(long x,long ll,long rr)
{
    long i,j,k,a;
    if(tree[x]==1)
        return;
    if(l[x]==ll && r[x]==rr)
    {
        tree[x]=1;
        return;
    }
    a=(l[x]+r[x])/2;
    if(rr<=a)
    {
        tree[x]=2;
        color(x*2,ll,rr);
        return;
    }
    else if(ll>a)
    {
        tree[x]=2;
        color(x*2+1,ll,rr);
        return;
    }
    else
    {
        tree[x]=2;
        color(x*2,ll,a);
        color(x*2+1,a+1,rr);
        return;
    }
    return;
}
void fz(long x,long ll,long rr)
{
    l[x]=ll;r[x]=rr;
    if(ll!=rr)
    {
        fz(x*2,ll,(ll+rr)/2);
        fz(x*2+1,(ll+rr)/2+1,rr);    
    }
    return;
}
int main()
{
    freopen("axis.in","r",stdin);
    freopen("axis.out","w",stdout);
    long i,j,k,x,y;
    scanf("%d%d",&n,&m);
    fz(1,1,n);
    for(i=1;i<=m;i++)
    {
        ans=0;
        scanf("%d%d",&x,&y);
        color(1,x,y);
        find(1);
        printf("%d\n",ans);
    }
    return 0;
}
