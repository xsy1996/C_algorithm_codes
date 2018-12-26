#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define Abs(a) (((a)>0)?(a):(-1*(a)))

using namespace std;

const int MAXN=11001,INF=1000000007,MOD=1000007;

int back[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	int t,lena,lenb,ans;
   	char a[MAXN],b[MAXN*100];
   	scanf("%d",&t);
   	while(t--)
   	{
   		ans=0;
   		scanf("%s",a+1);
   		scanf("%s",b+1);
   		lena=strlen(a+1);
   		lenb=strlen(b+1);
   		back[1]=0;
   		int p=0;
   		for(int i=2;i<=lena;i++)
   		{
   			while(p>0 && a[p+1]!=a[i])
   				p=back[p];
   			if(a[p+1]==a[i])
   				back[i]=++p;
   			else
   				back[i]=0;
   		}
   		p=0;
   		for(int i=1;i<=lenb;i++)
   		{
   			while(p>0 && a[p+1]!=b[i])
   				p=back[p];
   			if(a[p+1]==b[i])
   			{
   				p++;
   				if(p==lena)
   				{
   					ans++;
   					p=back[p];
   				}
   			}
   		}
         //求匹配个数
   		printf("%d\n",ans);
         //求循环节
         printf("%d\n",lena-back[lena]);
   	}
    return 0;
}