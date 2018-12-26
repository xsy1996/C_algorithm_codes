/*
ID:xsy19962
TASK:contact 
LANG:C++
*/
#include<stdio.h>
long v[10001],d[10001],s[10001],t=0,n,a,b,q[101],w[101];
void out(long x)
{
    long i,j,k=0,e[101];
    while(x>0)
    {
        k++;
        e[k]=x%2;
        x/=2;
    }
    for(i=k-1;i>=1;i--)
        printf("%d",e[i]);
    return;
}
void qsort(long l,long r)
{
    long i,j,k,x,y;
    x=s[(l+r)/2];
    y=d[(l+r)/2];
    i=l;j=r;
    while(i<=j)
    {
        while(s[i]>x || (s[i]==x && d[i]<y))i++;
        while(s[j]<x || (s[j]==x && d[j]>y))j--;
        if(i<=j)
        {
            k=d[i];
            d[i]=d[j];
            d[j]=k;
            k=s[i];
            s[i]=s[j];
            s[j]=k;
            i++;j--;
        }    
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    long i,j,k,c;
    scanf("%d%d%d",&a,&b,&n);
    w[1]=2;
    for(i=2;i<=b;i++)
        w[i]=w[i-1]*2;
    k=0;
    while(scanf("%1d",&c)!=EOF)
    {
        k++;
        for(i=b;i>=1;i--)
            if(k>=i)
                q[i]=q[i-1]*2+c;
        for(i=a;i<=b;i++)
            if(k>=i)
                v[q[i]+w[i]]++;
    }
    for(i=w[a];i<=w[b]*2;i++)
        if(v[i]!=0)
        {
            t++;
            d[t]=i;
            s[t]=v[i];
        }
    qsort(1,t);
    printf("%d\n",s[1]);
    out(d[1]);
    for(i=2;i<=t;i++)
    {
        if(s[i]!=s[i-1])
        {
            k=1;
            n--;
            if(n==0)
                break;
            printf("\n%d\n",s[i]);
            out(d[i]); 
        }
        else
        {
            if(k==6)
            {
                printf("\n");
                k=0;
            }
            else 
                printf(" ");
            k++;
            out(d[i]);
        }
    }
    printf("\n");
    return 0;
}
