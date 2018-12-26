#include<stdio.h>
#include<math.h>
long n,m,l,r,min[101][1001];
int main()
{
    long i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&min[0][i]);
    i=1;
    for(k=1;k*2<=n;k*=2,i++)
        for(j=1;j<=n-2*k+1;j++)
        {
            min[i][j]=min[i-1][j];
            if(min[i-1][j+k]<min[i][j])
                min[i][j]=min[i-1][j+k];
            printf("%d %d %d\n",i,j,min[i][j]);
        }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        k=double(log(r-l+1)*1.0)/double(log(2)*1.0);
        printf("%d\n",min[k][l]);
    }
    scanf("%d",&k);
    return 0;
}
