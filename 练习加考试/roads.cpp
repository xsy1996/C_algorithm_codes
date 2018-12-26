#include<stdio.h>
long f[201][201],t[201],tree[201][201],son[201],fa[201],n,m,root;
void dfs(long x)
{
    long i,j,k;
    for(i=1;i<=t[x];i++)
    {
        if(t[tree[x][i]]>0)
            dfs(tree[x][i]);
        else
            f[tree[x][i]][1]=1;
        son[x]+=son[tree[x][i]];
    }
    f[x][son[x]]=1;
    for(i=1;i<=t[x];i++)
        for(j=son[x]-1;j>0;j--)
            for(k=1;k<=son[tree[x][i]] && k<=j;k++)
                if(f[tree[x][i]][k]>0 && (j==k || f[x][j-k]>0) && (f[x][j]==0 || f[tree[x][i]][k]+f[x][j-k]<f[x][j]))
                    f[x][j]=f[tree[x][i]][k]+f[x][j-k];
    return;
}
int main()
{
    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);
    long i,j,k,x,y;
    scanf("%d%d",&n,&m);
	if(n==1){
		printf("0\n");	
		return 0;
	}
	if(m==1){
		printf("1\n");
		return 0;
	}
    for(i=1;i<=n;i++)
        son[i]=1;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        fa[y]=x;
        t[x]++;
        tree[x][t[x]]=y;
    }
    root=1;
    while(fa[root]!=0)
        root=fa[root];
    dfs(root);
    k=f[root][n-m];
    for(i=1;i<=n;i++)
        if(son[i]>=m && f[i][son[i]-m]+1<k)
        {
            k=f[i][son[i]-m]+1;
            //printf("%d %d\n",i,k);
        }
    printf("%d\n",k);
    return 0;
}
