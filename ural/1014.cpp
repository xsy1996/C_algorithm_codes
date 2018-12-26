#include<stdio.h>
#include<stdlib.h>
int a[1000001];
int main(){
    long long n,i,flag=0,j,k,t=0;
    scanf("%I64d",&n);
    if(n<=9){
      if(n==0)
        printf("10\n");
      else
        printf("%d\n",n);
      system("pause");
      return 0;
      }
    for(i=9;i>=2;i--)
      while(n%i==0){
          n/=i;
          t++;
          a[t]=i;
          }
    if(n>1)
      printf("-1\n");
    else{
      for(i=t;i>=1;i--)
        printf("%d",a[i]);
      printf("\n");
      }
    system("pause");
    return 0;
    }
