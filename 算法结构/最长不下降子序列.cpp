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
#define lowbit(x) ((x)&((x)^((x)-1)))

using namespace std;

const int MAXN=110000,INF=1000000007,MOD=1000000007,KIND=26;
 
int n,m,id;
int Num[MAXN],F1[MAXN],F3[MAXN],Len,Len3,ans;

int Search1(int l,int r,int item)
{
    if(l==r)return l;
    int mid=(l+r)/2;
    if(item<=F1[mid])return Search1(l,mid,item);
    if(item<=F1[mid+1])return mid;
    return Search1(mid+1,r,item);
}

int Search3(int l,int r,int item)
{
    if(l==r)return l;
    int mid=(l+r)/2;
    if(item<=F3[mid])return Search3(l,mid,item);
    if(item<=F3[mid+1])return mid;
    return Search3(mid+1,r,item);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cas=0;
    scanf("%d",&t);
    while(++cas<=t)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            F1[i]=F3[i]=INF;
        Len=0;F1[0]=-1000000007;
        Len3=0;F3[0]=-1000000007;
        for(int i=1;i<=n;i++)
            scanf("%d",&Num[i]);
        for(int i=1;i<=n;i++)
        {
            if(i<=n-m)
            {
                int id1,id2;
                id1=Search1(0,Len,Num[i+m]);
                id2=Search3(0,Len3,Num[i+m]);
                if(F3[id1+1]>Num[i+m])
                    F3[id1+1]=Num[i+m];
                F3[id2+1]=Num[i+m];
                if(id1+1>Len3)
                    Len3=id1+1;
                if(id2+1>Len3)
                    Len3=id2+1;
            }
            if(i==m-n)
                ans=Len;
            id=Search1(0,Len,Num[i]);
            F1[id+1]=Num[i];
            if(id>=Len)Len++;
        }
        ans=max(ans,Len3);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}