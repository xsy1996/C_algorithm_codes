#include<stdio.h>
long tree[1000][1000],f[1001][3],m[1001],ans,n,s,v[1001];
void dfs(long x)
{
    long i,j,k=0,min2,min3,a,b;
    min2=0,min3=0;b=2147483600;
    for(i=1;i<=n;i++)
        if(tree[x][i]==1)
        {
            k=1;
            dfs(i);
            a=2147483600;
            if(f[i][0]<f[i][1])
            {
                min2+=f[i][0];
                a=f[i][0];
            }
            else
            {
                min2+=f[i][1];
                a=f[i][1];
            }
            if(f[i][0]-f[i][1]<b)
                b=f[i][0]-f[i][1];
            if(f[i][2]<a)
                a=f[i][2];
            min3+=a;
        }
    if(b<0)
        b=0;
    if(k==0)
        f[x][1]=2147483600;
    else
        f[x][1]=min2+b;
    f[x][2]=min2;
    a=min2;
    if(min3<a)
        a=min3;
    f[x][0]=a+m[x];    
  //  printf("%d %d %d %d\n",x,f[x][0],f[x][1],f[x][2]);
    return;
}
int main()
{
    freopen("security.in","r",stdin);
    freopen("security.out","w",stdout);
    long i,j,k,a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&m[a]);
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&b);
            v[b]=1;
            tree[a][b]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
            s=i;
    }
    dfs(s);
    ans=f[s][1];
    if(f[s][0]<ans)
        ans=f[s][0];
    printf("%d\n",ans);
    return 0; 
}
