/*
ID:xsy19962
TASK:holstein
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long need[50],dl[50001][51],f[50001],t=1,kind[51][51],ans=101,path[101],mark[50001];
int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    long i,j,k,n,m,flag,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&need[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&kind[i][j]);
    for(i=1;i<=m;i++)
    {
        y=t;
        for(j=1;j<=y;j++)
        {
            t++;
            for(k=1;k<=n;k++)
                dl[t][k]=dl[j][k]+kind[i][k];
            dl[t][0]=dl[j][0]+1;
            f[t]=j;
            mark[t]=i;
            flag=0;
            for(k=1;k<=n;k++)
                if(dl[t][k]<need[k])
                    flag=1;
            if(flag==0)
            {
                if(dl[t][0]<ans)
                {
                    ans=dl[t][0];
                    x=t;
                    for(k=ans;k>=1;k--)
                    {
                        path[k]=mark[x];
                        x=f[x];
                    }
                }
                t--;
            }
        }
    }
    printf("%d %d",ans,path[1]);
    for(i=2;i<=ans;i++)
        printf(" %d",path[i]);
    printf("\n");
    return 0;    
}
