#include<stdio.h>
#include<string.h>
char s[51],f[11]={'0','0','S','B','Q','W','S','B','Q','Y','S'};
int main(){
    FILE *fin=fopen("readnum.in","r");
    FILE *fout=fopen("readnum.out","w");
    int z,x,c=0,i,j,k,n=0;
    fscanf(fin,"%s",s);
    if(s[0]=='-')
      fprintf(fout,"F");
    i=0;
    k=strlen(s);
    if(s[i]=='+' || s[i]=='-')
      i++;
    while(s[i]=='0')
      i++;
    c=i;
    i--;
    while(s[c]!='.' && c<k){
      n++;
      c++;
      }
      
    if(n==0)
      fprintf(fout,"0");
    else{
      x=0;
      for(j=1;j<=n;j++){
        if(s[j+i]!='0'){                 
          fprintf(fout,"%c",s[j+i]);
          if(f[n-j+1]!='0')
            fprintf(fout,"%c",f[n-j+1]);
          x=0;
          continue;
          }
        if(s[j+i]=='0' && (f[n-j+1]=='W' || f[n-j+1]=='Y' || f[n-j+1]=='0') && x!=3){
          if(f[n-j+1]!='0'){
            fprintf(fout,"%c",f[n-j+1]);
            if(s[j+i+1]!='0')
              fprintf(fout,"0");
            }
          x=0;
          continue;  
          }
        if(s[j+i]=='0' && s[j+i+1]>='1' && s[j+i+1]<='9'){
          fprintf(fout,"0");
          x=0;
          continue;
          }
        x++; 
        }    
      }
    
    if(c<k-1){
      fprintf(fout,"D");
      for(i=c+1;i<k;i++){
         fprintf(fout,"%c",s[i]);
         }
       }
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
    }
