/*
ID:xsy19962
TASK:combo
LANG:C++
*/
#include<stdio.h>

int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int i,j,k;
	int n,a[4],b[4],rep=1,flag=0;
	scanf("%d",&n);
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	scanf("%d%d%d",&b[1],&b[2],&b[3]);
	if(n<=5)
	{
		printf("%d\n",n*n*n);
		return 0;
	}
	for(i=1;i<=3;i++)
		if(a[i]>b[i])
			k=a[i],a[i]=b[i],b[i]=k;
	for(i=1;i<=3;i++)
	{
		if(b[i]-a[i]<5)
			rep*=a[i]-b[i]+5,flag=1;
		if(a[i]-b[i]+n<5)
			rep*=b[i]-a[i]-n+5,flag=1;
	}
	if(flag)
		printf("%d\n",250-rep);
	else
		printf("250\n");
	return 0;
}