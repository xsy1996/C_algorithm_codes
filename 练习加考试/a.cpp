#include<stdio.h>
long dp[5001][5001],x[5001],y[5001],xx[5001],yy[5001],qx[5001],qy[5001],f[100001],n;
void qsortx(long l,long r)
{
    long a,i,j,k;
    i=l;j=r;
    a=xx[(i+j)/2];
    while(i<=j)
    {
        while(qx[xx[i]]<qx[a])i++;
        while(qx[xx[j]]>qx[a])j--;
        if(i<=j)
        {
            k=xx[i];
            xx[i]=xx[j];
            xx[j]=k;
            i++;
            j--;
        }
    }
    if(i<r)qsortx(i,r);
    if(l<j)qsortx(l,j);
    return;
}
void qsorty(long l,long r)
{
    long a,i,j,k;
    i=l;j=r;
    a=yy[(i+j)/2];
    while(i<=j)
    {
        while(qy[yy[i]]<qy[a])i++;
        while(qy[yy[j]]>qy[a])j--;
        if(i<=j)
        {
            k=yy[i];
            yy[i]=yy[j];
            yy[j]=k;
            i++;
            j--;
        }
    }
    if(i<r)qsorty(i,r);
    if(l<j)qsorty(l,j);
    return;
}
long father(long a)
{
    if(f[a]!=a)
        f[a]=father(f[a]);
    return f[a];
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    long i,j,k,mx,my;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&qx[i],&qy[i]);
    for(i=1;i<=n;i++)
    {
        xx[i]=i;
        yy[i]=i;
    }
    qsortx(1,n);
    qsorty(1,n);
    mx=0;my=0;
    for(i=1;i<=n;i++)
    {
        if(qx[xx[i]]!=qx[xx[i-1]])
            mx++;
        x[xx[i]]=mx;
        if(qy[yy[i]]!=qy[yy[i-1]])
            my++;
        y[yy[i]]=my;
    }
    for(i=1;i<=mx;i++)
        f[i]=i;
    for(i=1;i<=my;i++)
        f[i+mx]=i+mx;
    for(i=1;i<=n;i++)
        f[father(x[i])]=father(y[i]+mx);
    for(i=1;i<=mx;i++)
        for(j=1;j<=my;j++)
        {
            if(father(i)==father(j+mx))
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=dp[i-1][j-1];    
            if(dp[i][j-1]>dp[i][j])
                dp[i][j]=dp[i][j-1];
            if(dp[i-1][j]>dp[i][j])
                dp[i][j]=dp[i-1][j];
        }
    printf("%d\n",dp[mx][my]);
    return 0;
}
