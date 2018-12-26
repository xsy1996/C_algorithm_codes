#include<stdio.h>
long f[100001],a[100001],n,m,t;
long father(long x)
{
    long k;
    if(f[x]!=x)
    {   
        k=f[x];
        f[x]=father(f[x]);
        a[x]=(a[k]+a[x])%2;
    }
    return f[x];
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    long i,j,k,x,y,fx,fy;
    char c;
    scanf("%d",&t);
    for(;t>=1;t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            f[i]=i;
            a[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            getchar();
            scanf("%c",&c);
            scanf("%d%d",&x,&y);
            fx=father(x);
            fy=father(y);
            if(c=='D')
            {
                a[fy]=(a[x]+a[y]+1)%2;
                f[fy]=fx;
            }
            if(c=='A')
            {
                if(fx!=fy)
                    printf("Not sure yet.\n");
                else if(a[x]==a[y])
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
        }
    }
    return 0;
}
