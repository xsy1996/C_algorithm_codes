/*
ID:xsy19962
TASK:kimbits
LANG:C++
*/
#include<stdio.h>
long long n,l,m,s[101][101];
long long count(long long a,long long b)
{
    long i,j,k;
    if(s[a][b]!=0)
        return s[a][b];
    if(a>n || b==0)    
        return 1;
    s[a][b]=count(a+1,b)+count(a+1,b-1);
  //  printf("%d %d %d\n",a,b,s[a][b]);
    return s[a][b];
}
int main()
{
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    long long i,j,k,q;
    scanf("%lld%lld%lld",&n,&l,&m);
    for(i=1;i<=n;i++)
        if(count(i+1,l)>=m)
            printf("0");
        else
        {
            printf("1");
            m-=count(i+1,l);
            l--;
        }
    printf("\n");
    return 0;
}
