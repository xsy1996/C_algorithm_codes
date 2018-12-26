/*
ID:xsy19962 
TASK:fence8
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
long n,m,rail[10001],board[100001];
long great(long a,long b)
{
    if(a>b)
        return 1;
    else
        return 0;
}
long search(long k,long x)
{
    long i,j=1,l=0;
    if(k==0)
        return 1;
    if(rail[k]==rail[k+1])
        j=x;
    for(i=1;i<=n;i++)
        if(board[i]>=rail[1])
            l+=board[i];
    for(i=1;i<=k;i++)
        l-=rail[i];
    if(l<0)
        return 0;
    for(i=j;i<=n;i++)
        if(board[i]==rail[k])
        {
            board[i]=0;
            l=search(k-1,1);
            board[i]=rail[k];
            return l;
        }
    for(i=j;i<=n;i++)
        if(board[i]>rail[k])
        {
            board[i]-=rail[k];
            l=search(k-1,i);
            board[i]+=rail[k];
            if(l==1)
                return 1;
        }
    return 0;
}
int main()
{
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&board[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&rail[i]);
    sort(rail+1,rail+m+1);
    sort(board+1,board+n+1,great);    
    for(i=1;i<=m;i++)
        if(search(i,1)==0)
            break;
    printf("%d\n",i-1);
    return 0;
}
