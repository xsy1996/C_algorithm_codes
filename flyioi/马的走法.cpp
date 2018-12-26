#include<stdio.h>
#include<stdlib.h>
long v[10][10],sum,m,n,fx[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
void dfs(int x,int y){
     int i,j,k,x1,y1;
     if(x==n && y==m){
       sum++;
       return;
       }
     for(i=0;i<=7;i++){
       x1=x+fx[i][0];
       y1=y+fx[i][1];
       if(x1<=4 && y1<=5 && x1>0 && y1>0 && v[x1][y1]==0){
         v[x1][y1]=1;
         dfs(x1,y1);
         v[x1][y1]=0;
         }
       }
     return;
     }
int main(){
    int i;
    scanf("%d%d",&n,&m);
    if(n<1 || n>4 || m<1 || m>5){
      printf("Error!");
      system("pause");
      return 0;
      }
    for(i=0;i<=7;i++)
      if(n+fx[i][0]<=4 && m+fx[i][1]<=5 && n+fx[i][0]>0 && m+fx[i][1]>0){
        v[n+fx[i][0]][m+fx[i][1]]=1;
        dfs(n+fx[i][0],m+fx[i][1]);
        v[n+fx[i][0]][m+fx[i][1]]=0;
        }
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
