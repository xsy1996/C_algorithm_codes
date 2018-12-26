#include<stdio.h>
#include<stdlib.h>
int main(){
    int x[1001][2],a,b,c,i,j,k,m,n;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
      scanf("%d",&x[i][0]);
      x[i][1]=i+1;
      }
    x[n][1]=1;
    while(m>n)
      m-=n;
    if(m==1){
      printf("1 ");
      m=x[1][0];
      x[n][1]=2;       
      k=n;
      }
    else{
      printf("%d ",m);
      k=m-1;
      x[m-1][1]=x[m][1];  
      m=x[m][0];
      }
    j=0;
    while(x[k][1]!=k){
      if(m==1){
        printf("%d ",x[k][1]);
        m=x[x[k][1]][0];
        x[k][1]=x[x[k][1]][1];       
        j=0;
        continue;
        }
      j++;
      k=x[k][1];
      if(j==m-1){
        printf("%d ",x[k][1]);
        m=x[x[k][1]][0];
        x[k][1]=x[x[k][1]][1];       
        j=0;
        }
      
      }
    printf("%d\n",k);      
    system("pause");
    return 0;
    }    
