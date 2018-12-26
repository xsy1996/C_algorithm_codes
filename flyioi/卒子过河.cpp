#include<stdio.h>
#include<stdlib.h>
int x[21][21];
int y[21][21];
int main(){
    int a,b,c,d,i,j,k,sum,m,n;
    freopen("")
    scanf("%d%d",&n,&m);
    scanf("%d",&q);
    for(i=1;i<=q;i++){
      scanf("%d%d",&a,&b);
      x[a+2][b+1]=1;
      x[a+1][b+2]=1;
      x[a-2][b-1]=1;
      x[a-1][b-2]=1;
      x[a-2][b+1]=1;
      x[a+2][b-1]=1;
      x[a-1][b+2]=1;
      x[a+1][b-2]=1;
      x[a][b]=1;
      }
    x[m][1]=2;
    sum=y(1,n,0);
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
