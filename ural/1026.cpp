#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>=0?(a):((a)*-1))

using std :: sort;

const long INF=1000000000,MAXn=101000;

long n,a[MAXn],m;
char c[101];

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	scanf("%s",c);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		printf("%d\n",a[k]);
	}
	return 0;
}
