#include<stdio.h>
long f[5001][101];
int main()
{
    freopen("coat.in","r",stdin);
    freopen("coat.out","w",stdout);
    long i,j,k,n,m,q,w,ans=0;
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        printf("%d\n",m);
        return 0;
    }
    for(i=1;i<=m;i++)
        f[1][i]=1;
    for(q=1;q<=m;q++)   
    {
        for(i=1;i<=m;i++)
            f[2][i]=1;   
        f[2][q]=0; 
        for(i=3;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                f[i][j]=0;
                for(k=1;k<=m;k++)
                    if(k!=j)
                    {
                        f[i][j]+=f[i-1][k];
                        f[i][j]%=19900801;
                    }
            }
        for(i=1;i<=m;i++)
            if(i!=q)
            {
                ans+=f[n][i];
                ans%=19900801;
            }
    }
    printf("%d\n",ans);
    return 0;
}
