/*
ID:xsy19962
TASK:fence6
LANG:C++
*/
#include<stdio.h>
long n,map[101][101],num[101],l[101],s1[101][11],s2[101][11],dis[101][101][2];
int main()
{
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    long i,j,k,min=100000001;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            dis[i][j][1]=100000001;
            dis[i][j][0]=100000001;
        }
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&num[i],&l[i],&s1[i][0],&s2[i][0]);
        for(j=1;j<=s1[i][0];j++)
            scanf("%d",&s1[i][j]);
        for(j=1;j<=s2[i][0];j++)
            scanf("%d",&s2[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=s1[j][0];k++)
                if(s1[j][k]==num[i])
                    dis[j][i][0]=l[i]+l[j];
            for(k=1;k<=s2[j][0];k++)
                if(s2[j][k]==num[i])
                    dis[j][i][1]=l[i]+l[j];
        }
    }   
 /*   for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            printf("%d %d %d %d\n",i,j,dis[i][j][0],dis[i][j][1]);*/
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                    if(dis[i][k][1]==dis[k][i][1] && dis[k][i][1]+dis[k][j][0]<dis[i][j][1])
                        dis[i][j][1]=dis[k][i][1]+dis[k][j][0];
                    else if(dis[i][k][0]==dis[k][i][1] && dis[k][i][1]+dis[k][j][0]<dis[i][j][0])
                        dis[i][j][0]=dis[k][i][1]+dis[k][j][0];
                    else if(dis[j][k][1]==dis[k][j][0] && dis[k][i][1]+dis[k][j][0]<dis[j][i][1])
                        dis[j][i][1]=dis[k][i][1]+dis[k][j][0];
                    else if(dis[j][k][0]==dis[k][j][0] && dis[k][i][1]+dis[k][j][0]<dis[j][i][0])
                        dis[j][i][0]=dis[k][j][0]+dis[k][i][1];
                    if(dis[i][k][1]==dis[k][i][0] && dis[k][i][0]+dis[k][j][1]<dis[i][j][1])
                        dis[i][j][1]=dis[k][i][0]+dis[k][j][1];
                    else if(dis[i][k][0]==dis[k][i][0] && dis[k][i][0]+dis[k][j][1]<dis[i][j][0])
                        dis[i][j][0]=dis[k][i][0]+dis[k][j][1];
                    else if(dis[j][k][1]==dis[k][j][1] && dis[k][i][0]+dis[k][j][1]<dis[j][i][1])
                        dis[j][i][1]=dis[k][i][0]+dis[k][j][1];
                    else if(dis[j][k][0]==dis[k][j][1] && dis[k][i][0]+dis[k][j][1]<dis[j][i][0])
                        dis[j][i][0]=dis[k][j][1]+dis[k][i][0];
            }
    for(i=1;i<=n;i++)
        if(dis[i][i][0]<min)
            min=dis[i][i][0];
    printf("%d\n",min/2);
    return 0;
}
