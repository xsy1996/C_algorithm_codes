/*
ID:xsy19962 
TASK:ditch
LANG:C++
*/
#include<stdio.h>
long h[1001],c[1001][1001],v[1001],queue[1000001],f,l,n,m;
long min(long x,long y)
{
    if(x>y)
        return y;
    else
        return x;
}
void push(long x)
{
    long i,k;
    for(i=1;i<=n;i++)
        if(h[i]==h[x]-1 && c[x][i]>0)
        {
            if(i!=n && i!=1 && v[i]==0)
            {
                l++;
                queue[l]=i;
            }
            k=min(c[x][i],v[x]);
            c[x][i]-=k;
            c[i][x]+=k;
            v[x]-=k;
            v[i]+=k;
            if(v[x]==0)
                break;
        } 
    return;
}
void relabel(long x)
{
    long i;
    for(i=1;i<=n;i++)
        if(c[x][i]>0 && h[i]<h[x])
            h[x]=h[i];
    h[x]++;
    return;
}
int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    long i,j,k,x,y,z;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        c[x][y]+=z;
    }
    h[1]=n-1;
    f=0;l=0;
    for(i=2;i<=n;i++)
        if(c[1][i]>0)
        {
            v[i]=c[i][1]=c[1][i];
            c[1][i]=0;
            h[i]=1;
            if(i!=n)
            {
                l++;
                queue[l]=i;
            }
        }
    while(f<l)
    {
        f++;
        relabel(queue[f]);
        push(queue[f]);
        if(v[queue[f]]>0)
        {
            l++;
            queue[l]=queue[f];
        }
    }
    printf("%d\n",v[n]);
    return 0;
}
