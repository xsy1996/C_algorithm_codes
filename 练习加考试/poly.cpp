#include<stdio.h>

int main(){
    FILE*fin=fopen("poly.in","r");
    FILE*fout=fopen("poly.out","w");
    int a,b,c,i,j,n;
    fscanf(fin,"%d",&n);
    for(i=n;i>=0;i--){
      fscanf(fin,"%d",&a);
      if(a==0)
        continue;
      if(a>0 && i!=n)
        fprintf(fout,"+");
      if(i!=0){
        if(a==-1)
          fprintf(fout,"-x");
        if(a==1)
          fprintf(fout,"x");
        else if(a>1 || a<-1)
          fprintf(fout,"%dx",a);   
        }
      if(i>=2)
        fprintf(fout,"^%d",i);
      if(i==0)
        fprintf(fout,"%d",a);
      }
    return 0;
    }

