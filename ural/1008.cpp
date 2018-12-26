#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000;

long dx[101],dy[101],n,map[101][101],f,l,mx=0,my=0;
char a,mark[101];

int main()
{
	freopen("ac.out","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,x,y;
	scanf("%d%c",&n,&a);
	if(a==' ')
	{
		dx[1]=n;
		scanf("%d",&dy[1]);
		map[dx[1]][dy[1]]=1;
		mx=dx[1];
		my=dy[1];
		f=0;l=1;
		while(f<l)
		{
			f++;
			scanf("%s",mark+1);
			n=strlen(mark+1);
			for(i=1;i<n;i++)
			{
				x=dx[f];
				y=dy[f];
				if(mark[i]=='R')
					++x;
				else if(mark[i]=='T')
					++y;
				else if(mark[i]=='L')
					--x;
				else
					--y;
				if(mx<x)
					mx=x;
				if(my<y)
					my=y;
				if(map[x][y]==0)
				{
					map[x][y]=1;
					l++;
					dx[l]=x;
					dy[l]=y;
				}
			}
		}
		printf("%d\n",l);
		for(i=1;i<=mx;i++)
			for(j=1;j<=my;j++)
				if(map[i][j]==1)
					printf("%d %d\n",i,j);
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=1;
			if(mx<x)
				mx=x;
			if(my<y)
				my=y;
		}
		k=1;
		for(i=1;i<=mx && k==1;i++)
			for(j=1;j<=my;j++)
				if(map[i][j]==1)
				{
					x=i;
					y=j;
					k=0;
					break;
				}
		printf("%d %d\n",x,y);
		map[x][y]=0;
		dx[1]=x;
		dy[1]=y;
		f=0;l=1;
		while(f<l)
		{
			f++;
			x=dx[f];
			y=dy[f];
			if(map[x+1][y]==1)
			{
				printf("R");
				l++;
				dx[l]=x+1;
				dy[l]=y;
				map[x+1][y]=0;
			}
			if(map[x][y+1]==1)
			{
				printf("T");
				l++;
				dx[l]=x;
				dy[l]=y+1;
				map[x][y+1]=0;
			}
			if(map[x-1][y]==1)
			{
				printf("L");
				l++;
				dx[l]=x-1;
				dy[l]=y;
				map[x-1][y]=0;
			}
			if(map[x][y-1]==1)
			{
				printf("B");
				l++;
				dx[l]=x;
				dy[l]=y-1;
				map[x][y-1]=0;
			}
			if(f<l)
				printf(",\n");
			else
				printf(".\n");
		}
	}
	return 0;
}
