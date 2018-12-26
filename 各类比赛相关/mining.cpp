#include<stdio.h>
long long n,m,v[10001],map[1001][1001],e[10001],dfn[10001],t=1,low[10001],s[10001],ans1,ans2,s1,s2,f[10001],vv[1001];
void dfs(long long a)
{
    long long i,j,k;
    t++;
    low[a]=t;
    dfn[a]=t;
 //   printf("%I64d->\n",a);
    for(i=1;i<=e[a];i++)
        if(map[a][i]!=f[a])
        {
            if(v[map[a][i]]==0)
            {
                v[map[a][i]]=1;
                f[map[a][i]]=a;
                dfs(map[a][i]);
                if(low[map[a][i]]<low[a])
                    low[a]=low[map[a][i]];
            }
            else if(dfn[map[a][i]]<low[a])
                low[a]=dfn[map[a][i]];
            if(low[map[a][i]]>=dfn[a])
            {
                s[a]=1;
            //    printf("gedian : %I64d\n",a);
            }
          //  printf("%I64d    f: %I64d  to: %I64d  dfn: %I64d  sonlow: %I64d  low: %I64d\n",a,f[a],map[a][i],dfn[a],low[map[a][i]],low[a]);
        }
    return;
}
void floodfill(long long a)
{
    long long i,j,k;
    for(i=1;i<=e[a];i++)
        if(v[map[a][i]]==0)
        {
            if(s[map[a][i]]==1)
            {
                if(vv[map[a][i]]==0)
                    s1++; 
                vv[map[a][i]]=1; 
                continue;
            }
            s2++;
            v[map[a][i]]=1;
            floodfill(map[a][i]);
        }
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long i,j,k,x,y,q;
    q=0;
    scanf("%I64d",&n);
    while(n!=0)
    {
        q++;
        m=0;
        ans1=0;
        ans2=1;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&x,&y);
            e[x]++;
            e[y]++;
            map[x][e[x]]=y;
            map[y][e[y]]=x;
            if(x>m)
                m=x;
            if(y>m)
                m=y;
        }
        v[m]=1;
        dfn[m]=1;
        low[m]=1;
        k=0;
        for(i=1;i<=e[m];i++)
            if(v[map[m][i]]==0)
            {
                k++;
                f[map[m][i]]=m;
                v[map[m][i]]=1;
                dfs(map[m][i]);
            }
        if(k>1)
            s[m]=1;
       /* for(i=1;i<=m;i++)
            printf("%I64d %I64d\n",i,s[i]);*/
        for(i=1;i<=m;i++)
            v[i]=0;
        for(i=1;i<=m;i++)
            if(s[i]==0 && v[i]==0 && e[i]!=0)
            {
                s1=0;
                s2=1;
                v[i]=1;
                for(j=1;j<=m;j++)
                    vv[j]=0;
                floodfill(i);
                if(s1==0)
                {
                    ans1+=2;
                    ans2*=s2*(s2-1)/2;
                }
                if(s1==1)
                {
                    ans1+=1;
                    ans2*=s2;
                }
               // printf("%I64d %I64d %I64d\n",i,s1,s2);
            }
        printf("Case %I64d: %I64d %I64d\n",q,ans1,ans2);
        for(i=1;i<=m;i++)
        {
            v[i]=0;
            e[i]=0;
            s[i]=0;
            dfn[i]=0;
            low[i]=0;
        }
        scanf("%I64d",&n);
    }
    return 0;    
}
