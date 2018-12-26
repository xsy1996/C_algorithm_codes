#include<stdio.h>
#include<string.h>
long map[101][1001],dis[1001][1001],fx[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char c[101][1001];
long min(long x,long y)
{
    if(x>y)
        return y;
    else
        return x;
}
int main()
{
    freopen("desert.in","r",stdin);
    freopen("desert.out","w",stdout);
    long i,j,k,n,sx,sy,x,y,flag,min1,min2,m;
    scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%s",c[i]+1);
    }
    m=strlen(c[1]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            dis[i][j]=1000001;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(c[i][j]=='@')
            {
                sx=i;sy=j;
            }
            else if(c[i][j]=='*')
            {
                dis[i][j]=0;
            //    printf("%d %d\n",i,j);
            }
            else if(c[i][j]=='X')
                map[i][j]=1;
        }
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=m;j++)
            printf("%d   ",dis[i][j]);*/
    for(i=0;i<=n+1;i++)
    {
        map[i][0]=1;
        map[i][m+1]=1;
    }
    for(i=0;i<=m+1;i++)
    {
        map[0][i]=1;
        map[n+1][i]=1;
    }
    flag=1;
    while(flag)
    {
        flag=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            if(dis[i][j]>0 && map[i][j]==0)
            {
                min1=1000001;
                min2=1000001;
                for(k=0;k<8;k++)
                {
                    x=i+fx[k][0];
                    y=j+fx[k][1];
                    if(map[x][y]!=1 && dis[x][y]<=min1)
                    {
                        min2=min1;
                        min1=dis[x][y];
                    }
                    else if(map[x][y]!=1 && dis[x][y]<min2)
                        min2=dis[x][y];
                }
                if(dis[i][j]>min(min1+3,min2+1))
                {
                    dis[i][j]=min(min1+3,min2+1);
                    flag=1;
                }
            }
    }
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=m;j++)
            printf("%d ",dis[i][j]);*/
    if(dis[sx][sy]==1000001)
        dis[sx][sy]=-1;
    printf("%d\n",dis[sx][sy]);
    return 0;
}
