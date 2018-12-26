#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int qm,by,lw,e=0,i,n,sum=0,x=0;
    char a,b,c,gb,xb,mz[20],y[20];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%s %d %d %c %c %d",&mz,&qm,&by,&gb,&xb,&lw);
      if(qm>80 && lw>=1)
        sum+=8000;
      if(qm>85 && by>80)
        sum+=4000;
      if(qm>90)
        sum+=2000;
      if(qm>85 && xb=='Y')
        sum+=1000;
      if(by>80 && gb=='Y')
        sum+=850;  
      e+=sum;
      if(sum>x){
        x=sum;
        strcpy(y,mz);
        }
      sum=0;
      }
    printf("%s\n%d\n%d",y,x,e);
    
    system("pause");
    return 0;
    }
