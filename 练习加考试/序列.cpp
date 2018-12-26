#include<cstdio>
#include<cstring>
#include<algorithm>

const long MAXn=500001,INF=1000000000;

long n,l[MAXn],r[MAXn],hpl[MAXn*5],hpr[MAXn*5],rl[MAXn*5],top=0,rr[MAXn*5],s,t,max=0;

void addl(long x,long y)
{
	if(x==1 || l[y]<l[hpl[x/2]])
	{
		hpl[x]=y;
		rl[y]=x;
		return;
	}
	hpl[x]=hpl[x/2];
	rl[hpl[x]]=x;
	addl(x/2,y);
	return;
}

void addr(long x,long y)
{
	if(x==1 || r[y]>r[hpr[x/2]])
	{
		hpr[x]=y;
		rr[y]=x;
		return;
	}
	hpr[x]=hpr[x/2];
	rr[hpr[x]]=x;
	addr(x/2,y);
	return;
}

void dell(long x)
{
	long i,j,k,q;
	k=x;
	if(x*2<=top && l[hpl[x*2]]>l[hpl[k]])
		k=x*2;
	if(x*2+1<=top && l[hpl[x*2+1]]>l[hpl[k]])
		k=x*2+1;
	if(l[hpl[k]]>l[hpl[x]])
	{
		q=hpl[k];
		hpl[k]=hpl[x];
		hpl[x]=q;
		rl[hpl[x]]=x;
		rl[hpl[k]]=k;
		dell(k);
	}
	return;
}

void delr(long x)
{
	long i,j,k,q;
	k=x;
	if(x*2<=top && r[hpr[x*2]]<r[hpr[k]])
		k=x*2;
	if(x*2+1<=top && r[hpr[x*2+1]]<r[hpr[k]])
		k=x*2+1;
	if(r[hpr[k]]<r[hpr[x]])
	{
		q=hpr[k];
		hpr[k]=hpr[x];
		hpr[x]=q;
		rr[hpr[x]]=x;
		rr[hpr[k]]=k;
		delr(k);
	}
	return;
}

int main()
{
	long i,j,k;
	scanf("%d",&n);
	k=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&l[i],&r[i]);
		top++;
		addl(top,i);
		addr(top,i);
		while(l[hpl[1]]>r[i])
		{
			j=k;
			k=hpl[1]+1;
			for(;j<k;++j)
			{
				l[j]=0;
				dell(rl[j]);
				r[j]=INF;
				delr(rr[j]);
			}
		}
		while(r[hpr[1]]<l[i])
		{
			j=k;
			k=hpr[1]+1;
			for(;j<k;++j)
			{
				l[j]=0;
				dell(rl[j]);
				r[j]=INF;
				delr(rr[j]);
			}
		}
		if(i-k+1>max)
		{
			max=i-k+1;
			s=k;t=i;
		}
	}
	printf("%d %d\n",s,t);
	return 0;
}