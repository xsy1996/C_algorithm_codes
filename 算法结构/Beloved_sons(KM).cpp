#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=1000,INF=1000000007;

struct edge
{
    int to,next,value;
}L[MAXN*MAXN+MAXN];

int n,ls,x[MAXN],y[MAXN*2],Begin[MAXN],choose[MAXN*2],ans[MAXN],slack[MAXN*2];
bool visitx[MAXN],visity[MAXN*2];

bool match(int u)
{
    int v,k,value;
    if(visitx[u])
        return 0;
    visitx[u]=1;
    k=Begin[u];
    while(k!=-1)
    {
        v=L[k].to;
        value=L[k].value;
        k=L[k].next;
        if(visity[v])
            continue;
        if(value==x[u]+y[v])
        {
            visity[v]=1;
            if(choose[v]==0 || match(choose[v]))
            {
                choose[v]=u;
                return 1;
            }
        }
        else if(x[u]+y[v]-value<slack[v])
            slack[v]=x[u]+y[v]-value;
    }
    return 0;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t,cas=0;
    //scanf("%d",&t);
    while(scanf("%d",&n)!=EOF)
    {
        int k,u,v;
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)
            Begin[i]=-1;
        ls=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
            {
                scanf("%d\n",&v);
                ls++;
                L[ls].to=v;
                L[ls].value=x[i];
                L[ls].next=Begin[i];
                Begin[i]=ls;
            }
            ++ls;
            L[ls].to=i+n;
            L[ls].value=0;
            L[ls].next=Begin[i];
            Begin[i]=ls;
        }
        memset(choose,0,sizeof(choose));
        memset(y,0,sizeof(y));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n;j++)
                slack[j]=INF;
            while(1)
            {
                memset(visitx,0,sizeof(visitx));
                memset(visity,0,sizeof(visity));
                if(match(i))
                    break;
                int min=INF;
                for(int j=1;j<=2*n;j++)
                    if(!visity[j] && slack[j]<min)
                        min=slack[j];
                for(int j=1;j<=n;j++)
                    if(visitx[j])
                        x[j]-=min;
                for(int j=1;j<=2*n;j++)
                {    
                    if(visity[j])
                        y[j]+=min; 
                    else
                        slack[j]-=min;
                }
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            ans[choose[i]]=i;
        for(int i=1;i<n;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}