#include<stdio.h>
#include<stdlib.h>
int fx[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main(){
    int i,j,k,n,x,y,sum;
    char q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){   
      getchar();
      scanf("%c",&q);
      scanf("%d",&y);
      x=q-'a'+1;
      sum=0;
      for(j=0;j<=7;j++)
        if((x+fx[j][0])>=1 && (x+fx[j][0])<=8 && (y+fx[j][1])>=1 && (y+fx[j][1])<=8)
          sum++;
      printf("%d\n",sum);        
      }
    system("pause");
    return 0;
    }
