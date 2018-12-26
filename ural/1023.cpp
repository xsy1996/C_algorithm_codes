#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>=0?(a):((a)*-1))

const long INF=1000000000,MAXn=10000;

long n;

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d",&n);
	for(i=3;i<=n;i++)
		if(n%i==0)
		{
			printf("%d\n",i-1);
			return 0;
		}
	printf("0\n");
	return 0;
}
