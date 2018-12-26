#include<stdio.h>
int a[10];
int main(){
    FILE *fin=fopen("matches.in","r");
    FILE *fout=fopen("matches.out","w");
    int z,x,c,b,sum=0,i,j,k,n;
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    fscanf(fin,"%d",&n);
    n-=4;
    for(i=0;i<=999;i++)
      for(j=0;j<=999;j++){
        x=0;z=i;
        while(z/10!=0){
          x+=a[z%10];
          z/=10;
          }
        x+=a[z];
        c=0;z=j;
        while(z/10!=0){
          c+=a[z%10];
          z/=10;
          }
        c+=a[z];
        b=0;z=i+j;
        while(z/10!=0){
          b+=a[z%10];
          z/=10;
          }
        b+=a[z];
        if(x+c+b==n)
          sum++;
        }
    fprintf(fout,"%d\n",sum);
    fclose(fin);
    fclose(fout);
    return 0;
    }
