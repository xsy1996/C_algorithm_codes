#include<cstdio>
#include<cstring>
#include<algorithm>

const long MAXn=100001;

long n,m,f[MAXn],dis[MAXn],l[MAXn],r[MAXn],mark[MAXn][2],num[MAXn],t;
bool flag,odd[MAXn];
char a[10001];

long father(long x)
{
	long fx;
	if(f[x]!=x)
	{
		fx=f[x];
		f[x]=father(f[x]);
		dis[x]=(dis[x]+dis[fx])%2;
	}	
	return f[x];
}

void qsort(long l,long r)
{
	long i,j,k,x;
	x=num[(l+r)/2];
	i=l;j=r;
	while(i<=j)
	{
		while(num[i]<x)i++;
		while(num[j]>x)j--;
		if(i<=j)
		{
			k=num[i];
			num[i]=num[j];
			num[j]=k;
			k=mark[i][0];
			mark[i][0]=mark[j][0];
			mark[j][0]=k;
			k=mark[i][1];
			mark[i][1]=mark[j][1];
			mark[j][1]=k;
			i++;
			j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
	return;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,x,y,fx,fy;
	scanf("%d",&n);
	while(n!=-1)
	{
		flag=0;
		scanf("%d",&m);
		t=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&num[t+1],&num[t+2]);
			num[t+1]--;
			mark[t+1][0]=0;
			mark[t+1][1]=i;
			mark[t+2][0]=1;
			mark[t+2][1]=i;
			t+=2;
			scanf("%s",a);
			if(a[0]=='e')
				odd[i]=0;
			else
				odd[i]=1;
		}
		qsort(1,t);
		j=0;
		num[0]=-111111;
		for(i=1;i<=t;i++)
		{
			if(num[i]!=num[i-1])
				j++;
			if(mark[i][0]==0)
				l[mark[i][1]]=j;
			else
				r[mark[i][1]]=j;
		}
		for(i=0;i<=j+1;i++)
		{	
			f[i]=i;
			dis[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			fx=father(l[i]);
			fy=father(r[i]);
			if(fx==fy)
			{
				if(((!odd[i]) && (dis[l[i]]^dis[r[i]])) || (odd[i] && (!(dis[l[i]]^dis[r[i]]))))
					break;
				continue;
			}
			dis[fy]=(dis[l[i]]+dis[r[i]]+odd[i])%2;
			f[fy]=fx;
			}
		printf("%d\n",i-1);
		scanf("%d",&n);
	}
	return 0;
}
