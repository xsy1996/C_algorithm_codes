#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define Abs(a) (((a)>0)?(a):(-1*(a)))

using namespace std;

const int MAXN=1100,INF=1000000007,MOD=100003;


long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0)
    {
        x=0;y=1;
        return b;
    }
    long long r=exgcd(b%a,a,x,y),k;
    k=y;
    y=x;
    x=k-b/a*x;
    return r;
}


long long m,n,t1,t2;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    return 0;
}
