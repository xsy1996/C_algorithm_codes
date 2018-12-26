#include<stdio.h>
#include<string.h>
int main(){
  FILE*fin=fopen("word.in","r");
  FILE*fout=fopen("word.out","w");
  char x[1001];
  int y,i,j,a=0,b=0,c;
  fscanf(fin,"%s",&x);
  y=strlen(x);
  for(i=0;i<y;i++)
    if(x[i]<'a')
      x[i]+=32;
  for(i=1;i<y;i++){
    if(x[i]==x[0]){
      for(j=i+1;j<y;j++)
        if(x[j]!=x[j-i])
          a++;
      if(a==0){
        fprintf(fout,"%d\n",i);
        for(j=0;j<i;j++)
        fprintf(fout,"%c",x[j]);
        b=10;
        break;
        }
      }
    a=0;
    }
  if(b!=10)
    fprintf(fout,"%d\n%s",y,x);
  fclose(fin);
  fclose(fout);
  return 0;
  }
