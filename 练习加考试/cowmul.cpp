#include<stdio.h>
#include<string.h>

int main(){
    FILE*fin=fopen("cowmul.in","r");
    FILE*fout=fopen("cowmul.out","w");
    int a,b,c,i=1,j=1,k,n=0,x[11],y[11];
    fscanf(fin,"%d %d",&a,&b);
    while(a/10!=0){
      x[i]=a%10;
      i++;
      a/=10;            
      }
    x[i]=a;
    while( b/10!=0){
      y[j]=b%10;
      j++;
      b/=10;
      }
    y[j]=b;
    for(a=1;a<=i;a++)
      for(b=1;b<=j;b++)
        n+=x[a]*y[b];        
    fprintf(fout,"%d",n);  
     
    fclose(fin);
    fclose(fout);
    return 0;
    }
