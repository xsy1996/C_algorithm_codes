/*
ID:xsy19962 
TASK:heritage
LANG:C++
*/
#include<stdio.h>
#include<string.h>
char tree[10001],a[101],b[101];
long t=0,len1,len2;
void dfs(long x,long l,long r)
{
    long i,j,k;
    if(l>r)
        return;
    t++;
    tree[x]=b[t];
    for(i=l;i<=r;i++)
        if(a[i]==b[t])
        {
            dfs(2*x,l,i-1);
            dfs(2*x+1,i+1,r);
            break;
        }
    return;
}
void out(long x)
{
    if(tree[2*x]!=0)
        out(2*x);
    if(tree[2*x+1]!=0)    
        out(2*x+1);
    printf("%c",tree[x]);
    return;
}
int main()
{
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    long i,j,k;
    gets(a+1);
    gets(b+1);
    len1=strlen(a+1);
    len2=strlen(b+1);
    dfs(1,1,len1);
    out(1);
    printf("\n");
    return 0;
}   
