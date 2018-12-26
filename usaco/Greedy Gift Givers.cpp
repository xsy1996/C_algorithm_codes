/*
ID:19962
PROG:gift1
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char mz[11][15];
int s[11];
int main(){
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    int i,j,k,n,money,x,y;
    char a,b,t[15],q[15];
    scanf("%d",&n);
    for(i=1;i<=n;i++,getchar())
      scanf("%s",&mz[i]);
    while(scanf("%s",&t)!=EOF){
      for(i=1;i<=n;i++)
        if(strcmp(t,mz[i])==0){
          k=i;
          break;
          }
      scanf("%d%d",&money,&x);
      if(x==0 || money==0)
        continue;
      money/=x;
      s[k]-=money*x;
      for(i=1;i<=x;i++,getchar()){
        scanf("%s",&q);
        for(j=1;j<=n;j++)
          if(strcmp(q,mz[j])==0){
            y=j;
            break;
            }
        s[j]+=money;    
        }
      }
    for(i=1;i<=n;i++)
      printf("%s %d\n",mz[i],s[i]);
      
  
    return 0;
    }
