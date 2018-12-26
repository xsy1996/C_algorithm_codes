#include<stdio.h>
int x[10];
int main(){
    
    FILE *fout=fopen("sws.out","w");
    int a,b,c,d,i,j,k,n=0;
    for(i=1;i<=3;i++)
      for(j=1;j<=9;j++)
        for(k=1;k<=9;k++)
          if(i!=j && j!=k && i!=k){
            x[i]++;
            x[j]++;
            x[k]++;
            d=i*100+j*10+k;
            b=d*3;
            a=d*2;
        
            x[a%10]++;
            a/=10;
            x[a%10]++;
            x[a/10]++; 
            x[b%10]++;
            b/=10;
            x[b%10]++;
            x[b/10]++; 
            
          for(c=1;c<=9;c++)
            if(x[c]==1)
               n++;    
          if(n==9)
            fprintf(fout,"%d %d %d\n",d,2*d,3*d);
          n=0;         
          for(c=1;c<=9;c++)
            x[c]=0;       
            }
    
    fclose(fout);
    return 0;
    }
