#include<stdio.h>
#include<string.h>
int main(){
  FILE*fin=fopen("lucky.in","r");
  FILE*fout=fopen("lucky.out","w");
  int a=0,b,c,i,j,m,n;
  fscanf(fin,"%d%d",&n,&m);
  int x[1001],y[1001];
  for(i=1;i<=n;i++){
    fscanf(fin,"%d",&y[i]);
    if(y[i]<m)
    x[y[i]]=10;
    }
  for(i=1;i<n;i++)
    for(j=i;j<=n;j++)
      if(y[i]!=1&&y[j]!=1){
      if(y[i]*y[j]<=m){
        x[y[i]*y[j]]=10;
        n++;
        y[n]=y[i]*y[j];
         }
      }
  for(i=1;i<=1001;i++)
    if(x[i]==10){
      a++;
      y[a]=i;
      }
    if(a==0)
      fprintf(fout,"No answer!");
    else{
    fprintf(fout,"%d\n",a);
    for(i=1;i<=a;i++) 
    fprintf(fout,"%d ",y[i]);
    }   
  
  fclose(fin);
  fclose(fout);
  return 0;
  }
