/*
ID:xsy19962
TASK:calfflac
LANG:C++
*/
#include<stdio.h>
long a[50001],b[50001],s[50001],sa[50001],rank[50001],h[50001],n,max=0,ans,s1[50001],v1[50001],v2[50001];
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
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    long i,j,k,x,y;
    char q;
    n=0;i=0;
    while(scanf("%c",&q)!=EOF)
    {
        i++;
        s[i]=q;
        if(q>='a' && q<='z')
        {
            n++;
            a[n]=q-'a'+1;
            b[n]=i;
        }
        if(q>='A' && q<='Z')
        {
            n++;
            a[n]=q-'A'+1;
            b[n]=i;
        }
    }
    n++;
    a[n]=-100;
    for(i=1;i<n;i++)
        a[n+i]=a[n-i];
    a[2*n]=-200;
    n*=2;
    for(i=1;i<=n;i++)
    {
        rank[i]=i;
        sa[i]=i;
    }
    qsort(1,n);
    for(j=1;j<=n;j++)
        if(a[sa[j]]==a[sa[j-1]])
            rank[sa[j]]=rank[sa[j-1]];
    for(i=1;i<n;i*=2)
        px(i);
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=sa[i];j<=n;j++)
            printf("%c ",a[j]+'a'-1);*/
    for(i=1;i<=n;i++)
            c(i);
 /*   for(i=1;i<=n;i++)
        printf("%d ",h[sa[i]]);*/
    for(i=1;i<=n/2-1;i++)
    {
        k=5001;
        x=rank[i];
        y=rank[n-i];
        if(x>y)
        {
            y=rank[i];
            x=rank[n-i];
        }
        for(j=x+1;j<=y;j++)
            if(h[sa[j]]<k)
                k=h[sa[j]];
        if(2*k-1>max)
        {
            max=2*k-1;
            ans=i-k+1;
        }
        k=5001;
        x=rank[i];
        y=rank[n-i+1];
        if(x>y)
        {
            y=rank[i];
            x=rank[n-i+1];
        }
        for(j=x+1;j<=y;j++)
            if(h[sa[j]]<k)
                k=h[sa[j]];
        if(2*k>max)
        {
            max=2*k;
            ans=i-k;
        }
    }
    printf("%d\n",max);
    for(i=b[ans];i<=b[ans+max-1];i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;    
}
