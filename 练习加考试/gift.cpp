#include<stdio.h>
#include<stdlib.h>
long sum[100001],n,m,a[2500],v[2500],num[2500];
void qsort(long l,long r)
{
    long i,j,k,x;
    i=l;j=r;
    x=v[(i+j)/2];
    while(i<=j)
    {
        while(v[i]<x)i++;
        while(v[j]>x)j--;
        if(i<=j)
        {
            k=v[i];
            v[i]=v[j];
            v[j]=k;
            k=a[i];
            a[i]=a[j];
            a[j]=k;
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
int main()
{
    freopen("gift.in","r",stdin);
    freopen("gift.out","w",stdout);
    long i,j,k;
    scanf("%d",&k);
    n=1;
    for(i=1;i<=k;i++)
        n*=2;
    i=0;
    m=2*n+1;
    while(scanf("%d",&a[i+1])!=EOF)
        i++;
    srand(11);
	for(i=1;i<=m;i++)
	   num[i]=i;
    while(1)
    {
		for(i=1;i<=m;i++)
			v[i]=rand();
		qsort(1,m);
		sum[0]=0;
        for(i=1;i<=m;i++)
            sum[i]=sum[i-1]+a[i];
        for(i=0;i<=m-n;i++)
            if((sum[i+n]-sum[i])%n==0)
            {
                for(j=1;j<=n;j++)
                    printf("%d ",num[i+j]);
                printf("\n");
                return 0;
            }
    }
    return 0;
}
