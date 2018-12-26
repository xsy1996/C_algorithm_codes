#include<stdio.h>
#include<stdlib.h>
long mop[101][101],f[101][101];
int main(){
    long i,j,x,y,t,n,m;
    scanf("%d",&t); 
    for(;t>=1;t--){
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
          scanf("%d",&mop[i][j]);
          f[i][j]=0;
          }
      f[1][1]=1;
      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          for(x=0;x<=mop[i][j];x++)
            for(y=0;y<=mop[i][j]-x;y++)
              if((x+i)<=n && (y+j)<=m && (x || y)){
                f[x+i][y+j]+=f[i][j];
                if(f[i+x][y+j]>=10000)
                  f[x+i][y+j]%=10000;
                }
      printf("%d\n",f[n][m]%10000);
      }
    system("pause");
    return 0;
    }
