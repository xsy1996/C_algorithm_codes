#include<stdio.h>
long end[10001],n;
int main()
{
    long i,j,k,max,t,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&m);
        max=0;
        for(j=1;j<=m;j++)
        {
            scanf("%d",&k);
            if(end[k]>max)
                max=end[k];
        }
        end[i]=max+t;
    }
    max=0;
    for(i=1;i<=n;i++)
        if(end[i]>max)
            max=end[i];
    printf("%d\n",max);
    return 0;
}
