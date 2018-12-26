#include<stdio.h>
int x[30001];
int main(){
    FILE*fin=fopen("dining.in","r");
    FILE*fout=fopen("dining.out","w");
    int a=0,b=0,c=32767,d,i,j,n;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++){
      fscanf(fin,"%d",&x[i]);
      if(x[i]==1)
        a++;
      }   
    for(i=1;i<=n;i++){
      if(x[i]==2){
        b++;
        d=b+a+b-i-1;
        }
      else
        d=b+a+b-i;
      if(c>d)
       c=d;
      }
    fprintf(fout,"%d",c);
    fclose(fin);
    fclose(fout);
    return 0;
    }
