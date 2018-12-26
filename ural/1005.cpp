#include<stdio.h>
#include<stdlib.h>
long a[21],n,sum,min=10000001;
void dfs(int x,long s){
     int i,j,k;
     if(s>sum/2)
       return;
     if(x==n){
       if(sum-s-s<min)
         min=sum-s-s;
       return;
       }
     dfs(x+1,s+a[x+1]);
     dfs(x+1,s);         
     return;
     }
int main(){
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%ld",&a[i]);
      sum+=a[i];
      }
    dfs(0,0);
    printf("%ld\n",min);
    system("pause");
    return 0;
    }
