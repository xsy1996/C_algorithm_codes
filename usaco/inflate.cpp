/*
ID:xsy19962 
TASK:inflate 
LANG:C++
*/
#include<stdio.h>
long f[100001],n,m,a[10001],v[10001];
int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&v[i],&a[i]);
    f[0]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<=m;j++)
            if(f[j]>0 && j+a[i]<=m && f[j]+v[i]>f[j+a[i]])
                f[j+a[i]]=f[j]+v[i];
    k=0;
    for(i=1;i<=m;i++)
        if(f[i]>k)
            k=f[i];
    printf("%d\n",k-1);
    return 0;
}
