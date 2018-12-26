#include<stdio.h>
long t[1001],v[1001],g[1001],vmax,gmax,f[1001][1001],ans=0;
int main()
{
    freopen("Transport.in","r",stdin);
    freopen("Transport.out","w",stdout);
    long i,j,k,n;
    scanf("%d%d",&vmax,&gmax);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d%d",&t[i],&v[i],&g[i]);
    f[0][0]=1;
    for(k=1;k<=n;k++)
        for(i=vmax;i>=0;i--)
            for(j=gmax;j>=0;j--)
                if(f[i][j]>0 && i+v[k]<=vmax && j+g[k]<=gmax && f[i+v[k]][j+g[k]]<f[i][j]+t[k])
                    f[i+v[k]][j+g[k]]=f[i][j]+t[k];
    for(i=0;i<=vmax;i++)
        for(j=0;j<=gmax;j++)
            if(f[i][j]>ans)
                ans=f[i][j];
    printf("%d\n",ans-1);
    return 0;
}
