#include<stdio.h>
long c[5],max,min,q,w,p[1001][1001],t[1001],n,m,flag=0;
void dfs(long x)
{
    long i,j,k;
    if(flag==1)
        return;
    for(i=1;i<=m;i++)
        if(p[i][0]>q)
            return;
    if(x==n)
    {
        min=2147483600;max=0;
        for(i=1;i<=m;i++)
        {
            if(p[i][0]<min)
                min=p[i][0];
            if(p[i][0]>max)
                max=p[i][0];
        }
        if(max-min<=3)
        {
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=t[i];j++)
                    printf("%d ",p[i][j]);
                printf("\n");
            }
            flag=1;
        }
    }
    if(c[3]>0)
    {
        c[3]--;
        for(i=1;i<=m;i++)
        {
            t[i]++;
            p[i][t[i]]=3;
            p[i][0]+=3;
            dfs(x+1);
            t[i]--;
            p[i][0]-=3;
        }
        c[3]++;
    }
    else if(c[2]>0)
    {
        c[2]--;
        for(i=1;i<=m;i++)
        {
            t[i]++;
            p[i][t[i]]=2;
            p[i][0]+=2;
            dfs(x+1);
            t[i]--;
            p[i][0]-=2;
        }
        c[2]++;
    }
    else if(c[1]>0)
    {
        c[1]--;
        for(i=1;i<=m;i++)
        {
            t[i]++;
            p[i][t[i]]=1;
            p[i][0]+=1;
            dfs(x+1);
            t[i]--;
            p[i][0]-=1;
        }
        c[1]++;
    }
    return;
}
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    long i,j,s=0,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        c[k]++;
        s+=k;
    }
    q=s/m+3;
    dfs(0);
    return 0;
}
