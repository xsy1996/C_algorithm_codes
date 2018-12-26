#include<stdio.h>
#include<stdlib.h>
int x[17][17];
int main(){
    int a,b,c,i,j,k,n;
   scanf("%d%d%d",&a,&b,&c);   
    for(i=1;i<=c;i++){
       scanf("%d%d",&j,&k);
       x[j][k]=-1;
       }
    for(i=1;i<=a;i++){
      if(x[i][1]!=-1)
        x[i][1]=1;
      else
        break;  
        }
    for(i=1;i<=b;i++){
      if(x[1][i]!=-1)
        x[1][i]=1;
      else
        break;  
        } 
    if(x[1][1]==-1)
      printf("0");
    else{  
    for(i=2;i<=a;i++)
      for(j=2;j<=b;j++){
        if(x[i][j]!=-1 && x[i-1][j]!=-1)
          x[i][j]+=x[i-1][j];
        if(x[i][j]!=-1 && x[i][j-1]!=-1)
          x[i][j]+=x[i][j-1];
          }
    printf("%d",x[a][b]);
      }
    system("pause");
    return 0;
    }
