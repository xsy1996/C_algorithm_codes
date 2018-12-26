/*
ID:xsy19962
TASK:camelot
LANG:C++
*/
#include<stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define jdz(a) (((a)>=0)?(a):((a)*-1))
long m,n,x[1001],y[1001],t=0,kx,ky,dis[31][31][31][31],d[10001][2],f,l,fx[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}},ans=2147483600;
int main()
{
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    long i,j,k,b;
    char a;
    scanf("%d%d",&m,&n);
    getchar();
    scanf("%c",&a);
    scanf("%d",&b);
    kx=a-'A'+1;
    ky=b;
    getchar();
    while(scanf("%c",&a)!=EOF)
    {
        scanf("%d",&b);
        //printf("%c %d\n",a,b);
        t++;
        x[t]=a-'A'+1;
        y[t]=b;
        getchar();
    }
    if(t==0)
    {
        printf("0\n");
        return 0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            for(k=1;k<=n;k++)
                for(b=1;b<=m;b++)
                    dis[i][j][k][b]=100000000;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            f=0;l=1;
            d[1][0]=i;
            d[1][1]=j;
            dis[i][j][i][j]=0;
            while(f<l)
            {
                long xx,yy;
                f++;
                for(k=0;k<=7;k++)
                {
                    xx=d[f][0]+fx[k][0];
                    yy=d[f][1]+fx[k][1];
                    if(xx>n || xx<1 || yy>m || yy<1)
                        continue;
                    if(dis[i][j][xx][yy]>dis[i][j][d[f][0]][d[f][1]]+1)
                    {
                        dis[i][j][xx][yy]=dis[i][j][d[f][0]][d[f][1]]+1;
                       // printf("%d   %d %d %d %d %d   %d  %d %d %d %d %d\n",l,i,j,xx,yy,dis[i][j][xx][yy],f,i,j,d[f][0],d[f][1],dis[i][j][d[f][0]][d[f][1]]);
                        l++;
                        d[l][0]=xx;
                        d[l][1]=yy;
                    }    
                }
            }
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            long sum=0,x1,y1,min=2147483600;
            for(k=1;k<=t;k++)
            {
              //  printf("%d %d %d %d\n",i,j,x[k],y[k]);
                if(dis[x[k]][y[k]][i][j]==100000000)
                {
                    sum=ans+1;
                    break;
                }
                sum+=dis[x[k]][y[k]][i][j];
                for(x1=kx-2;x1<=kx+2;x1++)
                    for(y1=ky-2;y1<=ky+2;y1++)
                    {
                        if(x1<1 || x1>n || y1<1 || y1>m || dis[x[k]][y[k]][x1][y1]==100000000 || dis[x1][y1][i][j]==100000000 || dis[x[k]][y[k]][i][j]==100000000)
                            continue;
                        if(max(jdz(x1-kx),jdz(y1-ky))+dis[x[k]][y[k]][x1][y1]+dis[x1][y1][i][j]-dis[x[k]][y[k]][i][j]<min)
                        {
                            min=max(jdz(x1-kx),jdz(y1-ky))+dis[x[k]][y[k]][x1][y1]+dis[x1][y1][i][j]-dis[x[k]][y[k]][i][j];
                        }
                    }
            }
            if(min==2147483600)
                continue;
          //  printf("%d %d\n",sum,min);
            if(sum+min<ans)
                ans=sum+min;
           // printf("-----%d\n",ans);
        }
    printf("%d\n",ans);
    return 0;
}
