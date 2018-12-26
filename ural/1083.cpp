#include<stdio.h>
#include<stdlib.h>
int main(){
    char a;
    long n,k=0,i,j,sum=1;
    scanf("%ld",&n);
    getchar();
    while(1){
      scanf("%c",&a);
      if(a!='!')
        break;
      k++;
      }
    for(i=n;i>0;i-=k)
      sum*=i;
    printf("%ld\n",sum);
    system("pause");
    return 0;
    }
