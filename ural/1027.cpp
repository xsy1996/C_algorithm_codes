#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>=0?(a):((a)*-1))
#define lowbit(a) ((a)&(-1*(a)))

using std :: sort;

const long INF=1000000000,MAXn=101000;

long s,flag,n;
char a[MAXn];

int main()
{ 
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	n=0;
	while(scanf("%c",&a[n])!=EOF)
		n++;
	n--;
	//printf("%s\n",a);
	for(i=0;i<=n;i++)
	{
		if(s<0)
		{
			printf("NO\n");
			return 0;
		}
		if(a[i]=='(' && a[i+1]=='*')
		{
			k=i+3;
			while((a[k-1]!='*' || a[k]!=')') && k<=n)
				k++;
			if(k>n)
			{
				printf("NO\n");
				return 0;
			}
			i=k;
			continue;
		}
		if(a[i]==')')
		{
			s--;
			continue;
		}
		if(a[i]=='(')
		{
			s++;
			continue;
		}
		if(s==0)
			continue;
		if((a[i]!='\n') && ((a[i]>'9') || (a[i]<'0')) && (a[i]!='+') && (a[i]!='-') && (a[i]!='*') && (a[i]!='/') && (a[i]!='='))
		{
			printf("NO\n");
			return 0;
		}
	}
	if(s!=0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
