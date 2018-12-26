#include<stdio.h>
long long q[100001],sum[1000001],f,l;
int main()
{
    freopen("Azwraith.in","r",stdin);
    freopen("Azwraith.out","w",stdout);
    long long i,j,k,n,t,a,b,max;
    scanf("%I64d%I64d",&t,&n);
    for(;t>=1;t--)
    {
        sum[0]=0;
        scanf("%I64d%I64d",&a,&b);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&sum[i]);
            sum[i]+=sum[i-1];
        }
        f=1;l=1;
        q[1]=0;
        max=0;
        for(i=a;i<=n;i++)
        {
            if(i-q[f]>b)
                f++;
            while(sum[i-a]<=sum[q[l]] && l-f>=0)
                l--;
            l++;
            q[l]=i-a;
     /*   for(j=f;j<=l;j++)
            printf("%I64d ",q[j]);
        printf("\n");*/
            if(sum[i]-sum[q[f]]>max)
                max=sum[i]-sum[q[f]];
        }
        printf("%I64d\n",max);
    }
    return 0;
}
