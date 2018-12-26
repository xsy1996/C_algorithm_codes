#include<stdio.h>
bool map[1002][1002];
long f[1002][1002],max=0;
int main(){
    FILE *fin=fopen("easy.in","r");
    FILE *fout=fopen("easy.out","w");
    int k=0,i,j,m,n,min=1111;
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++){
      k=0;
      for(j=1;j<=m;j++){
        fscanf(fin,"%d",&map[i][j]);
        if(map[i][j]==1)
          k=0;
        if(map[i][j]==0)
          k++;
        f[i][j]=k;
        }
      }
    for(i=0;i<=n;i++){
      map[i][0]=1;
      map[i][m+1]=1;
      }
    for(i=0;i<=m;i++){
      map[0][i]=1;
      map[n+1][i]=1;
      }
    
    for(i=1;i<=n;i++)
      for(j=m;j>=1;j--)
        if(map[i][j]==0){
          k=i;min=1111;
          while(map[k][j]==0){
            if(f[k][j]<min)
              min=f[k][j];
            if((k-i+1)*min>max)
              max=(k-i+1)*min;
            k++;
            }
          }
    fprintf(fout,"%d\n",max);
    fclose(fin);
    fclose(fout);
    return 0;
    }
