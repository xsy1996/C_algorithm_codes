#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=1000000000,MAXn=10101;

long q[MAXn],num[MAXn],mark[MAXn],t=0,print[MAXn][3],react[MAXn],n,ans=0,ansf,ansl;
bool v[MAXn];

void qsort(long l,long r)
{
	long i,j,k,x;
	x=q[(l+r)/2];
	i=l;j=r;
	while(i<=j)
	{
		while(q[i]<x)i++;
		while(q[j]>x)j--;
		if(i<=j)
		{
			k=q[i];q[i]=q[j];q[j]=k;
			k=num[i];num[i]=num[j];num[j]=k;
			k=mark[i];mark[i]=mark[j];mark[j]=k;
			i++;j--;
		}
	}
	if(i<r)qsort(i,r);
	if(l<j)qsort(l,j);
	return;
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k,f,l;
	char c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t++;
		scanf("%d",&q[t]);
		mark[t]=0;
		num[t]=i;
		t++;
		scanf("%d",&q[t]);
		mark[t]=1;
		num[t]=i;
		getchar();
		scanf("%c",&c);
		if(c=='b')
			print[i][2]=1;
		else
			print[i][2]=0;
	}
	qsort(1,t);
	k=0;
	q[0]=-1;
	react[0]=0;
	for(i=1;i<=t;i++)
	{
		if(q[i]!=q[i-1])
		{
			k++;
			react[k]=q[i];
		}
		print[num[i]][mark[i]]=k;
	}
	k++;
	react[k]=INF;
	for(i=1;i<=n;i++)
		for(j=print[i][0];j<print[i][1];j++)
			v[j]=print[i][2];
	
	for(i=0;i<=k;i++)
		if(v[i]==0)
		{
			f=i;
			l=f;
			while(v[l]==0 && l<k)
				l++;
			if(react[l]-react[f]>ans)
			{
				ans=react[l]-react[f];
				ansf=react[f];
				ansl=react[l];
			}
			i=l;
		}
	printf("%d %d\n",ansf,ansl);
	return 0;
}
