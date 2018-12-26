#include<stdio.h>
#include<stdlib.h>
long a[10001],b[10001];
void qsort(int l,int r){
     int k,i,j,x;
     if(l==r)
       return;
     i=l;
     j=r;
     x=a[(i+j+1)/2];
     while(i<j){
       while(a[i]<x)
         i++;
       while(a[j]>x)
         j--;
       if(i<=j){
         k=a[i];       
         a[i]=a[j];
         a[j]=k;
         i++;
         j--;       
         }
       }
     if(l<=j)
       qsort(l,j);
     if(i<=r)
       qsort(i,r);
     return;
     }
int main(){
    long i,j,sum=0,k,n,s=1,f=1,l=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    qsort(1,n);
    for(i=1;i<n;i++){
      k=0; 
      if((a[s]<b[f] || b[f]==0) && s<=n){
        k+=a[s];               
        s++;
        }
      else if(b[f]!=0){
        k+=b[f];
        f++;
        }
      if((a[s]<b[f] || b[f]==0) && s<=n){
        k+=a[s];               
        s++;
        }
      else if(b[f]!=0){
        k+=b[f];
        f++;
        }
      l++;
      b[l]=k;
      sum+=k;
      }
    printf("%ld\n",sum);
    system("pause");
    return 0;
    }
