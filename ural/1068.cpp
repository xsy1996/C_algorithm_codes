#include<stdio.h>
#include<stdlib.h>
int main()
{
    long n,a,b,sum=0,i,j;
    scanf("%d",&n);
    if(n<=1)
      for(i=n;i<=1;i++)
        sum+=i;
    if(n>1)
      for(i=1;i<=n;i++)
        sum+=i;
    printf("%d\n",sum);
    return 0;
}
