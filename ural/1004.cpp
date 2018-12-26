#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000;

long dis[101][101],n,m,map[101][101],mark[101][101],path[101],t;

void out(long l,long r)
{
	if(mark[l][r]==0)
	{
		t++;
		path[t]=l;
		return;
	}
	out(l,mark[l][r]);
	out(mark[l][r],r);
	return;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,x,y,z;
	scanf("%d",&n);
	while(n!=-1)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				dis[i][j]=map[i][j]=INF;
				mark[i][j]=0;
			}
		for(i=1;i<=n;i++)
			dis[i][i]=map[i][i]=0;
		for(i=1;i<=m;i++)
		{		
			scanf("%d%d%d",&x,&y,&z);
			if(dis[x][y]>z)
				dis[x][y]=dis[y][x]=map[x][y]=map[y][x]=z;
		}
		y=INF;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<k;i++)
				for(j=i+1;j<k;j++)
					if(y>map[k][j]+map[i][k]+dis[i][j])
					{
						y=map[k][j]+map[i][k]+dis[i][j];
						t=0;
						out(i,j);
						path[++t]=j;
						path[++t]=k;
					}
			for(i=1;i<n;i++)
				for(j=i+1;j<=n;j++)
					if(dis[i][k]+dis[k][j]<dis[i][j])
					{
						dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
						mark[i][j]=mark[j][i]=k;
					}
		}
		//printf("%d\n",y);
		if(y==INF)
			printf("No solution.\n");
		else
		{
			for(i=1;i<t;i++)
				printf("%d ",path[i]);
			printf("%d\n",path[t]);
		}
		scanf("%d",&n);
	}
	return 0;
}
