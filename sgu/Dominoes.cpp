#include<stdio.h>
long map[101][101],n,m,sum=0,v[101][101],a[101][101][2],b[101][101],flag=0,h=0,s=0,fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
long match(long x,long y)
{
    long x1,y1,i,j,k;
    if(v[x][y]==1)
        return 0;
    v[x][y]=1;
    for(i=0;i<=3;i++)
    {
        x1=x+fx[i][0];
        y1=y+fx[i][1];
        if(map[x1][y1]!=-1 && v[x1][y1]==0 && (a[x1][y1][0]==-1 || match(a[x1][y1][0],a[x1][y1][1])==1))
        {
            v[x1][y1]=1;
            a[x][y][0]=x1;
            a[x][y][1]=y1;
            a[x1][y1][0]=x;
            a[x1][y1][1]=y;
            return 1;
        }   
    }
    return 0;    
}
int main()
{
 //   freopen("D.in","r",stdin);
  //  freopen("D.out","w",stdout);
    long i,j,k,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=-1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j][0]=-1;
            a[i][j][1]=-1;
        }
    for(i=0;i<=n+1;i++)
    {
        map[i][0]=-1;
        map[i][n+1]=-1;
        map[0][i]=-1;
        map[0][n+1]=-1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(map[i][j]!=-1 && a[i][j][0]==-1)
            {
                for(x=1;x<=n;x++)
                    for(y=1;y<=n;y++)
                        v[x][y]=0;
                if(match(i,j)==0)
                {
                    flag=1;
                    break;
                }
            }
    if(flag==1)
        printf("No\n");
    else
    {
        printf("Yes\n");
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(map[i][j]==-1 || map[a[i][j][0]][a[i][j][1]]==-1)
                    continue;
                if(a[i][j][0]==i && a[i][j][1]==j+1)
                {
                    s++;
                    b[i][j]=2;
                }
                if(a[i][j][0]==i+1 && a[i][j][1]==j)
                {
                    h++;
                    b[i][j]=1;
                }
            }
    /*    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                printf("%d %d     %d %d\n",i,j,a[i][j][0],a[i][j][1]);*/
        printf("%d\n",h);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(b[i][j]==1)
                    printf("%d %d\n",i,j);
        printf("%d\n",s);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(b[i][j]==2)
                    printf("%d %d\n",i,j);
    }
    return 0;
}
