/*
ID:xsy19962
TASK:agrinet 
LANG:C++
*/
#include<stdio.h>
long f[101],n,map[101][101],v[101],ans=0,min;
int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    long i,j,k,s;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%ld",&map[i][j]);
    v[1]=1;
    s=1;
    while(s<n)
    {
        min=2147483600;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(v[i]==1 && v[j]==0 && map[i][j]<min)
                {
                    min=map[i][j];
                    k=j;
                }
        if(min!=2147483600)
        {    
            v[k]=1;
            ans+=min;
            s++;
        }
    }
    printf("%ld\n",ans);
    return 0;
}
