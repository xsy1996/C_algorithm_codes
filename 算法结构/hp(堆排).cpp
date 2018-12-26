#include<stdio.h>
#include<stdlib.h>
int d[10001];
void zl(int n){
     int i,j=0,k;
     i=1;
     while(1){
       if(2*i<=n)
         j=2*i;
       else break;
       if(2*i+1<=n && d[j]>d[2*i+1])
         j=2*i+1;
       if(d[i]<d[j])
         break;
       else{
         k=d[i];
         d[i]=d[j];
         d[j]=k;
         i=j;
         }
       }
     return;
     }
void jd(int a){
     int i,k;
     i=a;
     while(d[i]<d[i/2] && i>1){
       k=d[i];
       d[i]=d[i/2];
       d[i/2]=k;
       i/=2;
       }
     return;
     }
int main(){
    int i,j,k,n,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&d[i]);
      jd(i);
      }
    for(i=n;i>1;i--){
      printf("%d ",d[1]);
      d[1]=d[i];
      zl(i-1);
      }
    printf("%d\n",d[1]);
    system("pause");
    return 0;
    }
