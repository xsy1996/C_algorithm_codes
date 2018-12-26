#include<stdio.h>
#include<stdlib.h>
int f[103][53][53],w[53][53];
int main(){
    long i,j,k,m,n,max,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&w[i][j]);
    for(k=2;k<=m+n;k++)
      for(i=1;i<=k && i<=n;i++)
        for(j=1;j<=k && j<=n;j++){
          max=f[k][i][j];
          for(a=0;a<=1;a++)
            for(b=0;b<=1;b++)
              if(f[k-1][i-a][j-b]>max)   
                max=f[k-1][i-a][j-b];
          if(i==j)
            f[k][i][j]=max+w[i][k-i];
          else  
            f[k][i][j]=max+w[i][k-i]+w[j][k-j];
          }
    printf("%ld\n",f[m+n][n][n]);
    system("pause");
    return 0;
    }
