#include<stdio.h>
#include<stdlib.h>
int shi[11];
int main(){
    int a,b=0,c,i,j,k,n,sum=0;
      scanf("%d%d",&k,&a);
      while(a!=0){
          shi[b]=a%2;
          a/=2;
          b++;
          }
        for(j=(b-1);j>=0;j--) 
            if(shi[j]!=0){     
              c=1;     
              for(i=1;i<=j;i++)
                c*=k;
              sum+=c;
            }
        printf("%d\n",sum);
     system("pause");
    return 0;
    }
