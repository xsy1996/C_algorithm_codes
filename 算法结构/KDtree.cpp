#include <cstdio>
#include <algorithm>
#include <queue>

#define N 50005
#define INF 21390627567143.0

using namespace std;

const int orzSYC=1;

struct node
{
    int d[5],max[15],min[15],l,r,id;
    node() 
    {
        l=0;r=0;id=0;
    }
}a[N*4],aa[N];

int n,m,Q,i,j,t,x[15],D,temp[21],root,flag,ans;

int cmp(node a,node b)
{
    return a.d[D]<b.d[D];
}


int build(int l,int r,int dd)
{
    D=dd;
    int mid=((l+r)>>1);
    nth_element(aa+l,aa+mid,aa+r+1,cmp);
    for(int i=0;i<m;i++)
        a[mid].min[i]=a[mid].max[i]=a[mid].d[i]=aa[mid].d[i];
    a[mid].id=mid;
    if(l<mid) 
        a[mid].l=build(l,mid-1,(dd+1)%m);
    else 
        a[mid].l=0;
    if(mid<r) 
        a[mid].r=build(mid+1,r,(dd+1)%m);
    else 
        a[mid].r=0;
  return mid;
}

double sdis(int k)
{
    double res=0;
    for(i=0;i<m;i++)
    {
        res+=(a[k].d[i]-x[i])*(a[k].d[i]-x[i]);
    }
    return res;
}

void ask(int k,int dem)
{
    int L=a[k].l,R=a[k].r;
    if(x[dem]>=a[k].d[dem]) 
        swap(L,R);
    double now=sdis(k);
    if(L) 
        ask(L,(dem+1)%m);
    int flag=0;
    if(sdis(k)<sdis(ans))
    {
        ans=k;
        flag=1;
    }
    if(flag&&R) 
        ask(R,(dem+1)%m);
}

int main()
{
    freopen("input.txt","r",stdin);
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=1;i<=n;i++) 
            for (j=0;j<m;j++)
                scanf("%d",&aa[i].d[j]);
        root=build(1,n,0);
        scanf("%d",&Q);
        while (Q--)
        {
            for (i=0;i<m;i++) 
                scanf("%d",&x[i]);
            ans=-1;
            ask(root,0);
            printf("the closest point are:\n");
            for(int i=0;i<m;i++)
                printf("%d ",a[ans].d[i]);
            printf("\n");
        }
    }
    return 0;
}