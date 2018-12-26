#include<stdio.h>
#include<stdlib.h>
long a[100001],b[100001];
int main(){
    long n,max=1,i,j;
    a[0]=0;a[1]=1;a[2]=1;
    b[0]=0;b[1]=1;b[2]=1;
    for(i=3;i<=100000;i++){
      if(i%2!=0)
        a[i]=a[i/2]+a[i/2+1];
      else
        a[i]=a[i/2];
      if(a[i]>max)
        max=a[i];
      b[i]=max;  
      }
    while(scanf("%ld",&n) && n!=0)
      printf("%d\n",b[n]);
    system("pause");
    return 0;
    }
