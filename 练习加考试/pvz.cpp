#include<stdio.h>
#include<stdlib.h>
long long ss[10001],r[10001],v[10001];
long long map[1001][1001],c[1001][1001],sum=0,n,m,s[10001],flag,path[10001],t=0,f,l,dl[10001];
void find(){
    long long i,j,k,min=2147483600;
    for(i=1;i<t;i++)
        if(map[path[i]][path[i+1]]-c[path[i]][path[i+1]]<min)
            min=map[path[i]][path[i+1]]-c[path[i]][path[i+1]];
    for(i=1;i<t;i++){
        c[path[i]][path[i+1]]+=min;
        c[path[i+1]][path[i]]-=min;
        }
    sum+=min;
    return;
    }
void dfs(long long x){
    long long i,j,k;
    if(x==n){
        
        find();
        return;
        }
    for(i=2;i<=n;i++)
        if((s[i]==s[x]+1 || i==n) && c[x][i]<map[x][i]){
            t++;
            path[t]=i;
            dfs(i);
            t--;
            }
    return;
    }
void cct(){
    long long i,j,k;
    f=0;l=1;
    for(i=1;i<=n;i++){
        v[i]=0;
        s[i]=-1;
        }
    s[1]=0;
    dl[1]=1;
    v[1]=1;
    int ii;
    while(f<l)
    {
        f++;
        for(j=1;j<=n;j++)
            if(c[dl[f]][j]<map[dl[f]][j] && v[j]==0)
            {
           // printf("%I64d %I64d %I64d\n",f,l,j);
                v[j]=1;
      /*    for(ii=1;ii<=n;ii++)
            printf("%d",v[ii]);
            printf("\n");*/
                if(j==n)
                    flag=1;
                else
                {              
                    l++;
                    dl[l]=j;
                    s[dl[l]]=s[dl[f]]+1;  
                }
            }
       // printf("\n");
    } 
    return;
}
void dinic(){
    long long i,j,k; 
    while(1){
        flag=0;
        cct();
        if(flag==0)
            break;
        t=1;
        path[1]=1;
        dfs(1);
    }
    return;
}
int main()
{
    freopen("pvz.in","r",stdin);
    freopen("pvz.out","w",stdout);
    long long i,j,k,x,y,ans=0,flag;
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%I64d",&ss[i*m+j+1]);
            scanf("%I64d",&k);
            for(;k>=1;k--)
            {
                scanf("%I64d%I64d",&x,&y);
                y++;
                map[x*m+y+1][i*m+j+1]=2147483600;
                r[x*m+y+1]++;
            }
        }
    for(i=0;i<n;i++)
        for(j=1;j<m;j++)
        if(map[i*m+j+1][i*m+j+2]==0)
        {
            map[i*m+j+1][i*m+j+2]=2147483600;
            r[i*m+j+1]++;
        }
    k=0;
   /* for(i=2;i<=n*m+1;i++)
        printf("%I64d ",r[i]);*/
    while(k==0)
    {
        k=1;
        for(i=2;i<=n*m+1;i++)
            if(r[i]==0 && v[i]==0)
            {
                v[i]=1;
                for(j=2;j<=n*m+1;j++)
                    if(map[j][i]!=0)
                        r[j]--;
                k=0;
            }
    }
    for(i=2;i<=n*m+1;i++)
        if(r[i]!=0)
            for(j=0;j<=n*m+2;j++)
            {
                map[i][j]=0;
                map[j][i]=0;
            }
   // printf("\n");
  /*  for(i=2;i<=n*m+1;i++)
        printf("%I64d ",r[i]);*/
    for(i=2;i<=n*m+1;i++)
        if(r[i]==0)
        {
            if(ss[i]>=0)
            {
                map[1][i]=ss[i];
                ans+=ss[i];
            }
            else
                map[i][n*m+2]=-1*ss[i];
        }
    n=n*m+2;
    for(i=1;i<=n;i++)
        v[i]=0;
    dinic();
    printf("%I64d\n",ans-sum);
    return 0;
}
