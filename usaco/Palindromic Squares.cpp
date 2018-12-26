/*
ID:xsy19962
LANG:C++
TASK:palsquare
*/
#include<stdio.h>
#include<stdlib.h>
int n;
char def[21]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75};
int base(int q){
     int i,k=0,x,a[1000],t=0;
     x=q;
     while(x/n!=0){
       t++;
       a[t]=x%n; 
       x/=n;           
       }
     t++;
     a[t]=x;
     for(i=1;i<=t/2;i++)
       if(a[i]!=a[t-i+1])
         k++;
     if(k!=0)
       return 0;
     else
       return 1;
     }
void out(int q){
     int i,j,k,x,t;
     char a[1000];
     x=q;t=0;
     while(x/n!=0){
       t++;
       a[t]=def[x%n];    
       x/=n;
       }
     t++;
     a[t]=def[x];
     for(i=t;i>=1;i--)
       printf("%c",a[i]);
     printf(" ");
     x=q*q;t=0;
    while(x/n!=0){
       t++;
       a[t]=def[x%n];  
       x/=n;          
       }
     t++;
     a[t]=def[x];
     for(i=t;i>=1;i--)
       printf("%c",a[i]);
     printf("\n");

     return;
     }
int main(){
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout); 
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=300;i++)
      if(base(i*i))
        out(i);
   // system("pause");
    return 0;
    }
