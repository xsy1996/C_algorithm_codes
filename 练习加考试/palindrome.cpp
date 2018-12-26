#include<stdio.h>
char a[5001],b[5001];
long f[5001][5001];
int main()
{
    freopen("palindrome.in","r",stdin);
    freopen("palindrome.out","w",stdout);
    long i,j,k,n;
    scanf("%d",&n);
    getchar();
    scanf("%s",a+1);
    k=0;
    for(i=1;i<=n;i++)
        b[i]=a[n-i+1];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(f[i-1][j]<f[i][j-1])
                f[i][j]=f[i][j-1];
            else
                f[i][j]=f[i-1][j];
            if(a[i]==b[j] && f[i][j]<f[i-1][j-1]+1)
                f[i][j]=f[i-1][j-1]+1;
        }
    printf("%d\n",n-f[n][n]);
    return 0;
}
