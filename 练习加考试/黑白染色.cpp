#include<stdio.h>
long map[101][101],n,m,q[50001][2],dis[101][101],f,l=0,min=2147483640,max,fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    long i,j,k,x,y,a,b;
    char c;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=1;i<=n;i++,getchar())
        for(j=1;j<=m;j++)
        {
            scanf("%c",&c);
            if(c=='B')
                map[i][j]=1;
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {   
            for(a=1;a<=n;a++)
                for(b=1;b<=m;b++)
                    dis[a][b]=2147483600;    
            max=0;
            f=0;l=1;
            q[1][0]=i;
            q[1][1]=j;
            dis[i][j]=0;
            while(f<l)
            {
                f++;
                for(k=0;k<=3;k++)
                {
                    x=q[f][0]+fx[k][0];
                    y=q[f][1]+fx[k][1];
                    if(x>n || x<1 || y>m || y<1)
                        continue;
                    a=dis[q[f][0]][q[f][1]];
                    if(map[q[f][0]][q[f][1]]!=map[x][y])
                        a++;
                    if(a<dis[x][y])
                    {
                        l++;
                        dis[x][y]=a;
                        q[l][0]=x;
                        q[l][1]=y;
                    }
                }
            }
            for(a=1;a<=n;a++)
                for(b=1;b<=m;b++)
                    if(map[a][b] && dis[a][b]>max)
                        max=dis[a][b];
            if(max<min)
                min=max;  
        }
        printf("%d\n",min+1);
    return 0;
}
