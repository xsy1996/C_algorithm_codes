/*
ID:xsy19962
TASK:range
LANG:C++
*/
#include<stdio.h>
long min(long a,long b,long c)
{
    long k;
    k=(a<b)?a:b;
    if(c<k)
        k=c;
    return k;
}
long n,f[1001][1001],line[1001][1001],row[1001][1001],s[250];
bool map[1001][1001];
int main()
{
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    long i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%1d",&map[i][j]);
            if(map[i][j])
            {
                line[i][j]=line[i-1][j]+1;
                row[i][j]=row[i][j-1]+1;
            }
        }   
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(map[i][j])
            {
                f[i][j]=min(f[i-1][j-1],line[i-1][j],row[i][j-1])+1;
                for(k=2;k<=f[i][j];k++)
                    s[k]++;   
            }
    for(i=2;i<=n;i++)
        if(s[i]>0)
            printf("%d %d\n",i,s[i]);
    return 0;
}
