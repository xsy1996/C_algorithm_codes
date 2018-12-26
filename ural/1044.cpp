#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,a,b,c,d,i,j,k,l,sum=0;
    scanf("%d",&n);
    if(n==0)
      printf("1\n");
    if(n==2)
      printf("10\n");
    if(n==4)
      printf("670\n");
    if(n==6){
      for(a=0;a<=9;a++)
        for(b=0;b<=9;b++)
          for(c=0;c<=9;c++)
            for(i=0;i<=9;i++)
              for(j=0;j<=9;j++)
                for(k=0;k<=9;k++)
                  if((a+b+c)==(i+j+k))
                    sum++;
      printf("%d\n",sum);
      }
    if(n==8){
      for(a=0;a<=9;a++)
        for(b=0;b<=9;b++)
          for(c=0;c<=9;c++)
            for(d=0;d<=9;d++)
              for(i=0;i<=9;i++)
                for(j=0;j<=9;j++)
                  for(k=0;k<=9;k++)
                    for(l=0;l<=9;l++)  
                      if((a+b+c+d)==(i+j+k+l))
                        sum++;
      printf("%d\n",sum);
      }
    system("pause");
    return 0;
    }
