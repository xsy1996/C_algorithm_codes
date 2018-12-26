/*
ID:xsy19962
TASK:hamming
LANG:C++
*/
#include<stdio.h>
long n,b,d,max,path[101],t=0,flag=0;
long f(long a,long b)
{
    long i,j,k;
    k=a^b;
    i=0;
    while(k>0)
    {
        if(k%2==1)
            i++;
        k/=2;
    }
    if(i>=d)
        return 1;
    else
        return 0; 
}
void dfs(long x,long s)
{
    long i,j,k=0;
    if(flag==1)
        return;
    if(s==n)
    {
        flag=1;
        k=0;
        while(n>=10)
        {
            for(i=1;i<=9;i++)
                printf("%ld ",path[k+i]);
            printf("%d\n",path[k+10]);
            k+=10;
            n-=10;
        }    
        for(i=1;i<n;i++)
            printf("%ld ",path[k+i]);
        if(n!=0)
            printf("%ld\n",path[n+k]);
        return;
    }
    if(x>=max)
        return;
    for(i=1;i<=t;i++)
        if(f(x,path[i])==0)
        {
            k=1;
            break;
        }
    if(k==0)
    {
        t++;
        path[t]=x;
        dfs(x+1,s+1);
        t--;
    }
    dfs(x+1,s);
    return;
}
int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    long i,j,k;
    scanf("%d%d%d",&n,&b,&d);
    max=1;
    for(i=1;i<=b+1;i++)
        max*=2;      
    dfs(0,0);
    return 0;
}
