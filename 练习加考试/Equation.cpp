#include<stdio.h>
long c[1001][101][201],s[1001],t=0;
void add(long x,long y)
{
    long i,j,k;
    c[x][y][0]=c[x-1][y-1][0];
    if(c[x][y][0]<c[x-1][y][0])
        c[x][y][0]=c[x-1][y][0];
    for(i=1;i<=c[x][y][0];i++)
    {
        c[x][y][i]+=c[x-1][y-1][i]+c[x-1][y][i];
        c[x][y][i+1]=c[x][y][i]/10;
        c[x][y][i]%=10;
    }
    if(c[x][y][c[x][y][0]+1]>0)
        c[x][y][0]++;
    return;
}
int main()
{
    freopen("Equation.in","r",stdin);
    freopen("Equation.out","w",stdout);
    long i,j,k,n,m=1,x;
    scanf("%d%d",&n,&x);
    k=x%1000;
    while(x>0)
    {
        t++;
        s[t]=x%2;
        x/=2;
    }
    for(i=t;i>=1;i--)
    {
        m*=m;
        m%=1000;
        if(s[i]==1)
        {
            m*=k;
            m%=1000;
        }
    }
    c[1][1][0]=1;
    c[1][1][1]=1;
    for(i=2;i<=m+1;i++)
        for(j=1;j<=n+1;j++)
        {
            add(i,j);
         /*   for(k=c[i][j][0];k>=1;k--)
                printf("%d",c[i][j][k]);
            printf(" ");*/
        }
    if(c[m][n][0]!=0)
        for(i=c[m][n][0];i>=1;i--)
            printf("%d",c[m][n][i]);
    else
        printf("0");
    printf("\n");
    return 0;
}
