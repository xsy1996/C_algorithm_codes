/*
ID:xsy1962
TASK:zerosum
LANG:C++
*/
#include<stdio.h>
long n,sum,path[101];
void dfs(long x,long y,long s,long f)
{
	long i,k;
	if(x==n && y!=0 && s+f*y==0)
	{
		for(i=1;i<n;i++)
		{
			printf("%ld",i);
			if(path[i]==0)
				printf(" ");
			if(path[i]==1)
				printf("+");
			if(path[i]==-1)
				printf("-");
		}
		printf("%ld\n",n);
	}
	if(x==n)
		return;
	k=y*10+x+1;
	path[x+1]=0;
	dfs(x+1,k,s,f);
	path[x+1]=1;
	dfs(x+1,0,s+f*k,1);
	path[x+1]=-1;
	dfs(x+1,0,s+f*k,-1);
	return;
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%ld",&n);
	dfs(0,0,0,1);
	return 0;
}
