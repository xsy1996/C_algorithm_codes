/*
ID:xsy19962
TASK:job
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>

long n,an,bn,a[10001],b[10001],ca[10001],cb[10001],ta[10001],tb[10001],ans;

int main()
{
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	long i,j,k;
	scanf("%d%d%d",&n,&an,&bn);
	for(i=1;i<=an;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=bn;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		ca[i]=2147483600;
		for(j=1;j<=an;j++)
			if(ta[j]+a[j]<ca[i])
			{
				ca[i]=ta[j]+a[j];
				k=j;
			}
		ta[k]+=a[k];
		cb[i]=2147483600;
		for(j=1;j<=bn;j++)
			if(tb[j]+b[j]<cb[i])
			{
				cb[i]=tb[j]+b[j];
				k=j;
			}
		tb[k]+=b[k];
	}
	printf("%d ",ca[n]);
	ans=0;
	for(i=1;i<=n;i++)
		if(ca[i]+cb[n-i+1]>ans)
			ans=ca[i]+cb[n-i+1];
	printf("%d\n",ans);
	return 0;
}