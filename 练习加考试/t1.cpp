#include<stdio.h>
long long f[101][101],p[101][101],t[101],m[101],v[101],w[101];
void qsort(long long l,long long r)
{
    long long i,j,k,x;
    i=l;j=r;
    x=v[(i+j)/2];
    while(i<=j)
    {
        while(v[i]<x)i++;
        while(v[j]>x)j--;
        if(i<=j)
        {
            k=v[i];
            v[i]=v[j];
            v[j]=k;
            k=t[i];
            t[i]=t[j];
            t[j]=k;
            k=m[i];
            m[i]=m[j];
            m[j]=k;
            k=w[i];
            w[i]=w[j];
            w[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
}
int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    long long i,j,k,n,mmax,tmax,q=0,a,b,c,max=0;
    scanf("%I64d%I64d%I64d",&n,&mmax,&tmax);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&v[i],&t[i],&m[i],&w[i]);
        if(m[i]>=mmax || t[i]>tmax)
        {
            n--;
            i--;
        }
    }
    f[0][0]=1;
    qsort(1,n);
    for(k=1;k<=n;k++)
    {
        q=0;
        while(v[k+q+1]==v[k] && k+q<n)
            q++;
        for(i=mmax-1;i>=0;i--)
            for(j=tmax;j>=0;j--)
                if(f[i][j]!=0)
                    for(a=0;a<=q;a++)
                        if(i+m[a+k]<mmax && j+t[a+k]<=tmax && f[i][j]+w[a+k]>f[i+m[a+k]][j+t[a+k]])
                            f[i+m[a+k]][j+t[a+k]]=f[i][j]+w[a+k];
        k+=q;
    }
    for(i=mmax-1;i>=0;i--)
        for(j=tmax;j>=0;j--)
            if(max<f[i][j])
                max=f[i][j];
    printf("%I64d\n",max-1);
    return 0;
}
