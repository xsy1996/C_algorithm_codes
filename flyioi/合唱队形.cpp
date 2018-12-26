#include<stdio.h>
#include<stdlib.h>
int x[101],y[101],z[101];

int main(){
    int a,b,c=0,d=0,i,j,k,n;
    
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=n;i++){
      y[i]=1;
      z[i]=1;
      }
    for(i=2;i<=n;i++)
      for(j=1;j<i;j++)
        if(x[j]<x[i] && y[i]<(y[j]+1))
          y[i]=y[j]+1;
     
    for(i=n-1;i>=1;i--)
      for(j=n;j>i;j--)
        if(x[j]<x[i] && z[i]<(z[j]+1))
          z[i]=z[j]+1;    
        
    for(i=1;i<=n;i++)
      if((y[i]+z[i])>d)
        d=(y[i]+z[i]);
        
    printf("%d\n",n-d+1);
     
    system("pause");
    return 0;
    }
