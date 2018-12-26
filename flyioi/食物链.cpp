#include<stdio.h>
#include<stdlib.h>
long m,n,d[50001],f[50001],ans=0;
long a[3][3]={{0,1,-1},{-1,0,1},{1,-1,0}};
long father(long x)
{
    long k;
    if(f[f[x]]==f[x])
        return f[x];
    k=f[x];
    f[x]=father(f[x]);
    d[x]+=d[k];
    d[x]%=3;
    return f[x];
}
int main()
{
    long i,j,k,fx,fy;
    long q,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&q,&x,&y);
        if(x<1 || x>n || y<1 || y>n)
        {
            ans++;
            continue;
        }
        fx=father(x);
        fy=father(y);
        if(q==1)
        {
            if(fx==fy && a[d[x]][d[y]]!=0)
                ans++;
            if(fx!=fy)
            {
                d[fx]=(d[y]+3-d[x])%3;
                f[fx]=fy;
            }
        }
        else
        {
            if(fx==fy && a[d[x]][d[y]]!=1)
                ans++;
            else if(fx!=fy)
            {
                if(fy==y)
                {
                    d[y]=1;
                    f[y]=x;
                }
                else
                {
                    d[fx]=(d[y]+3-d[x]-1)%3;
                    f[fx]=fy;
                }
            }
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
