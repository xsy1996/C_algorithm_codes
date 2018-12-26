#include<stdio.h>
#include<stdlib.h>
int x[101]; 
int main(){
    int a,b=0,c,i,j,k,n,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&x[i]);
      s+=x[i];
      }
    a=s/n;
    for(i=1;i<=n;i++)
      if(x[i]!=a){
        x[i+1]+=x[i]-a;
        x[i]=a;
        b++;
        }
    printf("%d\n",b);  
    system("pause");
    return 0;
    }
