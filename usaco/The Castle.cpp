/*
ID:xsy19962
TASK:castle
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long a[501][501][5],t=0,s[10001],v[501][501],ans,xx,yy;
char fx;
void floodfill(long num,long x,long y)
{
    long i,j,k;
    v[x][y]=num;
    s[num]++;
    if(a[x][y][1]==0 && v[x][y-1]==0)
        floodfill(num,x,y-1);
    if(a[x][y][3]==0 && v[x][y+1]==0)
        floodfill(num,x,y+1);
    if(a[x][y][2]==0 && v[x-1][y]==0)
        floodfill(num,x-1,y);
    if(a[x][y][4]==0 && v[x+1][y]==0)
        floodfill(num,x+1,y);
    return;
}
int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    long i,j,k,n,m;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&k);
            if(k>=8)
            {
                k-=8;
                a[i][j][4]=1;
            }
            if(k>=4)
            {
                k-=4;
                a[i][j][3]=1;
            }
            if(k>=2)
            {
                k-=2;
                a[i][j][2]=1;
            }
            if(k>=1)
            {
                k-=1;
                a[i][j][1]=1;
            }
        }
    for(i=1;i<=m;i++)
    {
        a[1][i][2]=1;
        a[n][i][4]=1;
    }
    for(i=1;i<=n;i++)
    {
        a[i][1][1]=1;
        a[i][m][3]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(v[i][j]==0)
            {
                t++;
                floodfill(t,i,j);
            }
    k=0;
    for(i=1;i<=t;i++)
        if(k<s[i])
            k=s[i];
    printf("%d\n%d\n",t,k);
    for(j=1;j<=m;j++)
        for(i=n;i>=1;i--)
        {
            if(a[i][j][1]==1 && s[v[i][j]]+s[v[i][j-1]]>ans && v[i][j]!=v[i][j-1])
            {
                ans=s[v[i][j]]+s[v[i][j-1]];
                xx=i;yy=j;
                fx='W';
            }
            if(a[i][j][2]==1 && s[v[i][j]]+s[v[i-1][j]]>ans && v[i][j]!=v[i-1][j])
            {
                ans=s[v[i][j]]+s[v[i-1][j]];
                xx=i;yy=j;
                fx='N';
            }
            if(a[i][j][3]==1 && s[v[i][j]]+s[v[i][j+1]]>ans && v[i][j]!=v[i][j+1])
            {
                ans=s[v[i][j]]+s[v[i][j+1]];
                xx=i;yy=j;
                fx='E';
            }
            if(a[i][j][4]==1 && s[v[i][j]]+s[v[i+1][j]]>ans && v[i][j]!=v[i+1][j])
            {
                ans=s[v[i][j]]+s[v[i+1][j]];
                xx=i;yy=j;
                fx='S';
            }
        }
    printf("%d\n%d %d %c\n",ans,xx,yy,fx);
    return 0;    
}
