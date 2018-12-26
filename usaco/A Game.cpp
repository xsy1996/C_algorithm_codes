/*
ID:xsy19962
TASK:game1
LANG:C++
*/
#include<stdio.h>
#define max(i,j) (((i)>(j))?(i):(j))
long n,a[201],f[201][201],s[201];
int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        f[i][i]=a[i];
    }
    for(k=1;k<n;k++)
        for(i=1;i<n;i++)
            if(i+k<=n)
            {
                j=i+k;
                f[i][j]=max(a[i]+s[j]-s[i]-f[i+1][j],a[j]+s[j-1]-s[i-1]-f[i][j-1]);
            }
    printf("%d %d\n",f[1][n],s[n]-f[1][n]);
    return 0;
}
