#include<stdio.h>
#include<stdlib.h>
long long a[101][101];
int main(){
    int z,x,y,i,j,k,m,n;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    n+=3;
    m+=3;
    x+=3;
    y+=3;
    for(i=3;i<=n;i++)
      for(j=3;j<=m;j++)
        a[i][j]=-1;
    a[3][3]=1;
    a[x+2][y+1]=0;
    a[x+2][y-1]=0;
    a[x+1][y-2]=0;
    a[x+1][y+2]=0;
    a[x-1][y+2]=0;
    a[x-1][y-2]=0;
    a[x-2][y+1]=0;
    a[x-2][y-1]=0;
    a[x][y]=0;
    for(i=3;i<=n;i++)
      for(j=3;j<=m;j++){
        if((i==3 && j==3) || a[i][j]==0)
          continue;
          a[i][j]=a[i-1][j]+a[i][j-1];
      }
      printf("%I64d\n",a[n][m]);    
      system("pause");
        return 0;
    }


