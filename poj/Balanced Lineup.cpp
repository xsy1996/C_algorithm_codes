#include<stdio.h>
long m,n,h[50001],tree[50001][3],f[50001],x[400001],y[400001],num[400001],fi[50001],l[50001],ans1[200001],ans2[200001],head,v[50001];
void qsort(long l,long r)
{
    long i,j,k,a;
    i=l;j=r;a=x[(i+j)/2];
    while(i<=j)
    {
        while(x[i]<a)i++;
        while(x[j]>a)j--;
        if(i<=j)
        {
            k=x[i];
            x[i]=x[j];
            x[j]=k;
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            k=num[i];
            num[i]=num[j];
            num[j]=k;
            i++;
            j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
long father(long s)
{
    if(f[s]!=s)
        f[s]=father(f[s]);
    return f[s];
}
void dfs1(long s)
{
    long i,j,k;
    f[s]=s;
    v[s]=1;
    for(i=fi[s];i<=l[s];i++)
    {
        if(v[x[i]]==1 && v[y[i]]==1)
        {
            if(s==x[i])
                ans1[num[i]]=h[father(y[i])];
            if(s==y[i])
                ans1[num[i]]=h[father(x[i])];
        }
    }
    if(tree[s][1]!=0)
    {
        dfs1(tree[s][1]);
        f[tree[s][1]]=s;
    }
    if(tree[s][2]!=0)
    {
        dfs1(tree[s][2]);
        f[tree[s][2]]=s;
    }
    return;
}
void dfs2(long s)
{
    long i,j,k;
    f[s]=s;
    v[s]=1;
    for(i=fi[s];i<=l[s];i++)
    {
        if(v[x[i]]==1 && v[y[i]]==1)
        {
            if(s==x[i])
                ans2[num[i]]=h[father(y[i])];
            if(s==y[i])
                ans2[num[i]]=h[father(x[i])];
        }
    }
    if(tree[s][1]!=0)
    {
        dfs2(tree[s][1]);
        f[tree[s][1]]=s;
    }
    if(tree[s][2]!=0)
    {
        dfs2(tree[s][2]);
        f[tree[s][2]]=s;
    }
    return;
}
int main()
{
  //  freopen("1.in","r",stdin);
  //  freopen("1.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x[2*i-1],&y[2*i-1]);
        x[2*i]=y[2*i-1];
        y[2*i]=x[2*i-1];
        num[2*i-1]=i;
        num[2*i]=i;
    }
    qsort(1,2*m);
    k=0;
    for(i=1;i<=2*m+1;i++)
        if(k!=x[i])
        {
            l[k]=i-1;
            k=x[i];
            fi[k]=i;
        }
    head=1;
    for(i=2;i<=n;i++)
    {
        k=head;
        while(tree[k][2]!=0 && h[k]>h[i])
            k=tree[k][2];
        if(h[k]<=h[i])
        {
            tree[i][0]=tree[k][0];
            if(tree[k][0]!=0)
                tree[tree[k][0]][2]=i;
            else
                head=i;
            tree[k][0]=i;
            tree[i][1]=k;
        }
        else
        {
            tree[k][2]=i;
            tree[i][0]=k;
        }
    }
    dfs1(head);    
    for(i=1;i<=n;i++)
    {
        tree[i][1]=0;
        tree[i][2]=0;
        tree[i][0]=0;
        f[i]=0;
        v[i]=0;
    }
    head=1;
    for(i=2;i<=n;i++)
    {
        k=head;
        while(tree[k][2]!=0 && h[k]<h[i])
            k=tree[k][2];
        if(h[k]>=h[i])
        {
            tree[i][1]=k;
            if(head!=k)
            {
                tree[tree[k][0]][2]=i;
                tree[i][0]=tree[k][0];
            }
            else
                head=i;
            tree[k][0]=i;
        }
        else
        {
            tree[i][0]=k;
            tree[k][2]=i;
        }
    }
 /*   for(i=1;i<=n;i++)
        printf("%d %d %d %d\n",i,tree[i][0],tree[i][1],tree[i][2]);
    printf("%d\n",head);*/
    dfs2(head);
 /*   for(i=1;i<=2*m;i++)
        printf("%d %d\n",x[i],y[i]);
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d %d\n",fi[i],l[i]);*/
    for(i=1;i<=m;i++)
    {
      //  printf("%d %d\n",ans1[i],ans2[i]);
        printf("%d\n",ans1[i]-ans2[i]);
    }
    return 0;
}
