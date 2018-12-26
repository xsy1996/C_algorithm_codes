#include<stdio.h>
//#include<stdlib.h>
long a[200001],p[200001],n;
long long sum=0;
void gb(long f1,long l1,long f2,long l2){
     long i,j,k=0;
     if(f1==l1 || f2==l2){
       if(f1!=l1)
         gb(f1,(l1+f1)/2,(l1+f1)/2+1,l1);
       if(f2!=l2)
         gb(f2,(l2+f2)/2,(f2+l2)/2+1,l2);
       } 
     else{
       gb(f1,(l1+f1)/2,(l1+f1)/2+1,l1);
       gb(f2,(l2+f2)/2,(f2+l2)/2+1,l2);
       }
     i=f1;j=f2;
     while(i<=l1 || j<=l2){
       if(i>l1 || j>l2){
         if(i>l1)
           for(;j<=l2;j++){
             k++;
             p[k]=a[j];
             }
         if(j>l2)
           for(;i<=l2;i++){
             k++;
             p[k]=a[i];
             }
         break;
         }
       if(a[i]<=a[j]){
         k++;
         p[k]=a[i];
         i++;
         }
       else if(a[i]>a[j]){
         sum=sum+l1-i+1;
         k++;
         p[k]=a[j];
         j++;
         }
       }
     j=0;
     for(i=f1;i<=l2;i++){
       j++;
       a[i]=p[j];
       }
     return;
     }
int main(){
    long i,j,k;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      scanf("%ld",&a[i]);
    gb(1,(n+1)/2,(n+1)/2+1,n);
    printf("%I64d\n",sum);
   // system("pause");
    return 0;
    } 
