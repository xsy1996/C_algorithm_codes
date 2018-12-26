/*
ID:xsy19962
TASK:subset
LANG:C++
*/
#include<stdio.h>
long long f[1001],n;
int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    long long i,j,k,n,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        sum+=i;
    if(sum%2==1)
    {
        printf("0\n");
        return 0;
    }
    f[0]=1;
    for(i=1;i<=n;i++)
        for(j=sum/2;j>=0;j--)
            if(f[j]!=0 && j+i<=sum/2)
                f[j+i]+=f[j];
    printf("%lld\n",f[sum/2]/2);
    return 0;
}
