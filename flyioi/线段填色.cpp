#include<stdio.h>
#include<stdlib.h>
bool a[20001];
int main(){
    int sum=0,z,x,y,i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d%d%d",&z,&x,&y);
      if(z)
        for(j=x;j<y;j++)
          a[j]=1;
      else
        for(j=x;j<y;j++)
          a[j]=0;
      }
    for(i=0;i<=20000;i++)
      if(a[i])
        sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
    }

