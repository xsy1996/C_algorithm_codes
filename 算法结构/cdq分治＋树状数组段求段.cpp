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

const int MAXN=101001,INF=1000000007,MOD=1000007,KIND=4;

struct question
{
    int type,l,r,k,pos;   
}*q[MAXN],*temp1[MAXN],*temp2[MAXN];

int n,m,ans[MAXN],t[MAXN],B[MAXN],C[MAXN];

void ADD_B(int x, int c)
{
     for (int i=x; i>0; i-=i&(-i)) B[i] += c;
}
void ADD_C(int x, int c)
{
     for (int i=x; i<=n; i+=i&(-i)) C[i] += x * c;
}

void ADD(int l,int r,int c)
{
    ADD_B(r, c); 
    ADD_C(r, c);
    if (l > 1) 
    {
        ADD_B(l - 1, -c); 
        ADD_C(l - 1, -c);
    }
}

int SUM_B(int x)
{
    int s = 0;
    for (int i=x; i<=n; i+=i&(-i)) s += B[i];
    return s;
}
int SUM_C(int x)
{
    int s = 0;
    for (int i=x; i>0; i-=i&(-i)) s += C[i];
    return s;
}

int SUM(int x)
{
    if (x) return SUM_B(x) * x + SUM_C(x - 1); else return 0;
}

void DaC(int l,int r,int fi,int la)
{
    int mid=(l+r)/2,p1=0,p2=0;
    if(fi>la)
        return;
    if(l==r)
    {
        for(int i=fi;i<=la;i++)
            ans[q[i]->pos]=l;
        return;
    }
    for(int i=fi;i<=la;i++)
        if(q[i]->type==2)
        {
            int k=SUM(q[i]->r)-SUM(q[i]->l-1);
            if(k<q[i]->k)
            {
                temp2[++p2]=q[i];
                q[i]->k-=k;
            }
            else
                temp1[++p1]=q[i];
        }
        else
        {
            if(q[i]->k<=mid)
            {
                temp1[++p1]=q[i];
                ADD(q[i]->l,q[i]->r,1);
            }
            else
                temp2[++p2]=q[i];
        }
    for(int i=fi;i<=la;i++)
        if(q[i]->type==1 && q[i]->k<=mid)
            ADD(q[i]->l,q[i]->r,-1);
    for(int i=1;i<=p1;i++)
        q[fi+i-1]=temp1[i];
    for(int i=1;i<=p2;i++)
        q[fi+p1+i-1]=temp2[i];
    DaC(l,mid,fi,fi+p1-1);
    DaC(mid+1,r,fi+p1,fi+p1+p2-1);
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        q[i]=new question;
        scanf("%d%d%d%d",&(*q[i]).type,&(*q[i]).l,&(*q[i]).r,&(*q[i]).k);
        if(q[i]->type==1)
            q[i]->k=n-q[i]->k;
        else if(q[i]->type==2)    
            q[i]->pos=++k;
    }
    DaC(-n,n,1,m);
    for(int i=1;i<=k;i++)
        printf("%d\n",n-ans[i]);
    return 0;
}