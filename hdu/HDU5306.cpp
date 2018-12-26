#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int mark,color,max,sum;
};

int a[1000011];

int main()
{
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(mark,1,sizeof(mark));
		for(int i=1;i<=m;i++)
			scanf
	}
	return 0;
}