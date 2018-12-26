/*
ID:xsy19962
TASK:fact4
LANG:C++
*/
#include<stdio.h>
long n,ans=1,s=0;
int main()
{
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        k=i;
        while(k%2==0)
        {
            k/=2;
            s++;
        }
        while(k%5==0)
        {
            k/=5;
            s--;
        }
        ans*=k;
        ans%=10;
    }
    while(s>0)
    {
        ans*=2;
        ans%=10;
        s--;
    }
    while(s<0)
    {
        ans*=5;
        ans%=10;
        s++;    
    }
    printf("%d\n",ans);
    return 0;
}
