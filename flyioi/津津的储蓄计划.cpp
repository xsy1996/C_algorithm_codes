#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b=0,c,d,i,j=0,k,n,sum=0;
    for(i=1;i<=12;i++){
      scanf("%d",&a);
      c=(300+b)-a; 
      if(c>=0){
        sum+=c/100;
        b=c%100;        
        }
      if(c<0){
      printf("-%d\n",i);
      system("pause");   
        return 0;
        }
      }
    

      printf("%d\n",120*sum+b);
      
    system("pause");
    return 0;
    } 
