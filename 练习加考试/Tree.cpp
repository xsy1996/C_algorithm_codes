#include<stdio.h>
long f[101][1001],e[101][101],a[101],s[101],c[101],num[101];
void qsort(long l,long r)
{
    long i,j,k,x;
    i=l;j=r;
    x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j)
        {
            k=a[i];a[i]=a[j];a[j]=k;
            k=s[i];s[i]=s[j];s[j]=k;
            k=c[i];c[i]=c[j];c[j]=k;
            k=num[i];num[i]=num[j];num[j]=k;
            i++;j--;
        }
    }
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
    return;
}
int main()
{
    freopen("Tree.in","r",stdin);
    freopen("Tree.out","w",stdout);
    long i,j,k,n,m,max=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&s[i],&c[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&e[i][j]);
    for(i=1;i<=n;i++)
        num[i]=i;
    qsort(1,n);
    for(i=0;i<=n;i++)
        for(j=i+1;j<=n;j++)
            for(k=0;k<=m-c[j]-e[i][j];k++)
                if(f[i][k]+s[j]>f[j][k+c[j]+e[i][j]])
                    f[j][k+c[j]+e[i][j]]=f[i][k]+s[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(f[i][j]>max)
                max=f[i][j];
    printf("%d\n",max);
    return 0;
}
