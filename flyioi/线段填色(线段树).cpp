#include<stdio.h>
#include<stdlib.h>
long a[80001][3];
void tree(long n,long s,long e){
     long mid;
     a[n][0]=s;a[n][1]=e;
     if(e-s>1){
       mid=(s+e)/2;
       tree(2*n,s,mid);
       tree(2*n+1,mid,e);
       }
     return;
     }
void ran(long n,long t,long s,long e){
     long mid;
     mid=(a[n][0]+a[n][1])/2;
     if(a[n][2]==t)
       return;
     if(a[n][0]==s && a[n][1]==e)
       a[n][2]=t;
     else{
       if(a[n][2]>=0){
         a[2*n][2]=a[n][2];
         a[2*n+1][2]=a[n][2];
         a[n][2]=-1;
         }   
       if(e<=mid)
         ran(2*n,t,s,e);
       else if(s>=mid)
         ran(2*n+1,t,s,e);
       else{
         ran(2*n,t,s,mid);
         ran(2*n+1,t,mid,e);
         }
       }
     return;
     }
long tj(long n){
     long i,j,k,sum=0;
     if(a[n][2]>0)
       sum+=a[n][1]-a[n][0];
     if(a[n][2]<0)
       sum+=tj(2*n)+tj(2*n+1);
     return sum;
     }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long i,j,n,t,s,e;
    tree(1,0,20000);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d%d%d",&t,&s,&e);
      ran(1,t,s,e);
      }
    printf("%d\n",tj(1));
   // system("pause");
    return 0;
    }
