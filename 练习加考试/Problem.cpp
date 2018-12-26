#include<stdio.h>
long a[300001],s[300001],t,ans=1,n,m;
long find(long l,long r,long x)
{
    long i,j,k;
    k=(l+r)/2;
    if(s[k]>=x && s[k-1]<x)
        return k;
    else if(s[k-1]>=x)
        return find(l,k-1,x);
    else
        return find(k+1,r,x);
}
int main()
{
    freopen("Problem.in","r",stdin);
    freopen("Problem.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    t=0;
    s[0]=-32767;
    for(i=1;i<m;i++)
        if(a[i]<a[m])
        {
            if(a[i]>s[t])
            {
                t++;
                s[t]=a[i];
            }
            else
                s[find(1,t,a[i])]=a[i];
        }
    ans+=t;
    t=0;
    s[0]=-32767;
    for(i=m+1;i<=n;i++)
        if(a[i]>a[m])
        {
            if(a[i]>s[t])
            {
                t++;
                s[t]=a[i];
            }
            else
                s[find(1,t,a[i])]=a[i];
        }
    ans+=t;
    printf("%d\n",ans);
    return 0;
}
