#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>=0?(a):((a)*-1))

const long INF=1000000000,MAXn=10000;

long n,v[1001],ans=1,f[1001],step;

long gcd(long x,long y)
{
	long k;
	if(x>y)
	{
		k=x;
		x=y;
		y=k;
	}
	if(y%x==0)
		return x;
	return gcd(y%x,x);
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(i=1;i<=n;i++)
		if(v[i]==0)
		{
			v[i]=1;
			k=f[i];step=1;
			while(k!=i)
			{
				v[k]=1;
				k=f[k];
				step++;
			}
			ans*=step/gcd(ans,step);
			//printf("%d\n",step);
		}
	printf("%d\n",ans);
	return 0;
}
