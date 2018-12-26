#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=1010000,INF=1000000007;

int color[MAXN*6];
int m,n,ans[101],top;

void cover(int u,int ll,int rr,int l,int r,int p)
{
    int mid=(ll+rr)/2;
    if(ll>rr)
        return;
    if(color[u]==p)
        return;
    if(ll>=l && rr<=r)
    {
        color[u]=p;
    //cout<<u<<" "<<ll<<" "<<rr<<" "<<l<<" "<<r<<" "<<p<<"     "<<color[u]<<endl;
        return;
    }
    if(color[u]!=0)
    {
        color[u*2]=color[u*2+1]=color[u];
        color[u]=0;
    }
    if(l<=mid)
        cover(u*2,ll,mid,l,r,p);
    if(r>mid)
        cover(u*2+1,mid+1,rr,l,r,p);
   // color[u]=color[u*2]|color[u*2+1];
  //  cout<<u<<" "<<ll<<" "<<rr<<" "<<l<<" "<<r<<" "<<p<<"     "<<color[u]<<endl;
    return;
}

int quiry(int u,int ll,int rr,int l,int r)
{
    int mid=(ll+rr)/2;
    int k=0;
   // cout<<"eeeeeeee   "<<u<<" "<<ll<<" "<<rr<<" "<<l<<" "<<r<<" "<<"     "<<color[u]<<endl;
    if(ll>rr)
        return 0;
    if(color[u])
        return (1<<(color[u]));
    if(l<=mid)
        k=k|quiry(u*2,ll,mid,l,r);
    if(r>mid)
        k=k|quiry(u*2+1,mid+1,rr,l,r);
    return k;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t,cas=0;
    //scanf("%d",&t);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        char op;
        int l,r,k;
        if(m==0 && n==0)
            break;
       // build(1,1,n,2);
        color[1]=2;
        for(int i=1;i<=m;i++)
        {
            getchar();
            scanf("%c",&op);
            //cout<<op<<endl;
            if(op=='P')
            {
                scanf("%d%d%d",&l,&r,&k);
                cover(1,1,n,l,r,k);
            }
            if(op=='Q')
            {
                scanf("%d%d",&l,&r);
                k=quiry(1,1,n,l,r);
                top=0;
                for(int j=1;j<=30;j++)
                    if((k&(1<<j))!=0)
                        ans[++top]=j;
                for(int j=1;j<top;j++)
                    printf("%d ",ans[j]);
                printf("%d\n",ans[top]);
            }
        }
    }
    return 0;
}