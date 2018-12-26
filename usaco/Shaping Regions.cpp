/*
ID:xsy19962
TASK:rect1
LANG:C++
*/
#include<stdio.h>
long n,a,b,x1[1001],x2[1001],y1[1001],y2[1001],c[1001],sum[1002];
void dfs(long i,long xx1,long xx2,long yy1,long yy2,long color)
{
    long j,k;
    while(i<=n && (x1[i]>xx2 || x2[i]<xx1 || y1[i]>yy2 || y2[i]<yy1))
        i++;
    if(i>n)
    {
        sum[color]+=(xx2-xx1)*(yy2-yy1);
        return;
    }
    if(x1[i]>xx1)
    {
        dfs(i+1,xx1,x1[i],yy1,yy2,color);
        xx1=x1[i];
    }
    if(x2[i]<xx2)
    {
        dfs(i+1,x2[i],xx2,yy1,yy2,color);
        xx2=x2[i];
    }
    if(y1[i]>yy1)
    {
        dfs(i+1,xx1,xx2,yy1,y1[i],color);
        yy1=y1[i];
    }
    if(y2[i]<yy2)
    {
        dfs(i+1,xx1,xx2,y2[i],yy2,color);
        yy2=y2[i];
    }
    return;
}
int main()
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    long i,j,k;
    scanf("%d%d%d",&a,&b,&n);
    n++;
    x1[1]=0;
    y1[1]=0;
    x2[1]=a;
    y2[1]=b;
    c[1]=1;
    for(i=2;i<=n;i++)
        scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&c[i]);
    for(i=1;i<=n;i++)
        dfs(i+1,x1[i],x2[i],y1[i],y2[i],c[i]);
    for(i=1;i<=1001;i++)
        if(sum[i]!=0)
            printf("%d %d\n",i,sum[i]);
    return 0;    
}
