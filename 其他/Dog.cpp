#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[101][101],v[101],f[101],n,sum=0,l[101][2],m,d[101][2];
int jdz(int c){
    if(c>=0)
      return c;
    else
      return c*-1;
    }
int find(int x){
    int y;
    for(y=1;y<=n;y++)
      if(v[y] && a[x][y]){
        v[y]=0;
        if(f[y]==0 || find(f[y])){
          f[y]=x;
          return 1;
          }
        }
    return 0;
    }
int main(){
    long i,j,k,x,y,x1,y1,x2,y2;
    freopen("Dog.in","r",stdin);
    freopen("Dog.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%d%d",&l[i][0],&l[i][1]);
    for(i=1;i<=m;i++){
      scanf("%d%d",&d[i][0],&d[i][1]);
      x=d[i][0];
      y=d[i][1];
      for(j=1;j<n;j++){
        x1=l[j][0];
        y1=l[j][1];
        x2=l[j+1][0];
        y2=l[j+1][1];
        if(sqrt(jdz(x-x1)*jdz(x-x1)+jdz(y-y1)*jdz(y-y1))+sqrt(jdz(x-x2)*jdz(x-x2)+jdz(y-y2)*jdz(y-y2))<=2*sqrt(jdz(x1-x2)*jdz(x1-x2)+jdz(y1-y2)*jdz(y1-y2)))              
          a[i][j]=1;
        }
      }
    for(i=1;i<=m;i++){
      for(j=1;j<n;j++)
        v[j]=1;
      find(i);
      }
    for(i=1;i<=n;i++){
      if(f[i]!=0)
        sum++;
      v[i]=f[i];  
      }
    printf("%d\n",sum+n);
    for(i=1;i<=n;i++){
      printf("%d %d ",l[i][0],l[i][1]);
      if(v[i]!=0)
        printf("%d %d ",d[v[i]][0],d[v[i]][1]);
      }
    printf("\n");
  //  system("pause");
    return 0;
    }
