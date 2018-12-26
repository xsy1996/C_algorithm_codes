#include<cstdio>
#include<cstring>
#include<algorithm>

const long INF=100000000;

long a[10],a1,b[5],v[100001],kind[10001],last[10001],next[10001],t,n;

long count()
{
	long i,j,k,min=INF;
	for(i=1;i<=4;i++)
	{
		k=0;
		for(j=0;j<4;j++)
			k=k*10+b[(i+j-1)%4+1];
		if(k<min)
			min=k;
	}
	return min;
}

void turn()
{
	if(a1==1)
	{
		b[1]=a[3];b[2]=a[4];b[3]=a[5];b[4]=a[6];
	}
	if(a1==2)
	{
		b[1]=a[6];b[2]=a[5];b[3]=a[4];b[4]=a[3];
	}	
	if(a1==3)
	{
		b[1]=a[2];b[2]=a[4];b[3]=a[1];b[4]=a[6];
	}	
	if(a1==4)
	{
		b[1]=a[1];b[2]=a[3];b[3]=a[2];b[4]=a[5];
	}	
	if(a1==5)
	{
		b[1]=a[4];b[2]=a[2];b[3]=a[6];b[4]=a[1];
	}	
	if(a1==6)
	{
		b[1]=a[5];b[2]=a[2];b[3]=a[3];b[4]=a[1];
	}	
	return;
}

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		last[i]=i;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=6;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]==1)
				a1=j;
		}
		turn();
		k=count();
		//printf("%d\n",k);
		if(v[k]==0)
		{
			v[k]=i;
			t++;
			kind[t]=i;
		}
		else
		{
			next[last[v[k]]]=i;
			last[v[k]]=i;
		}
	}
	printf("%d\n",t);
	for(i=1;i<=t;i++)
	{
		k=kind[i];
		printf("%d",k);
		k=next[k];
		while(k!=0)
		{
			printf(" %d",k);
			k=next[k];
		}
		printf("\n");
	}
	return 0;
}
