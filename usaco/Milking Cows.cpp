/*
ID:xsy19962
PROG:milk2
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
bool a[1000001];
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    long start=1000001,end=0,f,l,i,j,k,sum,n,max1=0,max2=0;
    scanf("%ld",&n);
    for(i=1;i<=n;i++){
      scanf("%ld%ld",&f,&l);
      for(j=f;j<l;j++)
        a[j]=1;
      if(l>end)
        end=l;
      if(f<start)
        start=f;
      }
    k=a[1];sum=0;
    for(i=start;i<=end;i++){
      if(a[i]==k)
        sum++;
      else{
        if(k==0 && sum>max1)
          max1=sum;
        if(k==1 && sum>max2)
          max2=sum;  
        k=a[i];
        sum=1;
        }
      }
    printf("%ld %ld\n",max2,max1);
  
    return 0;
    }
