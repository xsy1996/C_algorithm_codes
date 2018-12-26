#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000;

long ans=INF,fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}},endx,endy,a[10],p[1001][2],path[1001][2],pt,t,b[10];
long turn[4][7]={{0,5,3,1,4,2,6},{0,3,5,2,4,1,6},{0,1,2,6,3,4,5},{0,1,2,4,5,6,3}},v[10][10][10][10][10];
void dfs(long x,long y,long s)
{
	
	long xx,yy,i,j,k,q[11];
	s+=b[a[5]];
	if(x==endx && y==endy)
	{
		if(s<ans)
		{
			pt=t;
			ans=s;
			for(i=1;i<=pt;i++)
			{
				path[i][0]=p[i][0];
				path[i][1]=p[i][1];
			}
		}
		return;
	}
	if(s>ans)
		return;
	for(i=1;i<=6;i++)
		q[i]=a[i];
	for(i=0;i<4;i++)
	{
		xx=x+fx[i][0];
		yy=y+fx[i][1];
		for(j=1;j<=6;j++)
			a[j]=q[turn[i][j]];
		if(xx<1 || xx>8 || yy<1 || yy>8 || (v[xx][yy][a[1]][a[3]][a[4]]!=0 && v[xx][yy][a[1]][a[3]][a[4]]<=s))
			continue;
		p[t+1][0]=xx;
		p[t+1][1]=yy;
		t++;
		v[xx][yy][a[1]][a[3]][a[4]]=s;
		dfs(xx,yy,s);
		t--;
	}
	return;
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,x,y;
	char c;
	scanf("%c%d",&c,&y);
	x=c-'a'+1;
	getchar();
	scanf("%c%d",&c,&endy);
	endx=c-'a'+1;
	scanf("%d%d%d%d%d%d",&b[1],&b[2],&b[3],&b[4],&b[5],&b[6]);
	for(i=1;i<=6;i++)
		a[i]=i;
	t=1;
	p[1][0]=x;
	p[1][1]=y;
	v[x][y][1][3][4]=1;
	dfs(x,y,1);
	printf("%d",ans-1);
	for(i=1;i<=pt;i++)
		printf(" %c%d",path[i][0]+'a'-1,path[i][1]);
	printf("\n");
	return 0;
}
