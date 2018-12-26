#include<stdio.h>
#include<stdlib.h>
int a[10],n;
bool x[10];
void dfs(int y){
     int i,j,m;
     if(y>n){
       for(i=1;i<=n;i++)
       printf("%d ",a[i]);
       printf("\n");
       return; 
       }
     for(i=1;i<=n;i++)
       if(!x[i]){
         x[i]=1;
         a[y]=i;
         dfs(y+1);
         x[i]=0;
         }
     return;   
     }
int main(){
    scanf("%d",&n);
    dfs(1);
    system("pause");
    return 0;
    } 
