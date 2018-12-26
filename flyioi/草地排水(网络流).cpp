#include<stdio.h>
#include<stdlib.h>
int v[201],c[201][201],f[201][201],n;
int find(){
     long i,j,k;
     bool x;
     for(i=2;i<=n;i++)
       v[i]=0;
     v[1]=1;
     do{
       x=0;
       for(i=1;i<=n;i++)
         if(v[i]!=0)
           for(j=2;j<=n;j++)
             if(v[j]==0 && f[i][j]<c[i][j]){
               v[j]=i;
               x=1;
               }        
       }while(x==1 && v[n]==0); 
     if(v[n]==0)
       return 0;
     else
       return 1;
     }
void pj(){
     long i,j,k,x=10000001;
     i=n;
     while(i!=1){
       j=i;
       i=v[i];
       if((c[i][j]-f[i][j])<x)
         x=c[i][j]-f[i][j];
       }
     i=n;
     while(i!=1){
       j=i;
       i=v[i];
       f[i][j]+=x;
       f[j][i]=0-f[i][j];
       }
     return;
     }
int main(){
    long x,z,y,m,i,j,sum=0,k;
    scanf("%ld%ld",&m,&n);
    for(i=1;i<=m;i++){
      scanf("%ld%ld%ld",&x,&y,&z);
      c[x][y]+=z;
      }
    while(find())
      pj();
    for(i=1;i<n;i++)
      if(f[i][n]>0)
        sum+=f[i][n];
    printf("%ld\n",sum);
    system("pause");
    return 0;
    }
