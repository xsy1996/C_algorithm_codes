#include<stdio.h>
#include<stdlib.h>
bool v[1001];
long w[1001][1001][2],top[1001],s[1001],st=1,sum=0;
int main(){
    long i,j,k,n,m,a,b,c,min;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
      scanf("%d%d%d",&a,&b,&c);
      top[a]++;
      w[a][top[a]][0]=c;
      w[a][top[a]][1]=b;
      top[b]++;
      w[b][top[b]][0]=c;
      w[b][top[b]][1]=a;
      }
    v[1]=1;s[1]=1;
    while(st<n){
      min=2147483640;
      for(i=1;i<=st;i++){
        for(j=1;j<=top[s[i]];j++)
          if(!v[w[s[i]][j][1]] && w[s[i]][j][0]!=0 && w[s[i]][j][0]<min){
            a=s[i];
            min=w[a][j][0];
            b=w[a][j][1];
            }
        }
      st++;
      s[st]=b;
      sum+=min;
      v[b]=1;
      }
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
