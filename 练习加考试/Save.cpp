#include<stdio.h>
int main()
{
    freopen("save.in","r",stdin);
    freopen("save.out","w",stdout);
    long save=0,rest=0,plan,i,j,k;
    for(i=1;i<=12;i++)
    {
        scanf("%d",&plan);
        k=300+rest-plan;
        if(k<0)
        {
            printf("-%d\n",i);
            return 0;
        }
        save+=k/100;
        rest=k%100;
    }
    printf("%d\n",save*120+rest);
    return 0;
}
