#include<stdio.h>
#include<stdlib.h>
int a[1001][1001],v[1001],d[1001];
int main(){
   freopen("10.in","r",stdin);
   freopen("10.out","w",stdout);
   int i,j,k,x,m,n,y,s=0,min;
   char c,e;
   scanf("%c %c\n",&c,&e);
   x=c-64;y=e-64;
   while(scanf("%c %c\n",&c,&e)!=EOF)
     a[c-64][e-64]=1;
  
     s=26;
   for(i=1;i<=s;i++)
     d[i]=100000000;  
  
   d[x]=0;
 
   for(i=1;i<=s;i++){
     min=100000000;
     for(j=1;j<=s;j++)
       if(v[j]==0 && d[j]<min){
         k=j;
         min=d[j];
         }
     v[k]=1;
     for(j=1;j<=s;j++)
       if(v[j]==0 && a[k][j]!=0 && min+a[k][j]<d[j])
         d[j]=min+a[k][j];
      }  
   printf("%d\n",d[y]);
   
   return 0; 
   }
