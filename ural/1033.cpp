#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

const long MAXn=10100,INF=1000000000;

long fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}},n,map[101][101],v[101][101],ans;

void dfs(long xx,long yy)
{
	long i,j,k,x,y;
	v[xx][yy]=1;
	for(i=0;i<=3;i++)
	{
		x=xx+fx[i][0];
		y=yy+fx[i][1];
		if((x==0 && y==1) || (x==1 && y==0) || (x==n && y==n+1) || (x==n+1 && y==n))
			continue;
		if(map[x][y]==1)
		{
			ans++;
			//printf("%d %d %d %d\n",xx,yy,x,y);
			continue;
		}
		if(v[x][y]==0)
			dfs(x,y);
	}
	return;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	long i,j,k;
	char c;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
	{
		map[i][0]=1;
		map[i][n+1]=1;
		map[0][i]=1;
		map[n+1][i]=1;
	}
	getchar();
	for(i=1;i<=n;i++,getchar())
		for(j=1;j<=n;j++)
		{
			scanf("%c",&c);
			if(c=='#')
				map[i][j]=1;
		}
	/*for(i=0;i<=n+1;i++,printf("\n"))
		for(j=0;j<=n+1;j++)
			printf("%d ",map[i][j]);*/
	ans=0;
	dfs(1,1);
	if(v[n][n]==0)
		dfs(n,n);
	printf("%d\n",ans*9);
	return 0;
}