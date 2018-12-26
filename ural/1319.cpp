#include<stdio.h>
#include<stdlib.h>
int a[101][101];
int main(){
    int n,i,j,k,x,y;
    scanf("%d",&n);
    k=0;
    for(i=n;i>=1;i--){
      y=i;
      for(x=1;x<=n-i+1;x++){
        k++;
        a[x][y]=k;
        y++;
        }
      }
    for(i=2;i<=n;i++){
      x=i;
      for(y=1;y<=n-i+1;y++){
        k++;
        a[x][y]=k;
        x++;
        }
      }
    for(i=1;i<=n;i++,printf("\n"))
      for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
    system("pause");
    return 0;
    }
