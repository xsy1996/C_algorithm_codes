#include<stdio.h>
int x[1000][1001];
int main(){ 
    long a=0,i,j,n;
    freopen("sjx.in","r",stdin);
    freopen("sjx.out","w",stdout);
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      for(j=1;j<=i;j++)    
        scanf("%d",&x[i][j]);
    
    for(i=2;i<=n;i++)
      for(j=1;j<=i;j++){
         if(x[i-1][j]>x[i-1][j-1])
           x[i][j]+=x[i-1][j];
         else
           x[i][j]+=x[i-1][j-1];
        }
    for(i=1;i<=n;i++)
      if(x[n][i]>a)
        a=x[n][i];
    printf("%ld\n",a); 
    return 0;
    }
