#include<stdio.h>
long ans,t,n,m;
int main()
{
    freopen("finger.in","r",stdin);
    freopen("finger.out","w",stdout);
    long i,j,k,q;
    scanf("%d",&t);
    for(;t>=1;t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            k=0;
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&q);
                k+=q%2;
            }
            ans^=k;
        }
        if(ans!=0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
