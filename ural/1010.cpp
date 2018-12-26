#include<cstdio>
#include<cstring>
#include<algorithm>

#define jdz(a) (((a)>0)?(a):((a)*-1))

const long INF=100000000,MAXn=100101;

long long h[MAXn],n,x;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&h[i]);
	x=1;
	for(i=2;i<n;i++)
		if(jdz(h[i+1]-h[i])>jdz(h[x+1]-h[x]))
			x=i;
	printf("%I64d %I64d\n",x,x+1);
	return 0;
}
