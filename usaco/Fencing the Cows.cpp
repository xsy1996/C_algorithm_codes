/*
ID:xsy19962
LANG:C++
TASK:fc
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long s[10001],t=2;
double sum,xl[10001],a[10001][2];
void qsort(long l,long r){
     long i,j;
     double x,k;
     i=l;j=r;
     x=a[(i+j)/2][0];
     while(i<=j){
       while(a[i][0]<x) i++;
       while(a[j][0]>x) j--;
       if(i<=j){
         k=a[i][0];
         a[i][0]=a[j][0];
         a[j][0]=k;
         k=a[i][1];
         a[i][1]=a[j][1];
         a[j][1]=k;
         i++;
         j--;
         }
       }
     if(l<j)
       qsort(l,j);
     if(i<r)
       qsort(i,r);
     return;
     }

int main(){
    freopen("fc.in","r",stdin);
    freopen("fc.out","w",stdout);
    long i,j,k,n;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      scanf("%lf%lf",&a[i][0],&a[i][1]);
    qsort(1,n);
    s[1]=1;
    s[2]=2;
    if(a[1][0]==a[2][0])
      if(a[1][1]>a[2][1])
        xl[1]=-1000000;
      else
        xl[1]=1000000;
    else
      xl[1]=(a[2][1]-a[1][1])/(a[2][0]-a[1][0]);
    for(i=3;i<=n;i++){
      if(a[i][0]==a[s[t]][0])
        if(a[s[t]][1]>a[i][1])
          xl[t]=-1000000;
        else
          xl[t]=1000000;
      else
        xl[t]=(a[i][1]-a[s[t]][1])/(a[i][0]-a[s[t]][0]);  
      xl[0]=2147483647;
      while(xl[t]>xl[t-1]){
        t--;
        xl[t]=(a[i][1]-a[s[t]][1])/(a[i][0]-a[s[t]][0]);  
        }
      t++;
      s[t]=i;
      }
    for(i=1;i<t;i++)
      sum+=sqrt((a[s[i]][0]-a[s[i+1]][0])*(a[s[i]][0]-a[s[i+1]][0])+(a[s[i]][1]-a[s[i+1]][1])*(a[s[i]][1]-a[s[i+1]][1]));
    t=2;
    s[1]=1;
    s[2]=2;
    if(a[1][0]==a[2][0])
      if(a[1][1]>a[2][1])
        xl[1]=-1000000;
      else
        xl[1]=1000000;
    else
      xl[1]=(a[2][1]-a[1][1])/(a[2][0]-a[1][0]);
    for(i=3;i<=n;i++){
      if(a[i][0]==a[s[t]][0])
        if(a[s[t]][1]>a[i][1])
          xl[t]=-1000000;
        else
          xl[t]=1000000;
      else
        xl[t]=(a[i][1]-a[s[t]][1])/(a[i][0]-a[s[t]][0]);  
      xl[0]=-2147483647;
      while(xl[t]<xl[t-1]){
        t--;
        xl[t]=(a[i][1]-a[s[t]][1])/(a[i][0]-a[s[t]][0]);  
        }
      t++;
      s[t]=i;
      }
    for(i=1;i<t;i++)
      sum+=sqrt((a[s[i]][0]-a[s[i+1]][0])*(a[s[i]][0]-a[s[i+1]][0])+(a[s[i]][1]-a[s[i+1]][1])*(a[s[i]][1]-a[s[i+1]][1]));
    printf("%0.2f\n",sum);
   // system("pause");
    return 0;
    } 
