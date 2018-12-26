#include<stdio.h>
long n,m,d[111],c[111][111],x[11111],y[11111],gap[111],min[111][111],max[111][111],sum;
long fmin(long a,long b)
{
    return a<b ? a:b;
}
long sap(long s,long flow)
{
    long i,j,k,f=0;
    if(s==n+1)
        return flow;
    for(i=1;i<=n+1;i++)
        if(c[s][i] && d[s]==d[i]+1)
        {
            k=sap(i,fmin(flow-f,c[s][i]));
            c[s][i]-=k;
            c[i][s]+=k;
            f+=k;  
            if(f==flow)   
                return f;       
        }
    if(d[0]<=n+1)
    {
        gap[d[s]]--;
        if(gap[d[s]]==0)
            d[0]=n+2;
        d[s]++;
        gap[d[s]]++;
    }
    return f;    
}
long yes()
{
    long i,j,k,ans=0;
    sum=0;
    for(i=0;i<=n+1;i++)
    {
        d[i]=0;
        gap[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        k=0;
        for(j=1;j<=n;j++)
        {
            k+=min[j][i]-min[i][j];
            c[i][j]=max[i][j]-min[i][j];
        }    
        if(k>0)
        {
            sum+=k;
            c[0][i]=k;
        }
        else
            c[i][n+1]=-1*k;
    }
    for(gap[0]=n+2;d[0]<=n+1;)
        ans+=sap(0,2147283600);
    return ans<sum ? 0:1;
}
int main()
{
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
    long i,j,k,a,b,l,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&a,&b);
        max[x[i]][y[i]]+=a;
        if(b)
            min[x[i]][y[i]]+=a;
    }
    l=0;a=0;b=0;
    for(i=2;i<n;i++)
    {
         a+=max[1][i];
         b+=max[i][n];       
    }
    if(a>b)
        r=b+1;
    else
        r=a+1;
    k=r;
    while(l<r)
    {
        max[n][1]=(l+r)/2;
        if(yes())
            r=max[n][1];
        else
            l=max[n][1]+1;
    }
    if(r==k)
        printf("Impossible\n");
    else
    {
        max[n][1]=r;
        yes();
        printf("%d\n",r);
        for(i=1;i<=m;i++)
            printf("%d ",max[x[i]][y[i]]-c[x[i]][y[i]]);
        printf("\n");
    }
    return 0;
}
