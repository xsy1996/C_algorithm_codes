#include<stdio.h>
long x[1000001],h[1000001],s[1000001];
int main(){
    FILE *fin=fopen("KOF.in","r");
    FILE *fout=fopen("KOF.out","w");
    long i,j,xmax=0,n,k,max,d,deal;
    fscanf(fin,"%ld%ld%ld%ld%ld%ld",&h[0],&d,&i,&j,&s[0],&max);
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++){
      fscanf(fin,"%ld",&x[i]);
      if(x[i]>xmax)
        xmax=x[i];
      }
    i=0;
    while(h[i]>0 && i<=xmax){
      i++;
      if(d>=s[i-1])
        h[i]=h[i-1]-1;
      else
        h[i]=h[i-1]-s[i-1]+d;
      s[i]=s[i-1]+i;
      while(s[i]>max)
        s[i]-=max;
      }
    if(h[i]<=0)
      deal=i;
    for(i=1;i<=n;i++)
      if(x[i]<deal)
        fprintf(fout,"%ld %ld\n",s[x[i]],h[x[i]]);
      else
        fprintf(fout,"KO!!!\n");
    fclose(fin);
    fclose(fout);
    return 0;
    }
