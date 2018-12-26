#include<stdio.h>
long a[100001],b[1000001],n,m,t;
void hp(long x,long y)
{
    long i,j,k;
    if(b[x/2]<y || x==1)
    {
        b[x]=y;
        return;
    }
    b[x]=b[x/2];
    hp(x/2,y);
    return;
}
void del(long x)
{
    long i,j,k=-1,q;
    i=2*x;j=2*x+1;
    if(i<=t)
        k=i;
    if(j<=t && b[j]<b[i])
        k=j;
    if(k!=-1)
    {
        q=b[x];
        b[x]=b[k];
        b[k]=q;
        del(k);
        return;
    }
    return;
}
void qsort(long l,long r)
{
    long i,j,k,x;
    i=l;j=r;
    x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]>x)i++;
        while(a[j]<x)j--;
        if(i<=j)
        {
            k=a[i];a[i]=a[j];a[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
int main()
{
    freopen("Flower.in","r",stdin);
    freopen("Flower.out","w",stdout);
    long i,j,k,min;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(1,n);
    t=m;
    for(i=1;i<=n;i++)
    {
        k=b[1]+a[i];
        b[1]=2147483640;
        del(1);
        t++;
        hp(t,k);
    }
    k=0;
    for(i=1;i<=t;i++)
        if(k<b[i] && b[i]!=2147483640)
            k=b[i];
    printf("%d\n",k);
    return 0;
}
