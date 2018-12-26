#include<stdio.h>
int main()
{
    freopen("Team.in","r",stdin);
    freopen("Team.out","w",stdout);
    long i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=m;j++)
            if((i+j)%3==0)
                printf("#");
            else
                printf("0");
    return 0;
}
