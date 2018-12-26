/*
ID:xsy19962
TASK:frac1
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long v[161],ss[201],top=0,x[50001],y[50001],t=2;
double a[50001];
void qsort(long l,long r)
{
    long i,j,k;
    double s,b;
    i=l;j=r;
    s=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]<s)i++;
        while(a[j]>s)j--;
        if(i<=j)
        {
            b=a[i];
            a[i]=a[j];
            a[j]=b;
            k=x[i];
            x[i]=x[j];
            x[j]=k;
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
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    long i,j,k,n,flag;
    scanf("%d",&n);
    a[1]=1.0;x[1]=1;y[1]=1;
    a[2]=0.0;x[2]=0;y[2]=1;
    for(j=2;j<=n;j++)
        for(i=1;i<j;i++)
        {
            flag=0;
            for(k=2;k<=j;k++)
                if(i%k==0 && j%k==0)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                t++;
                a[t]=(i*1.0)/(j*1.0);
                x[t]=i;y[t]=j;
            }
        }
    qsort(1,t);
    for(i=1;i<=t;i++)
        printf("%d/%d\n",x[i],y[i]);
    return 0;    
}
