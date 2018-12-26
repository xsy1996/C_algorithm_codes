/*
ID:xsy19962
TASK:cowtour
LANG:C++
*/
#include<stdio.h>
#include<math.h>
long n,x[201],y[201],f[201],t=0;
double dis[201][201],r[201],max[201],ans=100000000,q;
long father(long a)
{
    if(f[a]!=a)
        f[a]=father(f[a]);
    return f[a];
}
int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    long i,j,k,flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dis[i][j]=100000000;
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%1d",&k);
            if(k==1)
            {
                dis[i][j]=sqrt(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))*1.0);
                if(father(i)!=father(j))
                    f[father(i)]=father(j);
            }
        }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j && dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(dis[i][j]<100000000 && dis[i][j]>r[i])
            {
                r[i]=dis[i][j];
                if(r[i]>max[father(i)])
                    max[father(i)]=r[i];
            }           
    for(i=1;i<=n;i++)
        if(max[i]>0)
        {
            t++;
            max[t]=max[i];
         //   printf("%d %lf\n",i,max[i]);
        }
   // printf("-----------------\n");
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(father(i)!=father(j))
            {
                q=sqrt(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))*1.0);
                q+=r[i]+r[j];
                if(max[father(i)]>q)
                    q=max[father(i)];
                if(max[father(j)]>q)
                    q=max[father(j)];
                if(q<ans)
                    ans=q;
              //  printf("%d %d %lf\n",i,j,ans);
            }
    printf("%0.6lf\n",ans);
    return 0;   
}
