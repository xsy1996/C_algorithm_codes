#include<stdio.h>
#include<string.h>
char x[101];
int c[101];
int main(){
    FILE*fin=fopen("camel.in","r");
    FILE*fout=fopen("camel.out","w");
    int a,b,i,j,k,n;
    fscanf(fin,"%s",&x);
    a=strlen(x);
     n=0; 
    for(i=0;i<a;i++)
      if(x[i]<'a'){
      c[i]=x[i];
      n++;
      }
    for(i=0;i<n;i++)
      for(j=i;j<=a;j++){
        if(c[j]>c[i]){
          k=c[i];
          c[i]=c[j];
          c[j]=k;}
          }

    k=0;
    while(k!=n){
      if(c[k]!=c[k+1]){
      b=c[k];
      for(i=0;i<a;i++)
        if(x[i]==b)
          x[i]=0;
      for(i=0;i<a;i++)
        if(x[i]!=0)
          fprintf(fout,"%c",x[i]);
      fprintf(fout,"\n");  
      }
      k++;
      }
    fclose(fin);
    fclose(fout);
    return 0;
    }
