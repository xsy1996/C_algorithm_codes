#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000,mod=10000;

long n,m,f[2001][1001],len[2001];

void count(long x)
{ 
	long i,j,k;
	k=len[x-1];
	for(i=1;i<=k;i++)
		f[x][i]=(f[x-1][i]+f[x-2][i])*m;
	for(i=1;i<=k;i++)
	{
		f[x][i+1]+=f[x][i]/mod;
		f[x][i]%=mod;
	}
	while(f[x][k+1]>0)
	{
		k++;
		f[x][k+1]=f[x][k]/mod;
		f[x][k]%=mod;
	}
	len[x]=k;
	return;
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d%d",&n,&m);
	m--;
	f[0][1]=1;
	len[0]=1;
	f[1][1]=m;
	len[1]=1;
	for(i=2;i<=n;i++)
		count(i);
	printf("%d",f[n][len[n]]);
	for(i=len[n]-1;i>=1;i--)
		printf("%04d",f[n][i]);
	printf("\n");
	return 0;
}
