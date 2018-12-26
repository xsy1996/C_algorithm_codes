#include<stdio.h>
long long a[200005],min=-2147483600,max=2147483600;
int main()
{
    freopen("Number.in","r",stdin);
    freopen("Number.out","w",stdout);
    long i,j,k,n;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&k);
        a[i+1]=k*2-a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(i%2==1 && max>(a[i+1]-a[i])/2)
            max=(a[i+1]-a[i])/2;
        if(i%2==0 && min<(a[i]-a[i+1])/2)
            min=(a[i]-a[i+1])/2;
    }
    if(max<min)
    	printf("0\n");
   	else
    	printf("%I64d\n",max-min+1);
    return 0;
}
