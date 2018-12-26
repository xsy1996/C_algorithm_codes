#include<stdio.h>
long map[1001][1001],a[1001][1001][4];
int main(){
    FILE *fin=fopen("beans.in","r");
    FILE *fout=fopen("beans.out","w");
    long sum=0,n,m,i,j,k;
    fscanf(fin,"%ld%ld",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        fscanf(fin,"%ld",&map[i][j]);
    for(i=1;i<=n;i++){
      k=0;
      for(j=1;j<=m;j++)
        if(map[i][j]!=0)
          k=map[i][j];
        else
          a[i][j][0]=k;
      k=0;
      for(j=m;j>=1;j--)
        if(map[i][j]!=0)
          k=map[i][j];
        else
          a[i][j][1]=k;
      }
    for(j=1;j<=m;j++){
      k=0;
      for(i=1;i<=n;i++)
        if(map[i][j]!=0)
          k=map[i][j];
        else
          a[i][j][2]=k;
      k=0;
      for(i=n;i>=1;i--)
        if(map[i][j]!=0)
          k=map[i][j];
        else
          a[i][j][3]=k;
      }
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(map[i][j]==0)
          if((a[i][j][0]==a[i][j][1] && a[i][j][0]!=0) || (a[i][j][0]==a[i][j][2] && a[i][j][0]!=0) || (a[i][j][0]==a[i][j][3] && a[i][j][0]!=0) || (a[i][j][1]==a[i][j][2] && a[i][j][1]!=0) || (a[i][j][1]==a[i][j][3] && a[i][j][1]!=0) || (a[i][j][2]==a[i][j][3] && a[i][j][2]!=0))
            sum++;
    fprintf(fout,"%ld\n",sum);
    fclose(fin);
    fclose(fout);     
    return 0;
    }
