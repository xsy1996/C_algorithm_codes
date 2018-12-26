#include<stdio.h>
long long a[1000001],t=0,f,l;
int main()
{
    freopen("Number.in","r",stdin);
    freopen("Number.out","w",stdout);
    long long i,j,k,m,n;
    scanf("%I64d",&m);
    f=0;l=1;
    a[1]=1;
    while(l<10000)
    {
        k=0;
        while(a[f]*5<a[l])
            f++;
        for(i=f;i<=l;i++)
        {
            if(a[i]*2>a[l] && (k==0 || a[i]*2<k))
                k=a[i]*2;
            if(a[i]*3>a[l] && (k==0 || a[i]*3<k))
                k=a[i]*3;
            if(a[i]*5>a[l] && (k==0 || a[i]*5<k))
                k=a[i]*5;
        }
        l++;
        a[l]=k;
    }
    for(;m>=1;m--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}
