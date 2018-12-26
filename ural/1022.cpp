#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>=0?(a):((a)*-1))

const long INF=1000000000,MAXn=10000;

long f[101],s[101][101],n,v[101];
bool flag;

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(k!=0)
		{
			s[i][0]++;
			s[i][s[i][0]]=k;
			f[k]++;
			scanf("%d",&k);
		}
	}
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=1;i<=n;i++)
			if(v[i]==0 && f[i]==0)
			{
				flag=1;
				v[i]=1;
				printf("%d ",i);
				for(j=1;j<=s[i][0];j++)
					f[s[i][j]]--;
			}
	}
	printf("\n");
	return 0;
}
