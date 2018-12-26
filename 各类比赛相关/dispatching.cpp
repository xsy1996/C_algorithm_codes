#include<stdio.h>
#define minc(a,b) ((cost[(a)]<cost[(b)])?(a):(b))
long long ans=0,n,m,f[100001],head[100001],next[100001],cost[100001],lead[100001];
int main()
{
    freopen("dispatching.in","r",stdin);
    freopen("dispatching.out","w",stdout);
    long long i,j,k,s,sum,f1,f2;
    scanf("%I64d%I64d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%I64d",&f[i],&cost[i],&lead[i]);
        head[i]=i;
    }
    for(i=n;i>=1;i--)
    {
        k=head[i];
        sum=0;
        s=0;
        while(k!=0 && sum+cost[k]<=m)
        {
            sum+=cost[k];
            k=next[k];
            s++;
        }
        next[k]=0;
        if(ans<lead[i]*s)
            ans=lead[i]*s;
        f1=head[i];
        f2=head[f[i]];
        head[f[i]]=minc(f1,f2);
        k=head[f[i]];
        sum=cost[k];
        if(f1==k)
            f1=next[f1];
        else 
            f2=next[f2];
        while(f1!=0 && f2!=0)
        {
            if(cost[f1]<cost[f2])
            {
                next[k]=f1;
                k=f1;
                f1=next[f1];
            }
            else
            {
                next[k]=f2;
                k=f2;
                f2=next[f2];
            }
        }
        if(f2==0)
            next[k]=f1;
        else
            next[k]=f2;
    }
    printf("%I64d\n",ans);
    return 0;
}
