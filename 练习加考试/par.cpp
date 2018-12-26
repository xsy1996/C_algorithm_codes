#include<stdio.h>
#include<stdlib.h>
int a[101][101],b[101];
int main(){
    FILE *fin=fopen("par.in","r");
    FILE *fout=fopen("par.out","w");
    int i,j,k,m,n,x,y;
    fscanf(fin,"%d",&n);
    b[0]=1; 
    for(i=1;i<=101;i++)
      for(j=1;j<=101;j++)
        a[i][j]=100000000;
    for(i=1;i<=n;i++){
      fscanf(fin,"%d",&m);
      b[i]=m;  
      for(j=1;j<=m;j++){
        fscanf(fin,"%d",&x);
        while(x!=0){
          fscanf(fin,"%d",&y);
          if(a[i][j]>a[i-1][x]+y)
            a[i][j]=a[i-1][x]+y;
          fscanf(fin,"%d",&x);
          }
        
        }
      }
      y=100000000;
    for(i=1;i<=b[n];i++)
      if(a[n][i]<y)
        y=a[n][i];
      fprintf(fout,"%d\n",y);  
    fclose(fin);
    fclose(fout);
   
    return 0;
    }
