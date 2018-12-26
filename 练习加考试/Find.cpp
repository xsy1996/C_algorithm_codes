#include<stdio.h>
long long sum[100001],v[100001],a[100001];
int main()
{
    freopen("Find.in","r",stdin);
    freopen("Find.out","w",stdout);
    long long i,j,k,n;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]=a[i]+sum[i-1];
        if(v[sum[i]%n]!=0)
        {
            printf("%I64d\n",i-v[sum[i]%n]);
            for(j=v[sum[i]%n]+1;j<=i;j++)
                printf("%I64d\n",a[j]);
            return 0;
        }
        v[sum[i]%n]=i;
    }
    printf("-1\n");
    return 0;
}
