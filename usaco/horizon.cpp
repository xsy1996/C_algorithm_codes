#include<stdio.h>
long long tree[400001],lt[400001],rt[400001],h[40001],a[80001],b[80001],num[80001],x[40001],y[40001],n,ans=0;
void qsort(long long l,long long r)
{
    long long i,j,k,q;
    q=a[(l+r)/2];
    i=l;j=r;
    while(i<=j)
    {
        while(a[i]<q)i++;
        while(a[j]>q)j--;
        if(i<=j)
        {
            k=a[i];
            a[i]=a[j];
            a[j]=k;
            k=b[i];
            b[i]=b[j];
            b[j]=k;
            k=num[i];
            num[i]=num[j];
            num[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
void t(long long root,long long l,long long r)
{
    long i,j,k;
    lt[root]=l;
    rt[root]=r;
    if(l<r)
    {
        t(root*2,l,(l+r)/2);
        t(root*2+1,(l+r)/2+1,r);
    }
    return;
}
void qs(long l,long r)
{
    long i,j,k,q;
    q=h[(l+r)/2];
    i=l;j=r;
    while(i<=j)
    {
        while(h[i]<q)i++;
        while(h[j]>q)j--;
        if(i<=j)
        {
            k=h[i];
            h[i]=h[j];
            h[j]=k;
            k=x[i];
            x[i]=x[j];
            x[j]=k;
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            i++;j--;
        }
    }
    if(l<j)qs(l,j);
    if(i<r)qs(i,r);
    return;
} 
long min(long long xx,long long yy)
{
    if(xx<yy)
        return xx;
    return yy;
}
long max(long long xx,long long yy)
{
    if(xx>yy)
        return xx;
    return yy;
}
void update(long long root,long long l,long long r,long long hh)
{
    long long i,j,k;
    if(l==lt[root] && r==rt[root])
    {
        tree[root]=hh;
        return;
    }
    if(tree[root]>=0)
    {
        tree[root*2]=tree[root];
        tree[root*2+1]=tree[root];
        tree[root]=-1;
    }
    if(l<=rt[root*2])
        update(root*2,l,min(r,rt[root*2]),hh);
    if(r>=lt[root*2+1])
        update(root*2+1,max(lt[root*2+1],l),r,hh);
    return;
}
void count(long long root)
{
    if(tree[root]>=0)
    {
        ans+=tree[root]*(a[rt[root]+1]-a[lt[root]]);
        return;
    }
    count(root*2);
    count(root*2+1);
    return;
}
int main()
{
    freopen("horizon.in","r",stdin);
    freopen("horizon.out","w",stdout);
    long long i,j,k;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%I64d\n",&a[2*i-1],&a[2*i],&h[i]);
        b[2*i-1]=-1;
        b[2*i]=1;
        num[2*i-1]=i;
        num[2*i]=i;
    }
    qsort(1,2*n);
    for(i=1;i<=2*n;i++)
    {
        if(b[i]==-1)
            x[num[i]]=i;
        if(b[i]==1)
            y[num[i]]=i;
    }
    t(1,1,2*n);
    qs(1,n);
    for(i=1;i<=n;i++)
        update(1,x[i],y[i]-1,h[i]);
    count(1);
    printf("%I64d\n",ans);
    return 0;
}
