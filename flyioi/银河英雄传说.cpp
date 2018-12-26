#include<stdio.h>
#include<stdlib.h>
int father[30001],before[30001],count[30001];
int find(int x){
    int f;
    if(father[x]==x)
      return x;
    f=find(father[x]);
    before[x]+=before[father[x]];
    father[x]=f;
    return father[x];
    }
int jdz(int a){
    if(a>=0)
      return a;
    else
      return -1*a;
    }
int main(){
    long x,y,i,j,k,n;
    char zl;
    for(i=1;i<=30000;i++){
      father[i]=i;
      before[i]=0;
      count[i]=1;
      }
    scanf("%ld",&n);
    for(;n>=1;n--){
      getchar();
      scanf("%c%d%d",&zl,&x,&y);
      if(zl=='M'){
        i=find(x);
        j=find(y);
        father[i]=j;
        before[i]+=count[j];
        count[j]+=count[i];
        }
      if(zl=='C')
        if(find(x)==find(y))
          printf("%ld\n",jdz(before[x]-before[y])-1);
        else
          printf("-1\n");
      }
    system("pause");
    return 0;
    }
