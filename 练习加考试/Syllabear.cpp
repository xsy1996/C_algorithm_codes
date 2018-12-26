#include<stdio.h>
long long w[1001],v[1001],f[100001];
int main()
{
    freopen("Syllabear.in","r",stdin);
    freopen("Syllabear.out","w",stdout);
    long long i,j,k,n,m,a,b,max=0;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&w[i]);
        w[i]=(w[i]-1)/a+1;
    }
    for(i=1;i<=n;i++)
        scanf("%I64d",&v[i]);
    f[0]=1;
    for(k=1;k<=n;k++)
        for(i=m;i>=0;i--)
            if(f[i]>0 && i+w[k]<=m && v[k]+f[i]>f[i+w[k]])
                f[i+w[k]]=v[k]+f[i];
    for(i=0;i<=m;i++)
        if(f[i]>max)
            max=f[i];
    printf("%I64d\n",max-1);
    return 0;
}
