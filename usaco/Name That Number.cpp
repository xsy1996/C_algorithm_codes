/*
ID:xsy19962
PROG:namenum
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char x[13],y[13];
int main(){
    freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	freopen("dict.txt", "r", stderr);
    int i,j,k=0,xlen,ylen,flag=0;
    scanf("%s",x);
    xlen=strlen(x);
    while(fscanf(stderr, "%s", y) != EOF){
      ylen=strlen(y);
      if(xlen!=ylen)
        continue;
      k=0;
      for(i=0;i<xlen;i++)
        if(x[i]!=a[y[i]-'A']){
          k=1;
          break;
          }     
      if(k==0){
        printf("%s\n",y);
        flag=1;
        }                   
      }
    if(flag==0)
      printf("NONE\n");
   // system("pause");
    return 0;
    }
