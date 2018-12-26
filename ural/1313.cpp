#include<stdio.h>
#include<stdlib.h>
long a[101][101];
int main(){
    long n,i,j,k,y,x;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        scanf("%ld",&a[i][j]);
    for(i=1;i<=n;i++){
      x=i;
      for(y=1;y<=i;y++){
        printf("%ld ",a[x][y]);
        x--;
        }
      }
    for(i=2;i<=n;i++){
      y=i;
      for(x=n;x>=i;x--){
        printf("%ld ",a[x][y]);
        y++;
        }
      }      
    printf("\n");
    system("pause");
    return 0;
    }
