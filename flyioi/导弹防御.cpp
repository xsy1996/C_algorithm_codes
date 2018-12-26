#include<stdio.h>

int x[1001],y[1001];

int main(){
    int a,b,c=0,d=0,i,j,k,n;
    freopen("missile.in","r",stdin);
    freopen("missile.out","w",stdout);
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=n;i++)
      y[i]=1;
    for(i=2;i<=n;i++)
      for(j=1;j<i;j++)
        if(x[j]>=x[i] && y[i]<(y[j]+1))
          y[i]=y[j]+1;
            
  
    for(i=1;i<=n;i++)
      if(y[i]>d)
        d=y[i];
        
    printf("%d\n",d);
     
  
    return 0;
    }
