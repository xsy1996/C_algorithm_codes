#include<stdio.h>
long long t,a1,b1,a2,b2,ans;
long long m(long long x,long long y)
{
    if(x>y)
        return y;
    else
        return x;
}   
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    long long i,j,k,q,w,min,a,b,c;
    scanf("%I64d%I64d%I64d%I64d%I64d",&t,&b1,&a1,&b2,&a2);
    if(t==0)
    {
        printf("0\n");
        return 0;
    }
    if(a2/b2>=10 && a1/b1>=10)
    {
        printf("%I64d\n",t*10);
        return 0;
    }
    if(a1/b1>=10)
    {
        printf("%I64d\n",t/b2*a2+10*(t%b2));
        return 0;
    }
    if(a2/b2>=10)
    {
        printf("%I64d\n",t/b1*a1+10*(t%b1));
        return 0;
    }
    ans=0;
    if((b1<100000 || b2<100000))
    {
        ans+=(t/(b1*b2))*m(b2*a1,b1*a2);
        t%=b1*b2;
    }
    min=t*10+1;
    if((t/b1)<(t/b2))
        for(i=0;i<=(t/b1);i++)
        {
            b=t-b1*i;
            a=b/b2;
            c=t-i*b1-a*b2;
            if(min>(i*a1+a*a2+c*10))
                min=i*a1+a*a2+c*10;
        }
    else
        for(i=0;i<=(t/b2);i++)
        {
            b=t-b2*i;
            a=b/b1;
            c=t-i*b2-a*b1;
            if(min>(i*a2+a*a1+c*10))
                min=i*a2+a*a1+c*10;
        }
    if(min>(t/b1+1)*a1)
        min=(t/b1+1)*a1;
    if(min>(t/b2+1)*a2)
        min=(t/b2+1)*a2;
    printf("%I64d\n",min+ans);
    return 0;
}
