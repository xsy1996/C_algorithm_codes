#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define lowbit(k) ((k)&(-k))
#define abs(k) (((k)>=0)?(k):(-k))

const long MAXn=201000,INF=1000000000,mod=10000;

long head[MAXn],next[MAXn<<1],end[MAXn<<1],c[MAXn<<1],ne;
long n,anc[20][MAXn],f[20][MAXn],q[MAXn],d[MAXn],fa[MAXn];

using std :: sort;
using std :: swap;

struct edge
{
	long u,v,c;
}e[MAXn<<1];

long operator < (edge a,edge b)
{
	return (a.c<b.c);
}

long find(long x)
{
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}

void add(long a,long b,long cc)
{
	end[++ne]=b;
	c[ne]=cc;
	next[ne]=head[a];
	head[a]=ne;
	return;
}

void prepare()
{
	long i,j,k,h=0,t=1,u;
	for(q[1]=1;h<t;)
	{
		u=q[++h];
		for(i=head[u];i;i=next[i])
			if(anc[0][u]!=end[i])
			{	
				j=end[i];
				anc[0][j]=u;
				f[0][j]=c[i];
				d[j]=d[u]+1;
				q[++t]=j;
			}
	}
	for(i=1;i<=18;i++)
		for(j=1;j<=n;j++)
		{
			anc[i][j]=anc[i-1][anc[i-1][j]];
			f[i][j]=max(f[i-1][j],f[i-1][anc[i-1][j]]);
		}
	return;
}

long ask(long a,long b)
{
	long i,ans=0;
	if(d[a]<d[b])
		swap(a,b);
	for(i=18;i>=0;i--)
		if(d[a]-d[b]>=(1<<i))
		{
			ans=max(ans,f[i][a]);
			a=anc[i][a];
		}
	for(i=18;i>=0;i--)
		if(anc[i][a]!=anc[i][b])
		{
			ans=max(ans,max(f[i][a],f[i][b]));
			a=anc[i][a],b=anc[i][b];
		}
	if(a!=b)
		ans=max(ans,max(f[0][a],f[0][b]));
	return ans;
}

int main()
{
	freopen("Journey.in","r",stdin);
	freopen("Journey.out","w",stdout);
	long m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
		if(find(e[i].u)!=find(e[i].v))
		{
			add(e[i].u,e[i].v,e[i].c);
			add(e[i].v,e[i].u,e[i].c);
			fa[find(e[i].u)]=find(e[i].v);
		}
	prepare();
	scanf("%d",&m);
	for(;m--;)
	{
		scanf("%d%d",&i,&j);
		printf("%d\n",ask(i,j));
	}
	return 0;
}