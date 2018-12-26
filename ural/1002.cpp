#include<cstdio>
#include<cstring>
#include<algorithm>

long react[26]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
long n,m,mark[1001],from[1001],choose[1001];
char word[50001][101],len[50001],a[1001];

bool cmp(long x,long y)
{
	long i,j,k;
	if(x+len[y]>n)
		return 0;
	for(i=1;i<=len[y];i++)
		if(react[word[y][i]-'a']!=a[x+i]-'0')
			return 0;
	return 1;
}

void out(long k)
{
	long i,j;
	if(k==0)
		return;
	out(from[k]);
	printf("%s ",word[choose[k]]+1);
	return;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long i,j,k;
	while(1)
	{
		scanf("%s",a+1);
		if(a[1]=='-')
			return 0;
		n=strlen(a+1);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%s",word[i]+1);
			len[i]=strlen(word[i]+1);
		}
		memset(mark,0,sizeof(mark));
		mark[0]=1;
		for(i=0;i<=n;i++)
			for(j=1;j<=m;j++)
				if(mark[i]>0 && i+len[j]<=n && (mark[i+len[j]]>mark[i]+1 || mark[i+len[j]]==0) && cmp(i,j))
				{
					mark[i+len[j]]=mark[i]+1;
					choose[i+len[j]]=j;
					from[i+len[j]]=i;
				//	printf("%d %d %d %d\n",i+len[j],mark[i+len[j]],choose[i+len[j]],from[i+len[j]]);
				}
		if(mark[n]==0)
			printf("No solution.\n");
		else
		{
			out(n);
			printf("\n");
		}
	}
}
