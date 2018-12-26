/*
ID:xsy19962
TASK:maze1 
LANG:C++
*/
#include<stdio.h>
#include<queue>
long n,m,map[101][101][4],f,l,fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans=1,v[101][101];
long p[501][501];
struct node
{
    long x,y,step;
};
using namespace std; 
queue <struct node> d;
int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    long i,j,k,x1,y1,s;
    struct node a;
    char c;
    scanf("%d%d",&m,&n);
    getchar();
    for(i=1;i<=2*n+1;i++,getchar())
        for(j=1;j<=2*m+1;j++)
        {
            scanf("%c",&c);
            if(c==' ')
                p[i][j]=0;
            else
                p[i][j]=1;
            if(c==' ' && (i==2*n+1 || i==1 || j==1 || j==m*2+1))
            {
                a.step=1;
                a.x=i/2;
                a.y=j/2;
                if(a.x==0)
                    a.x++;
                if(a.y==0)
                    a.y++;
                d.push(a);         
                v[i/2][j/2]=1;
               // printf("%d %d\n",i/2,j/2); 
                p[i][j]=1; 
            }
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            for(k=0;k<=3;k++)
                map[i][j][k]=p[2*i+fx[k][0]][2*j+fx[k][1]];
    while(!d.empty())
    {
        a=d.front();
        x1=a.x;
        y1=a.y;
        s=a.step+1;
        for(i=0;i<=3;i++)
            if(map[x1][y1][i]==0 && v[x1+fx[i][0]][y1+fx[i][1]]==0)
            {
                v[x1+fx[i][0]][y1+fx[i][1]]=s;
                if(s>ans)
                {
                    ans=s;
                 //   printf("%d %d %d\n",x1+fx[i][0],y1+fx[i][1],ans);
                }
                a.x=x1+fx[i][0];
                a.y=y1+fx[i][1];
                a.step=s;
                d.push(a);/**/
            }
        d.pop();
    }
    printf("%d\n",ans);
    return 0;
}
