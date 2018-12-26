#include<stdio.h>
#include<stdlib.h>
long long s[10001],t=0;
int main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    long long i,j,k,n,sum=1,ans=1;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        sum+=4*i-3;
    while(sum>0)
    {
        t++;
        s[t]=sum%2;
        sum/=2;
    }
    for(i=t;i>=1;i--)
    {
        ans=(ans*ans)%19900801;
        if(s[i]==1)
            ans*=2;
        ans%=19900801;
    }
  /*  for(i=1;i<=sum;i++)
    {
        ans*=2;
        ans%=19900801;
    }*/
    printf("%I64d\n",ans);
    return 0;
}
