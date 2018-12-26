#include<stdio.h>
long f[1001],x[10001],y[10001],v[1001],n,m,ans;
long fa(long i)
{
    if(f[i]!=i)
        f[i]=fa(f[i]);
    return f[i];
}
long max(long a,long b)
{
    if(a>b)
        return a;
    return b;
}
long min(long a,long b)
{
    if(a<b)
        return a;
    return b;
}
long find(long a)
{
    long i,j,k=0;
    for(i=1;i<=m;i++)
        if(fa((x[i]+a)%n)!=fa((y[i]+a)%n))
        {
            for(j=min((x[i]+a)%n,(y[i]+a)%n);j<max((x[i]+a)%n,(y[i]+a)%n);j++)
                if(v[j]==0)
                {
                    v[j]=1;
                    k++;
                    f[fa(j)]=fa(j+1);
                }
        }    
    return k;
}
int main()
{
    freopen("fiber.in","r",stdin);
    freopen("fiber.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]--;
        y[i]--;
    }
    ans=n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            f[j]=j;        
            v[j]=0;
        }
        k=find(i);
        if(k<ans)
            ans=k;
    }
    printf("%d\n",ans);
    return 0;
}
