/*
ID:xsy19962
TASK:fence9
LANG:C++
*/
#include<stdio.h>
#define jdz(a) (((a)>=0)?(a):(a)*-1)
long x,y,p,s;
long gcd(long a,long b)
{
    long k;
    if(a>b)
    {
        k=a;
        a=b;
        b=k;
    }
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    long i,j,k;
    scanf("%d%d%d",&x,&y,&p);
    s=y*p+2;
    s-=p;
    s-=gcd(x,y);
    s-=gcd(jdz(p-x),y)-1;
    printf("%d\n",s/2);
    return 0;
}
