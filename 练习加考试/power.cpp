#include<stdio.h>
long n,ans,f,l,v[101][50001],dmin[5000001],dmax[5000001],t[5000001];
long min(long a,long b)
{
    if(a<b)
        return a;
    return b;
}
long max(long a,long b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long i,j,k,a[10];
    scanf("%d",&n);
    f=0;l=1;
    dmin[1]=0;
    dmax[1]=1;
    v[0][1]=1;
    while(f<l)
    {
        f++;
        if(dmin[f]==n || dmax[f]==n)
        {
            ans=t[f];
            break;
        }
        a[1]=dmin[f]*2;
        a[2]=dmin[f]+dmax[f];
        a[3]=dmax[f]*2;
        a[4]=dmax[f]-dmin[f];
        for(i=1;i<=4;i++)    
            if(max(dmin[f],a[i])<=50000 && min(dmin[f],a[i])<=100 && v[min(dmin[f],a[i])][max(dmin[f],a[i])]==0)
            {
                v[min(dmin[f],a[i])][max(dmin[f],a[i])]=1;
                l++;
                dmin[l]=min(dmin[f],a[i]);
                dmax[l]=max(dmin[f],a[i]);
                t[l]=t[f]+1;
            }
        for(i=1;i<=4;i++)    
            if(max(dmax[f],a[i])<=50000 && min(dmax[f],a[i])<=100 && v[min(dmax[f],a[i])][max(dmax[f],a[i])]==0)
            {
                v[min(dmax[f],a[i])][max(dmax[f],a[i])]=1;
                l++;
                dmin[l]=min(dmax[f],a[i]);
                dmax[l]=max(dmax[f],a[i]);
                t[l]=t[f]+1;
            }
    }
    printf("%d\n",ans);
    return 0;
}
