#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000;

long n,f[101][101],map[101][101],m,v[101],l[101],s[101];

void dfs(long a)
{
	long i,j,k,x=0,y=0;
	s[a]=1;
	for(i=1;i<=n;i++)
		if(map[a][i]>0 && v[i]==0)
		{
			v[i]=1;
			l[i]=map[a][i];
			dfs(i);
			s[a]+=s[i];
			if(x==0)
				x=i;
			else
				y=i;
		}
	f[a][0]=0;
	if(s[a]==1)
	{
		f[a][1]=l[a];
		return;
	}
	for(i=0;i<=s[x];i++)
		for(j=0;j<=s[y];j++)
			if(f[a][i+j+1]<l[a]+f[x][i]+f[y][j])
				f[a][i+j+1]=l[a]+f[x][i]+f[y][j];
	return;
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}
	v[1]=1;
	dfs(1);
	printf("%d\n",f[1][m+1]);
	return 0;
}
