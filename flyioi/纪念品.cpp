#include<stdio.h>
#include<stdlib.h>
long p[30001],n;
void qsort(long start,long end){
    long k,l,r,x;
    l=start;
    r=end;
    x=p[(l+r)/2];
    while(l<=r){
      while(p[l]<x)
        l++;
      while(p[r]>x)
        r--;
      if(l<=r){
        k=p[l];
        p[l]=p[r];
        p[r]=k;
        l++;
        r--;
        }
      }
    if(start<r)  
      qsort(start,r);
    if(l<end)
    qsort(l,end);         
    return;
    }
int main(){
    long i,j,k,w,sum=0;
    scanf("%ld",&w);
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      scanf("%ld",&p[i]);
    qsort(1,n);
    for(i=1;i<=n;i++){
      while((p[i]+p[n])>w){
        sum++;
        n--;
        }
      n--;
      sum++;
      }     
    printf("%d\n",sum);           
    system("pause");
    return 0;
    }
