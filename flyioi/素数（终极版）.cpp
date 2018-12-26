#include<stdio.h>
#include<stdlib.h>
#include<math.h>
bool a[20000001];
int main(){
    long z,x,i,j,k,n,sum=1;
    scanf("%d",&n);
    z=int(sqrt(n));
    for(i=0;i<=(z-3)/2;i++)
      if(a[i]==0)
        for(j=i*(2*i+6)+3;j<=(n-3)/2;j+=2*i+3)
          a[j]=1;
    if(n>2)
      for(i=0;i<=(n-3)/2;i++)
        if(a[i]==0)
          sum++;
    printf("%ld\n",sum);
    system("pause");
      return 0;
    }
