/*
ID:xsy19962
PROG:beads
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
char a[351];
int main(){
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int i,j,k,n,sum,max=0,x;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
      scanf("%c",&a[i]);
    a[0]=a[n];   
    a[n]=0;
    for(i=0;i<n;i++){
      sum=0;
      j=i;
      while(a[j%n]=='w'){
         if(j>i+n-1)
          break;
        sum++; 
        j++;
        }
      x=j;
      for(;j<=i+n-1;j++){
        if(a[j%n]==a[x] || a[j%n]=='w')
          sum++;
        else
          break;
        }
      k=i+n-1;
      while(a[k%n]=='w'){
        sum++;
        k--;
        if(k<i)
          break;
        }   
      j=k;  
      k%=n;
      for(;j>=i;j--){
        if(a[j%n]==a[k] || a[j%n]=='w')
          sum++;
        else
          break;
          }
      if(max<sum){
        if(sum>=n){
          max=n;
          break;
          }
        max=sum;
        }
      }
    printf("%d\n",max);
    return 0;
    }
