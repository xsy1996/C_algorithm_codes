#include<stdio.h>
#include<stdlib.h>
long jg[61][4],zyd[61][4],f[32001];
long z[61];
int main(){
    long x,c,i,j,k,m,n,t;
    scanf("%ld%ld",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld%ld%ld",&jg[i][0],&zyd[i][0],&z[i]);
        zyd[i][0]*=jg[i][0];
    }
    for(i=1;i<=n;i++)
    {
      if(z[i]!=0){
        if(jg[z[i]][1]!=0){  
          jg[z[i]][3]=jg[z[i]][1]+jg[i][0];
          zyd[z[i]][3]=zyd[z[i]][1]+zyd[i][0];
          jg[z[i]][2]=jg[z[i]][0]+jg[i][0];
          zyd[z[i]][2]=zyd[z[i]][0]+zyd[i][0];
          }
        else{
          jg[z[i]][1]=jg[i][0]+jg[z[i]][0];
          zyd[z[i]][1]=zyd[i][0]+zyd[z[i]][0];
          }
        zyd[i][0]=0;
        }
    }
      for(i=1;i<=n;i++)
    if(zyd[i][0]!=0)
      for(j=m;j>=jg[i][0];j--)
        for(k=0;k<=3;k++)
          if(j-jg[i][k]>=0 && f[j-jg[i][k]]+zyd[i][k]>f[j])
            f[j]=f[j-jg[i][k]]+zyd[i][k];
    printf("%ld\n",f[m]);
    system("pause");
    return 0; 
    }
