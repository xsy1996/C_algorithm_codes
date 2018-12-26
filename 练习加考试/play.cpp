#include<stdio.h>
long long n;
long long q(long long a,long long b)
{
    long long i,j,k=1;
    for(i=1;i<=b;i++)
        k*=a;
    if(k>n)
        return 0;
    else 
        return 1;
}
long min(long x,long y)
{
	if(x>y)
		return y;
	else
		return x;
}
long f(long x,long y)
{
	if(q(x,y)==0)
		return 1;
	if(x==1 && q(2,y)==0)
		return 0;
	if(y==1 && q(x,2)==0)
		if((n-x)%2==0)
			return -1;
		else
			return 1;
	return -1*min(f(x+1,y),f(x,y+1));
}
int main()
{
    freopen("play.in","r",stdin);
    freopen("play.out","w",stdout);
    long long i,j,k,t,w,e,x,y;
    scanf("%I64d",&n);
    scanf("%I64d",&t);
    for(;t>=1;t--)
    {
        scanf("%I64d%I64d",&x,&y);
        k=f(x,y);
        if(k==1)
        	printf("Masha\n");
        else if(f(x,y)==0)
        	printf("Missing\n");
        else
        	printf("Stas\n");
    }
    return 0;
}
