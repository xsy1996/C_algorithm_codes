#include<stdio.h>
#include<stdlib.h>
int x[1000001];
int main(){
    int a,b,c,i,j,k,n,s=0;
    scanf("%d%d",&n,&a);
    for(i=1;i<=n;i++){
      scanf("%d",&b);
      x[i]=x[i-1]+b;
      }
    j=0;
    for(i=1;i<=n;i++){
      while(j<i && (x[i]-x[j])>a)
        j++;
      if((i-j)>s)
        s=i-j;
       } 
     printf("%d",s);
      system("pause");
    return 0;
    }
