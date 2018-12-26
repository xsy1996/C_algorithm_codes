#include<stdio.h>
#include<stdlib.h>
int a[101],time[101],t,n,f[101][1001];
int main(){
    int z,x,i,j,k;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
      scanf("%d%d",&time[i],&a[i]);
    for(i=1;i<=n;i++)
      for(j=1;j<=t;j++){
        if(j>=time[i]){
          if(f[i-1][j]>f[i-1][j-time[i]]+a[i])
            f[i][j]=f[i-1][j];
          else
            f[i][j]=f[i-1][j-time[i]]+a[i];
          }
        else
          f[i][j]=f[i-1][j];
        }
    printf("%d\n",f[n][t]);
    system("pause");
    return 0;
    }
