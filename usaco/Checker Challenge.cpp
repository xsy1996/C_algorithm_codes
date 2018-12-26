/*
ID:xsy19962
TASK:checker
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long map[20],n,sum=0,a[20],b[100],c[100];
void dfs(long x)
{
    long i,j,k;
    if(x==n)
    {
        sum++;
        if(sum<=3)
        {
            printf("%d",map[1]);
            for(i=2;i<=n;i++) 
                printf(" %d",map[i]);
            printf("\n");
        }
        return;         
    }
    for(i=1;i<=n;i++)
        if(a[i]==0 && b[i+x+1]==0 && c[x+1-i+n]==0)
        {   
            a[i]=1;b[i+x+1]=1;c[x+1-i+n]=1;
            map[x+1]=i;
            dfs(x+1);
            a[i]=0;b[i+x+1]=0;c[x+1-i+n]=0;
        }        
    return;
}
int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    dfs(0);
    printf("%d\n",sum);
    return 0;
}
