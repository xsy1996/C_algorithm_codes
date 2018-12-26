#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define lowbit(k) ((k)&(-1*(k)))
#define abs(k) (((k)>=0)?(k):((k)*-1))

const long MAXn=10100,INF=1000000000,mod=10000;

long f[1001][1001],n,s,len[1001],ans[1001],la;

void add(long a,long b)
{
	long i,j,k;
	if(len[b]<len[a])	
		len[b]=len[a];
	for(i=1;i<=len[a];i++)
		f[b][i]+=f[a][i];
	for(i=1;i<=len[b];i++)
	{
		f[b][i+1]+=f[b][i]/mod;
		f[b][i]%=mod;
	}
	while(f[b][len[b]+1]>0)
	{
		len[b]++;
		f[b][len[b]+1]+=f[b][len[b]]/mod;
		f[b][len[b]]%=mod;
	}
	return;
}

void muilt()
{
	long i,j,k;
	la=len[s]*2-1;
	for(i=1;i<=len[s];i++)
		for(j=1;j<=len[s];j++)
		{
			ans[i+j-1]+=f[s][i]*f[s][j];
			ans[i+j]+=ans[i+j-1]/mod;
			ans[i+j-1]%=mod;
		}
	while(ans[la+1]>0)
	{
		la++;
		ans[la+1]+=ans[la]/mod;
		ans[la]%=mod;
	}
	return;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	long i,j,k;
	scanf("%d%d",&n,&s);
	if(s&1 || s>n*2*9)
	{
		printf("0\n");
		return 0;
	}
	s/=2;
	len[0]=1;
	f[0][1]=1;
	for(i=1;i<=n;i++)
		for(j=s;j>=0;j--)
			for(k=1;k<=j && k<=9;k++)
				add(j-k,j);
	muilt();
	printf("%d",ans[la]);
	for(i=la-1;i>=1;i--)
		printf("%04d",ans[i]);
	printf("\n");
	return 0;
}