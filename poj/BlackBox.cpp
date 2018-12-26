#include<stdio.h>
long h2[50001],a[50001],h[50001],t=0,t2=0;
void hp(long x)
{
    long i,j,k;
    if(x/2==0)
        return;
    if(a[h[x/2]]<a[h[x]])
    {
        k=h[x/2];
        h[x/2]=h[x];
        h[x]=k;
        hp(x/2);    
    }
    return;
}
void hp2(long x)
{
    long i,j,k;
    if(x/2==0)
        return;
    if(a[h2[x/2]]>a[h2[x]])
    {
        k=h2[x/2];
        h2[x/2]=h2[x];
        h2[x]=k;
        hp2(x/2);    
    }
    return;
}
void gx(long x)
{
    long i,j,k=0;
    if(x*2<=t)
        k=x*2;
    if(x*2<=t && a[h[k]]<a[h[x*2+1]])
        k=2*x+1;
    if(k!=0 && a[h[x]]<a[h[k]])
    {
        j=h[k];
        h[k]=h[x];
        h[x]=j;
        gx(k);
    }
    return;
}
void gx2(long x)
{
    long i,j,k=0;
    if(x*2<=t2)
        k=x*2;
    if(x*2<=t2 && a[h2[k]]>a[h2[x*2+1]])
        k=2*x+1;
    if(k!=0 && a[h2[x]]>a[h2[k]])
    {
        j=h2[k];
        h2[k]=h2[x];
        h2[x]=j;
        gx2(k);
    }
    return;
}
void del()
{
    long i,j,k;
    t++;
    h[t]=h2[1];
    hp(t);
    h2[1]=h2[t2];
    t2--;
    gx2(1);
    return;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    long i,j,k,x,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    j=0;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        while(j<x)
        {
            j++;
            t2++;
            if(a[j]>=a[h[1]] || t==0)
                h2[t2]=j;
            else
            {
                h2[t2]=h[1];
                h[1]=j;
                gx(1);
            }
            hp2(t2);
        }
        printf("%d\n",a[h2[1]]);
        del();
    }    
    return 0;
}
