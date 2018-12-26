#include<stdio.h>
long long n,x[10001],y[10001],d[10001],s=0,v[1000001],h[10001],t=0,m=0;
void qsort(long long l,long long r)
{
    long long i,j,k,a;
    i=l;j=r;
    a=x[(i+j)/2];
    while(i<=j)
    {
        while(x[i]<a)i++;
        while(x[j]>a)j--;
        if(i<=j)
        {
            k=x[i];
            x[i]=x[j];
            x[j]=k;
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            k=d[i];
            d[i]=d[j];
            d[j]=k;
            i++;
            j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
long long count(long long high,long long l1,long long l2)
{
    long long i,j,k;
    if(l1>=l2)
        return 0;
    if(l2-l1<=high)
        return (l2-l1)*(l2-l1);
    return (2*(l2-l1)-high)*high;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long i,j,k,a;
    scanf("%I64d\n",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%I64d",&x[i],&y[i],&d[i]);
        v[y[i]]=1;
        if(y[i]>m)
            m=y[i];
    }
    qsort(1,n);
    for(i=0;i<=m;i++)
        if(v[i]==1)
        {
            t++;
            h[t]=i;
        }
    h[t+1]=h[t]+1000001;
    for(i=1;i<=t;i++)
    {
        a=0;
        for(j=1;j<=n;j++)
        {
            while(((y[j]+d[j]<=h[i] || y[j]>=h[i+1]) || (y[j]==h[i] && x[j]+d[j]<=a))&& j<=n)
            {
                if(y[j]==h[i] && x[j]+d[j]<=a && j<=n)
                {
                    x[j]=-1;
                    y[j]=-1;
                    d[j]=0;
                }
                j++;
            }
            if(j>n)
                break;
            s+=count(h[i+1]-h[i],x[j],x[j]+d[j]);
            s-=count(h[i+1]-h[i],x[j],a);
           // printf("%I64d   %I64d %I64d %I64d    %I64d   %I64d \n",a,x[j],y[j],d[j],h[i+1]-h[i],s);
            a=x[j]+d[j];
            y[j]=h[i+1];
            d[j]-=h[i+1]-h[i];
        }
    }
    printf("%0.1f",(s*1.0)/2);
    return 0;
}
