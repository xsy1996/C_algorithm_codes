#include<stdio.h>
long map[2001][2001],t[2001],v[2001],dis[2001];
int main()
{
    freopen("Plan.in","r",stdin);
    freopen("Plan.out","w",stdout);
    long i,j,k,n,m,x,y,z,min;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(map[x][y]==0 || z<map[x][y])
            map[x][y]=z;
    }
    for(i=1;i<=n;i++)
        dis[i]=2147483640;
    dis[1]=0;
    t[1]=1;
    dis[0]=2147483600;
    while(v[n]==0)
    {
        min=0;
        for(i=1;i<=n;i++)
            if(v[i]==0 && (dis[i]<dis[min] || (dis[i]==dis[min] && t[i]>t[min])))
                min=i;
        if(min==0)
            break;
        else
        {
            v[min]=1;
            for(i=1;i<=n;i++)
            {
                if(map[min][i]>0 && map[min][i]+dis[min]<dis[i])
                {
                    dis[i]=map[min][i]+dis[min];
                    t[i]=t[min];    
                }
                else if(map[min][i]>0 && map[min][i]+dis[min]==dis[i])
                    t[i]+=t[min];
            }
        }
    }
    if(v[n]==0)
        printf("No answer\n");
    else
        printf("%d %d\n",dis[n],t[n]);
    return 0;   
}
