#include<stdio.h>
long a[200001],f[200001],t=0;
void find(long l,long r,long x)
{
    if(r==0)
    {
        f[1]=x;
        return;
    }
    if(r<l)
    {
        f[r]=x;
        return;
    }    
    if(l==r || (x>f[(l+r)/2-1] && x<=f[(l+r)/2]))
    {
        f[(l+r)/2]=x;
        return;
    }
    else if(x>f[(l+r)/2])
        find((l+r)/2+1,r,x);
    else 
        find(l,(l+r)/2-1,x);
    return;
}
int main()
{
    freopen("LIS.in","r",stdin);
    freopen("LIS.out","w",stdout);
    long i,j,n,k,ans;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<k;i++)
        if(a[i]<a[k])
        {
            if(a[i]>f[t])
            {
                t++;
                f[t]=a[i];
            }
            else
                find(1,t,a[i]);
        }
    t++;
    ans=t;
    for(i=0;i<=t;i++)
        f[i]=0;
    t=0;
    for(i=k+1;i<=n;i++)
        if(a[i]>a[k])
        {
            if(a[i]>f[t])
            {
                t++;
                f[t]=a[i];
            }
            else if(a[i]!=f[t])
                find(1,t,a[i]);
        }
    ans+=t;
    printf("%d\n",ans);
    return 0;
}
