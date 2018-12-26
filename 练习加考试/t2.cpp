#include<stdio.h>
#include<math.h>
long long ans=1;
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    long long i,j,k,n;
    scanf("%I64d",&n);
    i=2;
    while(i*i<=n && i<=1000000)
    {
        k=0;
        while(n%i==0)
        {
            k++;
            n/=i;
        }   
        while(k>=2)
        {
            ans*=i*i;
            k-=2;
        }
        i++;
    }
    if(sqrt(n)*sqrt(n)==n)
        ans*=n;
    printf("%I64d\n",ans);
    return 0;
}
