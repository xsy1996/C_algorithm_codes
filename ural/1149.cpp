#include<stdio.h>
#include<stdlib.h>
void a(int n){
     int i,j;
     for(i=1;i<=n-1;i++){
       if(i%2==1)
         printf("sin(%d-",i);
       else
         printf("sin(%d+",i);
       }
     printf("sin(%d)",n);
     for(i=1;i<n;i++)
       printf(")");
     return;
     }
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
      printf("(");
    for(i=1;i<n;i++){
      a(i);
      printf("+%d)",n-i+1);
      }
    a(n);
    printf("+1\n");
    system("pause");
    return 0;
    }
