#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    long long n,i,j,k,a;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++){
      scanf("%I64d",&a);
      if(a==1){
        printf("1 ");
        continue;
        }
      a=(a-1)*2;
      k=int(sqrt(a));
      if(a==k*(k+1))
        printf("1 ");
      else
        printf("0 ");
      }
    printf("\n");
    system("pause");
    return 0;
    }
