#include<stdio.h>
#include<stdlib.h>
bool x[30];
int  a[8];
int main(){
    int b,c,i,j,k=0;
    x[29]=1;
    for(a[1]=1;a[1]<=22;a[1]++)  
      for(a[2]=a[1]+1;a[2]<=23;a[2]++)
        for(a[3]=a[2]+1;a[3]<=24;a[3]++)
          for(a[4]=a[3]+1;a[4]<=25;a[4]++)
            for(a[5]=a[4]+1;a[5]<=26;a[5]++)
              for(a[6]=a[5]+1;a[6]<=27;a[6]++)
                for(a[7]=a[6]+1;a[7]<=28;a[7]++){
                  for(i=2;i<=28;i++)
                    x[i]=0;
                  k=0;
                  for(i=1;i<=7;i++){
                    x[a[i]]=1; 
                    x[29-a[i]]=1;
                    }
                  for(i=1;i<=6;i++)
                    for(j=i+1;j<=7;j++)
                      x[a[j]-a[i]]=1;
                  for(i=1;i<=29;i++)
                    k+=x[i];
                  if(k==29){
                    for(i=1;i<=7;i++)
                      printf("%d ",a[i]);
                    printf("\n");
                    }
                  }
                 
    system("pause");
    return 0;
    }
