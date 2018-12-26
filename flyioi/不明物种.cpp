#include<stdio.h>
#include<stdlib.h>

int main(){
    long a,b,c,d,i,j=0,k,n;
    scanf("%d",&a);
    j=1;b=1;c=1;d=1;
    for(i=4;i<=a;i++){
      j=(2*d+b)%1000000;
      d=c; 
      c=b;
      b=j;
      }printf("%ld\n",j);
    system("pause");
    return 0;
    }
