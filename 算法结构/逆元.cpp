#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=1010000,MOD=1000000007;

long long f[MAXN*2],ans;


long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//*********求逆元素*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}


int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    long long last;
    cin>>n;
    f[0]=1;
    ans=1;
    last=0;
    for(int i=1;i<=2*n;i++)
    {
        f[i]=(2*f[i-1]-2*last+2*MOD)%MOD;
        ans+=f[i];
        ans%=MOD;
       // cout<<f[i]<<endl;
        if(i==n)
            last=1;
        else if(i>n)
            last=last*i%MOD*inv(i-n,MOD)%MOD;
    }
    cout<<ans%MOD<<endl;
    return 0;
}
