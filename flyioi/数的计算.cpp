#include<stdio.h>
#include<stdlib.h>
int sum=1;
void js(int s){
     int a,b,i,j;
     for(i=1;i<=s/2;i++){
       sum++;
       js(i);
       }
     return;
     }
int main(){
    int a;
    scanf("%d",&a);
    js(a);
    printf("%d\n",sum);
    system("pause");
    }
