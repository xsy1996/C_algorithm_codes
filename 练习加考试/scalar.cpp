#include<stdio.h>
#include<stdlib.h>
long long x[801],y[801];
void qsortx(long l,long r)
{   
    long i,j,k,a;
    i=l;j=r;
    a=x[(l+r)/2];
    while(i<=j)
    {
        while(x[i]<a)i++;
        while(x[j]>a)j--;
        if(i<=j)
        {
            k=x[i];x[i]=x[j];x[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsortx(i,r);
    if(l<j)qsortx(l,j);
    return;
}
void qsorty(long l,long r)
{   
    long i,j,k,a;
    i=l;j=r;
    a=y[(l+r)/2];
    while(i<=j)
    {
        while(y[i]>a)i++;
        while(y[j]<a)j--;
        if(i<=j)
        {
            k=y[i];y[i]=y[j];y[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsorty(i,r);
    if(l<j)qsorty(l,j);
    return;
}
int main()
{
    freopen("scalar.in","r",stdin);
    freopen("scalar.out","w",stdout);
    long long i,j,k,sum=0,n;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d",&x[i]);
    for(i=1;i<=n;i++)
        scanf("%I64d",&y[i]);
    qsortx(1,n);
    qsorty(1,n);
    for(i=1;i<=n;i++)
        sum+=x[i]*y[i];
    printf("%I64d\n",sum);
    return 0;
}
