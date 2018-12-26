#include<stdio.h>
long long ans=2147483600,w[200001],v[200001],s,l[200001],r[200001],m,n,sum[200001],sumv[200001];
long long count(long long x)
{
    long long i,j,k=0,q,e;
    sum[0]=0;
    sumv[0]=0;
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        sumv[i]=sumv[i-1];
        if(w[i]>=x)
        {
            sum[i]++;
            sumv[i]+=v[i];
        }              
    }
    for(i=1;i<=m;i++)
        k+=(sum[r[i]]-sum[l[i]-1])*(sumv[r[i]]-sumv[l[i]-1]);
    return k;
}
long long jdz(long long x)
{
    if(x>=0)
        return x;
    else
        return -1*x;
}
void find(long long min,long long max)
{
    long long i,j,k;
    k=(min+max)/2;
    i=count(k);j=count(k+1);
    if((i>=s && j<=s) || max-min<=1)
    {
        ans*=1000000;
        if(jdz(i-s)<ans)
            ans=jdz(i-s);
        if(jdz(s-j)<ans)
            ans=jdz(s-j);
        return;
    }
    if(i<s)
        find(min,k);
    else
        find(k+1,max);
    return;
}
int main()
{
    FILE *fin=fopen("qc.in","r");
    FILE *fout=fopen("qc.out","w");
    long long i,j,k;
    fscanf(fin,"%I64d%I64d%I64d",&n,&m,&s);
    k=0;
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%I64d%I64d",&w[i],&v[i]);
        if(w[i]>k)
            k=w[i];
    }
    for(i=1;i<=m;i++)
        fscanf(fin,"%I64d%I64d",&l[i],&r[i]);
    find(0,k);
    fprintf(fout,"%I64d\n",ans);
    fclose(fin);
    fclose(fout);
    return 0;
}
