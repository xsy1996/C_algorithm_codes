#include<stdio.h>
long a[50001],x[15001],y[15001],n,s[15001],max=0;
void qsort(long l,long r)
{
    long i,j,k,q,w;
    i=l;j=r;
    q=x[(i+j)/2];w=y[(i+j)/2];
    while(i<=j)
    {
        while(x[i]<q || (x[i]==q && y[i]<w))i++;
        while(x[j]>q || (x[j]==q && y[j]>w))j--;
        if(i<=j)
        {
            k=x[i];
            x[i]=x[j];
            x[j]=k;
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
void add(long k)
{
    long i,j;
    while(k<=max)
    {
        a[k]++;
        k+=k&(k^(k-1));
    }
    return;
}
long count(long k)
{
    long i,j,sum=0;
    while(k>0)
    {
        sum+=a[k];
        k-=k&(k^(k-1));
    }
    return sum;
}
int main()
{
    //freopen("s.in","r",stdin);
    //freopen("s.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]++;
        y[i]++;
        if(y[i]>max)
            max=y[i];
    }
    qsort(1,n);
    k=0;
    for(i=1;i<=n;i++)
    {
        add(y[i]);
        s[count(y[i])]++;
    //    printf("%d  %d  %d\n",x[i],y[i],count(y[i]));
    }
    for(i=1;i<=n;i++)
        printf("%d\n",s[i]);
    return 0;
}
