/*
ID:xsy19962
TASK:rect1
LANG:C++
*/
#include<stdio.h>
long a[2010][6010],l[6010],r[6010],x[2010],y[2010],x1[2010],y1[2010],x2[2010],y2[2010],mx[10010],my[10010],n,c[2010],maxx,maxy,ans[3001];
void q(long s,long ll,long rr)
{
    long i,j,k;
    l[s]=ll;
    r[s]=rr;
    if(ll+1<rr)
    {
        q(2*s,ll,(ll+rr)/2);
        q(2*s+1,(ll+rr)/2,rr);
    }
    return;
}
void paint(long t,long s,long ll,long rr,long cc)
{
    long i,j,k;
    if(ll==l[s] && rr==r[s])
    {
        a[t][s]=cc;
        return;
    }
    else if(ll>=l[s] && rr<=r[s] && a[t][s]==cc)
        return;
    else
    {
        if(a[t][s]!=0)
        {
            a[t][s*2]=a[t][s];
            a[t][s*2+1]=a[t][s];
            a[t][s]=0;
        }
        if(ll<(l[s]+r[s])/2 && rr>(l[s]+r[s])/2)
        {
            paint(t,s*2,ll,(l[s]+r[s])/2,cc);
            paint(t,2*s+1,(l[s]+r[s])/2,rr,cc);
        }
        else if(ll>=(l[s]+r[s])/2)
            paint(t,s*2+1,ll,rr,cc);
        else if(rr<=(l[s]+r[s])/2)
            paint(t,s*2,ll,rr,cc);
    }
    return;
}
void count(long t,long s)
{
    long i,j,k;
    if(a[t][s]!=0)
        ans[a[t][s]]+=(y[r[s]]-y[l[s]])*(x[t+1]-x[t]);
    else
    {
        count(t,2*s);
        count(t,2*s+1);
    }
    return;
}
int main()
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    long i,j,k;
    scanf("%ld%ld%ld",&j,&k,&n);
    mx[0]=1;mx[j]=1;my[0]=1;my[k]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&c[i]);
        mx[x1[i]]=1;mx[x2[i]]=1;my[y1[i]]=1;my[y2[i]]=1;
    }
    k=0;
    for(i=0;i<=10001;i++)
        if(mx[i]==1)
        {
            k++;
            mx[i]=k;
            x[k]=i;
        }
    maxx=k;
    k=0;
    for(i=0;i<=10001;i++)
        if(my[i]==1)
        {
            k++;
            my[i]=k;
            y[k]=i;
        }
    maxy=k;
    q(1,1,maxy);
    for(i=1;i<maxx;i++)
        a[i][1]=1;
    for(i=1;i<=n;i++)
    {
        x1[i]=mx[x1[i]];
        x2[i]=mx[x2[i]];
        y1[i]=my[y1[i]];
        y2[i]=my[y2[i]];
    }
    for(i=1;i<=n;i++)
    {
        for(j=x1[i];j<x2[i];j++)
            paint(j,1,y1[i],y2[i],c[i]);
    }
    for(i=1;i<maxx;i++)
        count(i,1);
    for(i=1;i<=2500;i++)
        if(ans[i]!=0)
            printf("%d %d\n",i,ans[i]);
    return 0;
}
