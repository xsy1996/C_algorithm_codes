#include<stdio.h>
#include<stdlib.h>
int x[1001],y[1001],z[1001];

int main(){
    int a,b,c,d=0,i,j,k,n=1;
    char s;
    scanf("%d",&x[1]);
    scanf("%c",&s);
    
    while(s==' '){
    n++;
    scanf("%d",&x[n]);
    scanf("%c",&s);
    }
    
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
    
    z[1]=x[1];
    k=1;
    for(i=2;i<=n;i++){
      for(j=1;j<=k;j++)
        if(x[i]<=z[j])
        {
          z[j]=x[i];
          break;
          }
        if(j==(k+1))
        {
          k++;
          z[k]=x[i];  
          }
      
      }
   
    printf("%d\n",k);
   system("pause");
    return 0;
    }

