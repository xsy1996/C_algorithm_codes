#include<stdio.h>
#include<stdlib.h>
int fm[6]={1,2,3,5,10,20},a[1001],s[1001];
bool f[1021];
int main(){
    int z,x,i,j,k,t=0,n=0;
    for(i=0;i<=5;i++){
      scanf("%d",&z);
      for(j=1;j<=z;j++){
        n++;
        a[n]=fm[i];
        }
      } 
    for(i=1;i<=n;i++)
      for(j=t;j>=0;j--)
        if(f[s[j]+a[i]]==0){
          t++;
          s[t]=s[j]+a[i];
          f[s[j]+a[i]]=1;
          }
    printf("Total=%d\n",t);
    system("pause");
    return 0;
    }
