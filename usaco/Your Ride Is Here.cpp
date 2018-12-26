/*
ID:xsy19962
PROG:ride
LANG:C++
*/

#include<stdio.h>
#include<stdlib.h>
char x[10],y[10];
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char a,b;
    long c=1,d=1;
    int i=0,j,n;
    scanf("%s",&x);
    scanf("%s",&y);
    while(x[i]>='A'){
      c*=(x[i]-'A'+1);
      i++;               
      }
      i=0;
    while(y[i]>='A'){
      d*=(y[i]-'A'+1);
      i++;               
      }
      if(c%47==d%47)
        printf("GO\n");
      else
        printf("STAY\n");
    return 0;
    }
