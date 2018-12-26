#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=1100,INF=1000000007;

double a[11][MAXN],map[11][11];

int n,m,choose[11];
bool visitx[11],visity[11];

double x[11],y[11],slack[11],ans;

bool match(int u)
{
    int v,k;
    double value;
    if(visitx[u])
        return 0;
    visitx[u]=1;
    for(int v=1;v<=n;v++)
    {
        value=map[u][v];
        if(visity[v])
            continue;
        if(value>=x[u]+y[v]-0.00000001 && value<=x[u]+y[v]+0.00000001)
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

void KM()
{
    for(int i=1;i<=n;i++)
        choose[i]=x[i]=y[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(map[i][j]>x[i])
                x[i]=map[i][j];
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                slack[j]=2;
            while(1)
            {
                memset(visitx,0,sizeof(visitx));
                memset(visity,0,sizeof(visity));
                if(match(i))
                    break;
                double min=2;
                for(int j=1;j<=n;j++)
                    if(!visity[j] && slack[j]<min)
                        min=slack[j];
                for(int j=1;j<=n;j++)
                    if(visitx[j])
                        x[j]-=min;
                for(int j=1;j<=n;j++)
                {    
                    if(visity[j])
                        y[j]+=min; 
                    else
                        slack[j]-=min;
                }
            }
        }
    return;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t,cas=0,p;
    scanf("%d",&t);
    while(++cas<=t)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lf",&a[i][j]);
        p=0;
        ans=0;
        while(p+n<=m)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    map[i][j]=a[i][j+p];
            KM();
            for(int i=1;i<=n;i++)
            {
            //    cout<<x[i]<<"  "<<y[i]<<endl;
                ans+=x[i]+y[i];
            }
            p+=n;
        }
        if(p<m)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(j+p<=m)
                        map[i][j]=a[i][j+p];
                    else
                        map[i][j]=0;  
                }
            KM();
            for(int i=1;i<=n;i++)
            {
             //   cout<<x[i]<<"  "<<y[i]<<endl;
                ans+=x[i]+y[i];
            }
        }
        printf("Case #%d: %.5lf\n",cas,ans);
    }
    return 0;
}