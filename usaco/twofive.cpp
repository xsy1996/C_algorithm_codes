/*
ID:xsy19962
TASK:twofive
LANG:C++
*/
#include<stdio.h>
#include<cstring>
#define ok(i) ((v[i])==0 || (v[i])==(x)+'A')
long f[10][10][10][10][10],ans=0,map[10][10];
char v[101],a[101];
long dfs(long a,long b,long c,long d,long e,long x)
{
    if(x==25)
        return 1;
    if(f[a][b][c][d][e]>0)
        return f[a][b][c][d][e];
    if(a<5 && ok(a))
        f[a][b][c][d][e]+=dfs(a+1,b,c,d,e,x+1);
    if(b<a && ok(b+5))
        f[a][b][c][d][e]+=dfs(a,b+1,c,d,e,x+1);
    if(c<b && ok(c+10))
        f[a][b][c][d][e]+=dfs(a,b,c+1,d,e,x+1);
    if(d<c && ok(d+15))
        f[a][b][c][d][e]+=dfs(a,b,c,d+1,e,x+1);
    if(e<d && ok(e+20))
        f[a][b][c][d][e]+=dfs(a,b,c,d,e+1,x+1);
    return f[a][b][c][d][e];
}
int main()
{
    freopen("twofive.in","r",stdin);
    freopen("twofive.out","w",stdout);
    long i,j,k;
    char o;
    scanf("%c",&o);
    if(o=='W')
    {
        getchar();
        gets(a);
        long s=0;
        for(i=0;i<=24;i++)
            for(v[i]='A';v[i]<a[i];v[i]++)
            {
                memset(f,0,sizeof(f));
                s+=dfs(0,0,0,0,0,0);
            }
        printf("%d\n",s+1);
    }
    else
    {
        long n,tmp;
        scanf("%d",&n);
        for(i=0;i<=24;i++)
            for(v[i]='A';memset(f,0,sizeof(f)),(tmp=dfs(0,0,0,0,0,0))<n;v[i]++)
                n-=tmp;
        printf("%s\n",v);
    }
    return 0;
}
