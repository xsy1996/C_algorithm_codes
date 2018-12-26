#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=2100,INF=1000000007;

struct L
{
    int to,next;
}line[210000];

int n,Begin[MAXN*2],l_sum=0;
int dfn[MAXN*2],low[MAXN*2],counter=0,stack[MAXN*2],top=0;
bool visit[MAXN*2];
int p[MAXN*2],pieces=0,ans[MAXN];

void tarjan(int x)
{
    int y,k;
    if(dfn[x]!=0)
        return;
    top++;
    stack[top]=x;
    counter++;
    dfn[x]=low[x]=counter;
    k=Begin[x];
    while(k!=-1)
    {
        y=line[k].to;
        if(visit[y]==0)
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        k=line[k].next;
    }
    if(dfn[x]==low[x])
    {
        pieces++;
        k=0;
        p[x]=pieces;
        visit[x]=1;
     //   printf("       %d ",x);
        while(stack[top]!=x)
        {
            y=stack[top];
    //    printf("%d ",y);
            visit[y]=1;
            p[y]=pieces;
            top--;
        }
        top--;
    //    printf("\n");
    }
    return;
}

int main ()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int k,x;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        Begin[i]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&x);
            l_sum++;
            line[l_sum].to=x;
            line[l_sum].next=Begin[i+n];
            Begin[i+n]=l_sum;
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        l_sum++;
        line[l_sum].to=i+n;
        line[l_sum].next=Begin[x];
        Begin[x]=l_sum;
    }
    for(int i=n+1;i<=2*n;i++)
        if(dfn[i]==0)
            tarjan(i); 
   // for(int i=1;i<=2*n;i++)
     //   cout<<"num : "<<i<<"  dfn : "<<dfn[i]<<"  low : "<<low[i]<<endl;  
    for(int i=1;i<=n;i++)
    {
        int temp=0,y;
        x=i+n;
        k=Begin[i+n];
        while(k!=-1)
        {
            y=line[k].to;
            if(p[y]==p[x])
                ans[++temp]=y;
            k=line[k].next;
        }
        sort(ans+1,ans+temp+1);
        printf("%d ",temp);
        for(int j=1;j<temp;j++)
            printf("%d ",ans[j]);
        printf("%d\n",ans[temp]);
    }
    return 0;
}