#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int s[2][3],circle[500001],map[2][5][5],n,flag,m;

void dfs(int x,int y)
{
	if(flag==1)
		return;
	if(y>n)
	{
		x++;
		y=x+1;
	}
	if(x==n)
	{
		int ss[2][3],same=1;
		memset(ss,0,sizeof(ss));
		for(int z=0;z<=1;z++)
			for(int i=0;i<=2;i++)
				ss[z][i]=0;
		for(int z=0;z<=1;z++)
		{
			for(int i=1;i<=n;i++)
			{
				int k=0;
				for(int j=1;j<=n;j++)
					k+=map[z][i][j];
				if(k>2)
					same=0;
				else
					ss[z][k]++;
			}
			for(int i=0;i<=2;i++)
				if(s[z][i]!=ss[z][i])
					same=0;
		}
		if(same==1)
		{
			flag=1;
			for(int z=0;z<=1;z++)
				for(int i=1;i<=n;i++)
					for(int j=i+1;j<=n;j++)
						if(map[z][i][j]!=0)
							printf("%d %d %d\n",i,j,z);
		}
		return;
	}
	dfs(x,y+1);
	map[0][x][y]=map[0][y][x]=1;
	dfs(x,y+1);
	map[0][x][y]=map[0][y][x]=0;
	map[1][x][y]=map[1][y][x]=1;
	dfs(x,y+1);
	map[1][x][y]=map[1][y][x]=0;
	return;
}

void construct(int color)
{
	if(s[color][1]==0)
	{
		for(int i=1;i<s[color][2];i++)
			printf("%d %d %d\n",circle[i],circle[i+1],color);
		printf("%d %d %d\n",circle[1],circle[s[color][2]],color);
	}
	else
	{
		for(int i=1;i<=s[color][2]+1;i++)
			printf("%d %d %d\n",circle[i],circle[i+1],color);
		for(int i=s[color][2]+3;i<s[color][2]+s[color][1];i+=2)
			printf("%d %d %d\n",circle[i],circle[i+1],color);
	}
	return;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s[0][0]>>s[0][1]>>s[0][2]>>s[1][0]>>s[1][1]>>s[1][2];
		if(s[1][1]%2==1 || s[0][1]%2==1)
		{
			cout<<(-1)<<endl;
			continue;
		}
		n=s[0][0]+s[0][1]+s[0][2];
		m=s[0][2]+s[1][2]+(s[1][1]+s[0][1])/2;
		printf("%d\n",m);
		if(n<=4)
		{
			memset(map,0,sizeof(map));
   			flag=0;
   			dfs(1,2);
		}
		else
		{
			for(int i=1;i<=n;i++)
				circle[i]=i;
			construct(0);
			int k=0;
			for(int i=1;i<=n;i+=2)
				circle[++k]=i;
			for(int i=2;i<=n;i+=2)
				circle[++k]=i;
			construct(1);
		}
	}
	return 0;
}