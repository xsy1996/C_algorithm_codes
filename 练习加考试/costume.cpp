#include<stdio.h>
long x[20001];
int main(){
    FILE*fin=fopen("costume.in","r");
    FILE*fout=fopen("costume.out","w");
    long a,b,c,n,s;
    int i,j,k=0;
    fscanf(fin,"%ld %ld",&n,&s);
    for(i=1;i<=n;i++)
      fscanf(fin,"%ld",&x[i]);
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        if(x[i]+x[j]<=s)
          k++;
    fprintf(fout,"%d",k);  
    fclose(fin);
    fclose(fout);
    return 0;
    }
