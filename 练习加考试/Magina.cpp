#include<stdio.h>
long long v[5001],s[10001],like[5001][101],num[5001],ans[5001],p[10001][501],vi[10001],n,m,sum=0;
void qsort(long long l,long long r)
{
    long long i,j,k,x,t,q[101];
    i=l;j=r;
    x=v[(i+j)/2];
    while(i<=j)
    {    
        while(v[i]>x)i++;
        while(v[j]<x)j--;
        if(i<=j)
        {
            k=v[i];
            v[i]=v[j];
            v[j]=k;
            k=num[i];
            num[i]=num[j];
            num[j]=k;
            t=like[i][0];
            for(k=1;k<=t;k++)
                q[k]=like[i][k];
            for(k=1;k<=like[j][0];k++)
                like[i][k]=like[j][k];
            like[i][0]=like[j][0];
            like[j][0]=t;
            for(k=1;k<=t;k++)
                like[j][k]=q[k];
            i++;
            j--;
        }
    }
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
    return;    
}
long pp(long x)
{
    long i,j,k;
    for(i=1;i<=like[x][0];i++)
        if(vi[like[x][i]]==0)
        {
            if(s[like[x][i]]>0)
            {
                ans[x]=like[x][i];
                s[like[x][i]]--;
                p[like[x][i]][0]++;
                p[like[x][i]][p[like[x][i]][0]]=x;
                return 1;
            }
            else
                for(j=1;j<=p[like[x][i]][0];j++)
                {
                    vi[like[x][i]]=1;
                    k=pp(p[like[x][i]][j]);
                    if(k==1)
                    {
                        ans[x]=like[x][i];
                        p[like[x][i]][j]=x;
                        return 1;
                    }
                }
        }
    return 0;
}
int main()
{
    freopen("Magina.in","r",stdin);
    freopen("Magina.out","w",stdout);
    long long i,j,k,q;
    scanf("%I64d%I64d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%I64d",&s[i]);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&v[i]);
        num[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&like[i][0]);
        for(j=1;j<=like[i][0];j++)
            scanf("%I64d",&like[i][j]);
    }
    qsort(1,n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)        
            vi[j]=0;
        pp(i);
    }
    for(i=1;i<=n;i++)
        if(ans[i]!=0)
            sum+=v[i];
    printf("%I64d\n",sum);
    for(i=1;i<=n;i++)
        printf("%I64d %I64d\n",num[i],ans[i]);
    return 0;
}
