#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

const long MAXn=10100,INF=1000000000;
 
long n,a[101],v[201],ans;
 
bool yes(long x,long y,long z)
{
	long i,j,k;
	for(i=1;i<=n;i++)
		if( (i!=x && (a[i]+i==a[x]+x || a[i]+n-i==a[x]+n-x)) ||
		    (i!=y && (a[i]+i==a[y]+y || a[i]+n-i==a[y]+n-y)) ||
		    (i!=z && (a[i]+i==a[z]+z || a[i]+n-i==a[z]+n-z)) )
			return 0;
	return 1;
}
 
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	long i,j,k,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			for(k=j+1;k<=n;k++)
			{
				x=a[i];
				a[i]=a[j];
				a[j]=a[k];
				a[k]=x;
				ans+=yes(i,j,k);
				x=a[i];
				a[i]=a[j];
				a[j]=a[k];
				a[k]=x;
				ans+=yes(i,j,k);
				x=a[i];
				a[i]=a[j];
				a[j]=a[k];
				a[k]=x;
			}
	printf("%d\n",ans);
	return 0;
}