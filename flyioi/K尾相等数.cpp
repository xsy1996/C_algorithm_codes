#include<stdio.h>
#include<stdlib.h>
int v[1001];
int main(){
    long x,y,z=1,a=0,i,j,k,n;
    scanf("%ld",&n);
    if(n>1000){
      n%=1000;
      z=n;
      a=1;
      }
    else
      while(z<1000){
        z*=n;
        a++;
        }
    z%=1000;
    v[z]=a;  
    for(i=a+1;i<=1000000;i++){
      z*=n;
      if(z>=1000)
        z%=1000;
      if(v[z]==0)
        v[z]=i;
      else if(v[z]!=0){
        printf("%d\n",i+v[z]);
        break;
        }
      }
    system("pause");
    return 0;
    }
