#include<stdio.h>
#include<stdlib.h>
long sum=0,n,t;
void hf(int x,int y,int z){
     long i,j,k,a,b;
     if(x>0 && y==1){
       sum++;
       return;
       }
     for(i=z;i<=x/y;i++)
       hf(x-i,y-1,i);
     return;
     }
int main(){
    long i,j,k;
    scanf("%ld%ld",&n,&t);
    hf(n,t,1);
    printf("%ld\n",sum);
    system("pause");
    return 0;
    }
