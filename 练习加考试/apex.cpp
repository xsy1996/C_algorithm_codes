#include<stdio.h>
long long find(long long n)
{
    long long i,j,k;
    k=1;
    while(n!=1)
    {
        if(!(n&1) || (n+1)%4==0)
            k*=-1;
        n=(n+1)>>1;
    }
    return k;
}
long long sum(long long n)
{
    long long i,j,k;
    if(n==0)
        return 0;
    k=0;
    if(n&1)
        k=find(n);
    return ((sum(n>>2))<<1)+k;
}
int main()
{
    //freopen("apex.in","r",stdin);
    //freopen("apex.out","w",stdout);
    long long i,j,k,n,m,s;
    scanf("%I64d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%I64d%I64d",&k,&n);
        if(k==1)
            printf("%I64d\n",find(n));
        else
        {
            s=sum(n);
            if(k==2)
            {
                if(s==0)
                    printf("0\n");
                if(s>0)
                    printf("+\n");
                if(s<0)
                    printf("-\n");
            }
            if(k==3)
                printf("%I64d\n",s);
        }
    }
    return 0;
}

