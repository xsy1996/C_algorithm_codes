/*
ID:xsy19962
TASK:rockers
LANG:C++
*/
#include<stdio.h>
long f[101][101][101],n,t,m,l,max=0;
int main()
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    long i,j,k;
    scanf("%d%d%d",&n,&t,&m);
    f[0][1][0]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&l);
        for(j=1;j<=m;j++)
            for(k=0;k<=t;k++)
                f[i][j][k]=f[i-1][j][k];
        for(j=1;j<=m;j++)
        {
            for(k=0;k<=t-l;k++)
                if(f[i-1][j][k]>0 && f[i][j][k+l]<f[i-1][j][k]+1)
                    f[i][j][k+l]=f[i-1][j][k]+1;
            if(j!=m)
                for(k=t-l+1;k<=t;k++)
                    if(f[i-1][j][k]>0 && f[i][j+1][l]<f[i-1][j][k]+1)
                        f[i][j+1][l]=f[i-1][j][k]+1;
        }   
    }
    for(i=1;i<=m;i++) 
        for(j=0;j<=t;j++)
            if(f[n][i][j]>max)
                max=f[n][i][j];
    printf("%d\n",max-1);
    return 0;
}
