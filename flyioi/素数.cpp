#include<stdio.h>
#include<math.h>
bool x[20000001];
int main(){
    FILE *fin=fopen("ss.in","r");
    FILE *fout=fopen("ss.out","w");
    long k,a,b,i,j,n;
    fscanf(fin,"%d",&n);
    k=(int)(sqrt(n));
    for(i=2;i<=k;i++)
       if(x[i]==0)
         for(j=i*i;j<=n;j+=i)
           x[j]=1;
    j=0;
    for(i=2;i<=n;i++)
      if(x[i]==0)
        j++;
    fprintf(fout,"%d",j);
    fclose(fout);
    fclose(fin);
    return 0;
    }
