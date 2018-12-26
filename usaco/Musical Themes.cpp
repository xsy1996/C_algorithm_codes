/*
ID:xsy19962
TASK:theme 
LANG:C++
*/
#include<stdio.h>
long a[5001],s[5001],sa[5001],rank[5001],h[5001],n,ans=0,s1[5001],v1[5001],v2[5001];
void qsort(long l,long r)
{
    long i,j,k,x,y;
    i=l;j=r;
    x=a[sa[(i+j)/2]];
    while(i<=j)
    {
        while(a[sa[i]]<x)i++;
        while(a[sa[j]]>x)j--;
        if(i<=j)
        {
            k=sa[i];
            sa[i]=sa[j];
            sa[j]=k;
            rank[sa[i]]=i;
            rank[sa[j]]=j;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
long ok(long k)
{
    long i,j,min=sa[1],max=sa[1];
    for(i=1;i<=n;i++)
    {
        if(h[sa[i]]<k)
        {
            min=sa[i];
            max=sa[i];
        }
        else
        {
            if(sa[i]<min)
                min=sa[i];
            if(sa[i]>max)
                max=sa[i];
        }
        if(max-min>k)
            return 1;
  /*  printf("\n\n%d %d\n\n\n",min,max);*/
    }        
    return 0;
}
void find(long l,long r)
{
    long i,j,k;
    if(l==r)
        return;
    if(ok((l+r)/2))
    {
        if((l+r)/2>ans)
            ans=(l+r)/2;
        find((l+r)/2+1,r);
    }
    else
        find(l,(l+r)/2);
    return;
}
void c(long x)
{
    long i,j,k=h[x-1]-1;
    if(k<0)
        k=0;
    while(a[x+k]==a[sa[rank[x]-1]+k])
        k++;
    h[x]=k;
    return;
}
void px(long x)
{
    long i,j,k;
    for(i=0;i<=n;i++)
        s1[i]=0;
    for(i=1;i<=n;i++)
        s1[rank[i]]++;
    for(i=1;i<=n;i++)
        s1[i]+=s1[i-1];
    for(i=1;i<=x;i++)
        v1[i]=n-i+1;
    k=x;
    for(i=1;i<=n;i++)
        if(sa[i]-x>0)
        {
            k++;
            v1[k]=sa[i]-x;
        }
    for(i=n;i>=1;i--)
    {
        sa[s1[rank[v1[i]]]]=v1[i];
        s1[rank[v1[i]]]--;  
    }
    for(i=1;i<=n;i++)
        v2[i]=rank[i];
    for(i=1;i<=n;i++)
        rank[sa[i]]=i;
    for(i=2;i<=n;i++)
        if(v2[sa[i]]==v2[sa[i-1]] && v2[sa[i]+x]==v2[sa[i-1]+x])
            rank[sa[i]]=rank[sa[i-1]];
    return;
}
int main()
{
    freopen("theme.in","r",stdin);
    freopen("theme.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        if(i>1)
        {
            a[i-1]=s[i]-s[i-1];
            sa[i-1]=i-1;
            rank[i-1]=i-1;
        }
    }
    a[n]=-100;
    sa[n]=n;
    rank[n]=n;
    qsort(1,n);
    for(j=1;j<=n;j++)
        if(a[sa[j]]==a[sa[j-1]])
            rank[sa[j]]=rank[sa[j-1]];
    for(i=1;i<n;i*=2)
        px(i);
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=sa[i];j<=n;j++)
            printf("%d ",a[j]);*/
    for(i=1;i<=n;i++)
            c(i);
  /*  for(i=1;i<=n;i++)
        printf("%d ",h[sa[i]]);*/
    find(1,n);
    if(ans+1<5)
        printf("0\n");
    else
        printf("%d\n",ans+1);
    return 0;    
}
