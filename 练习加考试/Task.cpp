#include<stdio.h>
long a[10001],b[10001],s[10001],k;
void qsort(long l,long r)
{
    long i,j,k,x;
    i=l;j=r;
    x=b[i]-a[i];
    while(i<=j)
    {
        while(b[i]-a[i]>x)i++;
        while(b[j]-a[j]<x)j--;
        if(i<=j)
        {
            k=a[i];a[i]=a[j];a[j]=k;
            k=b[i];b[i]=b[j];b[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
int main()
{
    freopen("Task.in","r",stdin);
    freopen("Task.out","w",stdout);
    long i,j,k,n,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    qsort(1,n);
    k=0;
    for(i=1;i<=n;i++)
    {
        sum+=a[i];
        if(k>=a[i])
            k-=a[i];
        else
            k=0;
        k+=b[i];
    }
    printf("%d\n",sum+k);
    return 0;
}
