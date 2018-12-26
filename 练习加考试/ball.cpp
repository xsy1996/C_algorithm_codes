#include<stdio.h>
long m,n,f[2][501][501],a[501],b[501];
int main()
{
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    long i,j,k,x1,y1,x2,y2;
    char c;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=1;i<=n;i++)
    {
        scanf("%c",&c);
        if(c=='A')
            a[i]=0;
        else 
            a[i]=1;
    }
    getchar();
    for(i=1;i<=m;i++)
    {
        scanf("%c",&c);
        if(c=='A')
            b[i]=0;
        else 
            b[i]=1;
    }
    f[(n+m)%2][n][n]=1;
    for(i=n+m;i>=1;i--)
        for(x1=0;x1<=n;x1++)
            for(x2=0;x2<=n;x2++)
                if(f[i%2][x1][x2]>0)
                {
                    y1=i-x1;
                    y2=i-x2;
                    if(x1<0 || x2<0 || y1<0 || y2<0 || x1>n || x2>n || y1>m || y2>m)
                        continue;
                    if(a[x1]==a[x2] && x1>0 && x2>0)
                    {
                        f[(i+1)%2][x1-1][x2-1]+=f[i%2][x1][x2];
                        f[(i+1)%2][x1-1][x2-1]%=1024523;
                    }
                    if(a[x1]==b[y2] && x1>0 && y2>0)
                    {
                        f[(i+1)%2][x1-1][x2]+=f[i%2][x1][x2];
                        f[(i+1)%2][x1-1][x2]%=1024523;
                    }
                    if(b[y1]==a[x2] && y1>0 && x2>0)
                    {
                        f[(i+1)%2][x1][x2-1]+=f[i%2][x1][x2];
                        f[(i+1)%2][x1][x2-1]%=1024523;
                    }
                    if(b[y1]==b[y2] && y1>0 && y2>0)
                    {
                        f[(i+1)%2][x1][x2]+=f[i%2][x1][x2];
                        f[(i+1)%2][x1][x2]%=1024523;
                    }
                    f[i%2][x1][x2]=0;
                }
    printf("%d\n",f[0][0][0]);
    return 0;
}
