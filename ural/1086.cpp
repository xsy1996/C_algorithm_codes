#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[200001];
long b[20000];
int main(){
    int n=200000,t=0,i,x,j,k,z,q;
    z=int(sqrt(n*1.0));
    for(i=0;i<=(z-3)/2;i++)
      if(a[i]==0)
        for(j=i*(2*i+6)+3;j<=(n-3)/2;j+=2*i+3)
          a[j]=1;
      t=1;
      b[1]=2;
      for(i=0;i<=(n-3)/2;i++)
        if(a[i]==0){
          t++;
          b[t]=2*i+3;
          }
    scanf("%ld",&q);
    for(i=1;i<=q;i++){
      scanf("%ld",&z);
      printf("%ld\n",b[z]);
      }
    system("pause");
    return 0;
    }
