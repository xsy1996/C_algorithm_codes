/*
ID:xsy19962
PROG:transform
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
int a[11][11],b[11][11];
int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int i,j,k,n,flag;
    char x;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++,getchar())
      for(j=1;j<=n;j++)
        scanf("%c",&a[i][j]);
    for(i=1;i<=n;i++,getchar())
      for(j=1;j<=n;j++)
        scanf("%c",&b[i][j]);
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[j][n-i+1]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("1\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[n-i+1][n-j+1]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("2\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[j][i]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("3\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[i][n-j+1]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("4\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[n-j+1][n-i+1]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("5\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[n-j+1][i]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("5\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[n-i+1][j]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("5\n");
      return 0;
      }
    flag=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][j]!=b[i][j]){
          flag=1;
          break;
          }
    if(flag==0){
      printf("6\n");
      return 0;
      }
    printf("7\n");
    return 0;
    }
