#include<stdio.h>
int x[101];
bool z[10000][101];
int main(){
    FILE*fin=fopen("score.in","r");
    FILE*fout=fopen("score.out","w");
    int a,b,c,i,j,n,m,sum=0,fsx;
    fscanf(fin,"%d%d",&n,&m);
    m=(3*m)/2;
    for(i=1;i<=n;i++){
      fscanf(fin,"%d%d",&a,&b);
      x[b]++;
      z[a][b]=true;
      }     
    a=m;
    for(i=100;i>=0;i--){
      sum+=x[i];
      if(x[i]<a)
        a-=x[i];
      else
        break;  
      }
      fsx=i;
      fprintf(fout,"%d %d\n",fsx,sum);
    for(i=100;i>=fsx;i--)
      for(j=1000;j<=9999;j++)
        if(z[j][i]==true)
          fprintf(fout,"%d %d\n",j,i);
      
    return 0;
    }

