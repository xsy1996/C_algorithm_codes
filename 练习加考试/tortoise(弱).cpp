#include<stdio.h>
long f[351][40][40][40],x[351];
int main(){
    FILE *fin=fopen("tortoise.in","r");
    FILE *fout=fopen("tortoise.out","w");
    long a,i,j,c,k,b,d,s,n,m,q;
    fscanf(fin,"%ld%ld",&n,&m);
    for(i=1;i<=n;i++)
      fscanf(fin,"%ld",&x[i]);
    a=0;d=0;b=0;c=0;
    for(i=1;i<=m;i++){
      fscanf(fin,"%ld",&k);
      if(k==1)
        d++;
      else if(k==2)
        c++;
      else if(k==3)
        b++;
      else if(k==4)
        a++;  
      }x[0]=-1;
      f[1][0][0][0]=x[1];
      for(s=2;s<=n;s++)   
        for(i=0;i<=a;i++)
          for(j=0;j<=b;j++)
            for(k=0;k<=c;k++){
              if(s-1-i*4-j*3-k*2>d || s-1-i*4-j*3-k*2<0)
                continue;
              if(f[s-1][i][j][k]+x[s]>f[s][i][j][k])
                f[s][i][j][k]=f[s-1][i][j][k]+x[s];
              if(s>2 && k>0 && f[s-2][i][j][k-1]+x[s]>f[s][i][j][k])
                f[s][i][j][k]=f[s-2][i][j][k-1]+x[s];
              if(s>3 && j>0 && f[s-3][i][j-1][k]+x[s]>f[s][i][j][k]) 
                f[s][i][j][k]=f[s-3][i][j-1][k]+x[s];
              if(s>4 && i>0 && f[s-4][i-1][j][k]+x[s]>f[s][i][j][k])
                f[s][i][j][k]=f[s-4][i-1][j][k]+x[s];
              }
      fprintf(fout,"%ld\n",f[n][a][b][c]);
    fclose(fin);
    fclose(fout);
    return 0;
    }
