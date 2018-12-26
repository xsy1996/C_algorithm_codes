#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define Abs(a) (((a)>0)?(a):(-1*(a)))

using namespace std;

const int MAXN=20,INF=1000000007,MOD=1024523;

long long a[MAXN];
int m;

long long gcd(long long a,long long b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

long long cal(long long now,long long divi,long long dir,long long n)
{
	//cout<<now<<" "<<divi<<"  "<<dir<<endl;
	if(n==0)
		return 0;
	if(now>m)
	{
		return 0;
	}
	long long r,d;
	r=cal(now+1,divi,dir,n);
	d=divi/gcd(divi,a[now])*a[now];
	if(n>=d)
		r+=(n/d)*dir+cal(now+1,d,dir*(-1),n);
	return r;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cas=0,t;
    long long l,r,ans,n;
    cin>>t;
	while(++cas<=t)
	{
		cin>>l>>r>>n;
		int temp=n;
		m=0;
		for(int i=2;temp/i>=i;i++)
			if(temp%i==0)
			{
				a[++m]=i;
				while(temp%i==0)
					temp/=i;
			}
		if(temp>1)
			a[++m]=temp;
		ans=(r+cal(1,1,-1,r))-(l-1+cal(1,1,-1,l-1));
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
    return 0;
}