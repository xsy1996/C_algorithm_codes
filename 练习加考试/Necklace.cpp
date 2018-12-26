#include<stdio.h>
long a[500001],s[101],n,m;
int main()
{
    freopen("Necklace.in","r",stdin);
    freopen("Necklace.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i>=1;i--)
    {
        k=2147483640;
        for(j=1;j<=m;j++)
            if(s[j]<k)
                k=s[j];
        s[a[i]]=k+1;
    }
    k=2147483640;
    for(i=1;i<=m;i++)
        if(s[i]<k)
            k=s[i];
    printf("%d\n",k+1);
    return 0;
}
