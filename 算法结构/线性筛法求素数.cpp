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

const int MAXN=1010,INF=1000000007,MOD=1000000007;

bool isNotPrime[MAXN];
int prime[MAXN],num_prime=0;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(long i = 2 ; i < MAXN ; i ++)         
        {              
        if(! isNotPrime[i])                 
            prime[num_prime ++]=i;    
        //关键处1          
        for(long j = 0 ; j < num_prime && i * prime[j] <  MAXN ; j ++)  
            {                 
                isNotPrime[i * prime[j]] = 1;    
            if( !(i % prime[j] ) )  //关键处2                    
                break;             
        }          
    }      
    return 0;
}