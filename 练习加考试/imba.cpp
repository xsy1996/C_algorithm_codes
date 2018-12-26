#include<stdio.h>
long f[101][5001],n,hp,l,r,max;
int main()
{
    freopen("imba.in","r",stdin);
    freopen("imba.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&hp);
    f[0][hp+2000]=1;
    max=hp+2000;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        for(j=0;j<=max;j++)
            if(f[i][j]>0)
                for(k=l;k<=r;k++)
                    if(j-k>=0)
                    {
                        f[i+1][j-k]+=f[i][j];
                        f[i+1][j-k]%=99991;
                        if(j-k>max)
                            max=j-k;
                    }
    }
    printf("%d\n",f[n][2000]);
    return 0;   
}
