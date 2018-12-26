/*
ID:xsy19962 
TASK:fence
LANG:C++
*/
#include<stdio.h>
long n=0,m,out[10001],t=0,s[1001][1001],a[501];
void dfs(long x)
{
    long i,j,k;
    for(i=1;i<=n;i++)
        while(s[x][i]!=0)
        {
            --s[x][i];
            --s[i][x];
            dfs(i);
        }
    t++;
    out[t]=x;
    return;
}
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    long i,j,k,x,y,w=1050;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        ++s[x][y];
        ++s[y][x];
        a[x]^=1;
        a[y]^=1;
        if(x<w)
            w=x;
        if(y<w)
            w=y;
        if(x>n)
            n=x;
        if(y>n)
            n=y;
    }
    for(i=n;i>=1;i--)
        if(a[i]==1)
            w=i;
    dfs(w);
    for(i=t;i>=1;i--)
        printf("%d\n",out[i]);
    return 0;
}
