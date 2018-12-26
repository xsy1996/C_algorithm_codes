long long pow(long long x,long y)
{
    long long k=1;
    while(y)
    {
        if(y&1)
            k=x*k%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return k;
}



long long big_num_Mul(long long a,long long b)//大数乘法
{
    if(q>0)
    {
        long long k=Mul(a,b>>1);
        k<<=1;
        k%=mod;
        if(b%2==1)
            k+=a;
        k%=mod;
        return k;
    }
    return 0;
}
