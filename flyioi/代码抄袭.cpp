#include<stdio.h>
#include<stdlib.h>
char x[1001],y[1001];
int main(){
    int a,b,i,j,k,n,s=0;
    float c=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d %s",&a,&x);
      scanf("%d %s",&b,&y);
      if(a!=b)
        printf("No\n");
      else{
        for(j=0;j<a;j++)
          if(x[j]==y[j])
            c+=1.0;
        if(c/b>=0.7)
          printf("Yes\n");
        else
          printf("No\n");
        c=0;
        }
      
      }
    system("pause");
    return 0;
    }
