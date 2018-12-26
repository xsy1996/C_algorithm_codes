/*
ID;xsy19962 
TASK:nuggets
LANG:C++
*/
#include<cstdio>
long n,a[101],No1=0,No2=0,m,d,ans;
bool f[1000001];
long gcd(long x,long y)
{
    if(x>y)
    {
        x^=y;
        y^=x;
        x^=y;
    }
    if(x==0)
        return y;
    return gcd(y%x,x);
}
int main()
{
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>No1)
        {
            No2=No1;
            No1=a[i];
        }
        else if(a[i]>No2)
            No2=a[i];
    }
    m=No1*No2;
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    d=gcd(a[1],a[2]);
    for(i=3;i<=n;i++)
        d=gcd(d,a[i]);
    if(d!=1)
    {
        printf("0\n");
        return 0;
    }
    f[0]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<=m;j++)
            if(f[j])
                f[j+a[i]]=1;
    for(i=1;i<=m;i++)
        if(!f[i])
            ans=i;
    printf("%d\n",ans);
    return 0;
}
