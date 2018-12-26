/*
ID:xsy19962
TASK:nocows 
LANG:C++
*/
#include<stdio.h>
long s[201][101],n,m;
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	long i,j,k;	
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=m;i++)
		s[1][i]=1;
	for(i=3;i<=n;i++)
		for(k=2;k<=m;k++)
			for(j=1;j<=i-2;j++)
			{
				s[i][k]+=s[j][k-1]*s[i-j-1][k-1];
				s[i][k]%=9901;
			}
	/*for(i=1;i<=n;i++)
		for(k=1;k<=m;k++)
			printf("%ld %ld %ld\n",i,k,s[i][k]);*/
	printf("%ld\n",(s[n][m]-s[n][m-1]+9901)%9901);
	return 0;
}
