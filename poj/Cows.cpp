#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long x[50001],y[50001],a[100001],t,n,dis[200001];
double slope[100001],ans=0;
void qsort(long l,long r)
{
    long i,j,k,q,w;
    i=l;j=r;
    q=x[(i+j)/2];
    w=y[(i+j)/2];
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
            i++;
            j--;    
        }
    }
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
    return;
}
void convex()
{
    long i,j;
    double k;
    qsort(1,n);
    slope[1]=2147483647.0;
    a[1]=1;
    t=1;
    for(i=2;i<=n;i++)
    {
        if(x[i]==x[a[t]])
            k=2147483647.0;
        else
            k=((y[i]-y[a[t]])*1.0)/((x[i]-x[a[t]])*1.0);
        while(k>slope[t])
        {
            t--;         
            k=((y[i]-y[a[t]])*1.0)/((x[i]-x[a[t]])*1.0); 
        }  
        t++;
        a[t]=i;
        slope[t]=k;
    }
    slope[t]=2147483647.0;
    for(i=n-1;i>=1;i--)
    {
        if(x[i]==x[a[t]])
            k=2147483647.0;
        else
            k=((y[a[t]]-y[i])*1.0)/((x[a[t]]-x[i])*1.0);
        while(k>slope[t])
        {
            t--;         
            k=((y[a[t]]-y[i])*1.0)/((x[a[t]]-x[i])*1.0); 
        }             
        t++;
        a[t]=i;
        slope[t]=k;
    }
    return;
}
void acreage()
{
    long i,j,k=1;
    double s1,s2,s3,p;
    for(i=1;i<t;i++)
    {
        s1=sqrt((x[a[i]]-x[a[i+1]])*(x[a[i]]-x[a[i+1]])+(y[a[i]]-y[a[i+1]])*(y[a[i]]-y[a[i+1]]));
        s2=sqrt((x[a[k]]-x[a[i+1]])*(x[a[k]]-x[a[i+1]])+(y[a[k]]-y[a[i+1]])*(y[a[k]]-y[a[i+1]]));
        s3=sqrt((x[a[i]]-x[a[k]])*(x[a[i]]-x[a[k]])+(y[a[i]]-y[a[k]])*(y[a[i]]-y[a[k]]));
        p=(s1+s2+s3)/2;
        ans+=sqrt(p*(p-s1)*(p-s2)*(p-s3));
    }
    return;
}

int main()
{   
    long i,j,k;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        scanf("%ld%ld",&x[i],&y[i]);
    convex();
    acreage();
    if(ans/50-long(ans/50)>0.99999)
        printf("%ld\n",long(ans/50)+1);
    else
        printf("%ld\n",long(ans/50));
    system("pause");
    return 0;
}
