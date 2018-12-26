#include<stdio.h>
#include<stdlib.h>
int a[251][251],v[251],f[251],n,sum=0;
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
    int i,j,k,m,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
      scanf("%d",&k);
      for(j=1;j<=k;j++){
        scanf("%d",&y);
        a[i][y]=1;        
        }        
      }
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
        v[j]=1;
      find(i);
      }
    for(i=1;i<=n;i++)
      if(f[i]!=0)
        sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
