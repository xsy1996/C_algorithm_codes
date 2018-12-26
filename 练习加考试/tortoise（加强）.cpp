#include<stdio.h>
#include<stdlib.h>
int f[41][41][41][41],x[351];
int main(){
    int a=0,b=0,c=0,d=0,i,j,k,l,m,n;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=m;i++){
      scanf("%d",&k);
      switch(k){
        case 1 : a++;break;
        case 2 : b++;break;
        case 3 : c++;break;
        case 4 : d++;break;
        }
      }f[0][0][0][0]=x[0];
    for(i=0;i<=a;i++)
      for(j=0;j<=b;j++)
        for(k=0;k<=c;k++)
          for(l=0;l<=d;l++){
            if(i>=1 && f[i-1][j][k][l]+x[i+2*j+3*k+4*l]>f[i][j][k][l])
              f[i][j][k][l]=f[i-1][j][k][l]+x[i+2*j+3*k+4*l];
            if(j>=1 && f[i][j-1][k][l]+x[i+2*j+3*k+4*l]>f[i][j][k][l])
              f[i][j][k][l]=f[i][j-1][k][l]+x[i+2*j+3*k+4*l];
            if(k>=1 && f[i][j][k-1][l]+x[i+2*j+3*k+4*l]>f[i][j][k][l])
              f[i][j][k][l]=f[i][j][k-1][l]+x[i+2*j+3*k+4*l];
            if(l>=1 && f[i][j][k][l-1]+x[i+2*j+3*k+4*l]>f[i][j][k][l])
              f[i][j][k][l]=f[i][j][k][l-1]+x[i+2*j+3*k+4*l];
                }
    printf("%d\n",f[a][b][c][d]);
    system("pause");
    return 0;
    }
