/*
ID:xsy19962
TASK:sort3
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long x[10001],y[10001],ans=0,n;
void qsort(long l,long r)
{
    long i,j,k,s;
    i=l;j=r;
    s=y[(i+j)/2];
    while(i<=j)
    {
        while(y[i]<s)i++;
        while(y[j]>s)j--;
        if(i<=j)
        {
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
void change(long q)
{
    long i,j,k;
    ans++;
    for(i=1;i<=n;i++)
        if(x[i]==y[q] && y[i]==x[q])
        {
            k=x[i];
            x[i]=x[q];
            x[q]=k;
            return;
        }
    for(i=1;i<=n;i++)
        if(x[i]==y[q] && y[i]!=x[i])
        {
            k=x[i];
            x[i]=x[q];
            x[q]=k;
            change(i);
            return;
        }
    return;
}
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        y[i]=x[i];
    }
    qsort(1,n);
    for(i=1;i<=n;i++)
        if(x[i]!=y[i])
            change(i);
    printf("%d\n",ans);
    return 0;    
}
