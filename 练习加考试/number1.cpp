#include<stdio.h>
#include<math.h>
long long f[201];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long i,j,k,a,b,s,x,y,ans=0;
    scanf("%I64d%I64d",&a,&b);
    for(i=100;i>=2;i--)
    {
        x=long(pow(a,1.0/i));
        y=long(pow(b,1.0/i));
        if(pow(x,i)<a)
            x++;
        s=y-x+1;
        for(j=2*i;j<=100;j+=i)
            s-=f[j];
        if(s>0)
            f[i]=s;
    }
    s=b-a+1;
    for(i=1;i<=100;i++)
        s-=f[i];
    f[1]=s;
    for(i=1;i<=100;i++)
        ans+=f[i]*i;
    printf("%I64d\n",ans);
    return 0;
}
