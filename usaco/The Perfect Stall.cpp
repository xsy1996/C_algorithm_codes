/*
ID:xsy19962
PROB:stall4
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long m,n,map[201][201],v[201],q[201];
long match(long x){
    long i,j,k,flag=0;
    for(i=1;i<=m;i++)
        if(q[i]==0 && map[x][i]==1){
            q[i]=1;
            if(v[i]==0 || match(v[i])==1){        
                q[i]=1;
                v[i]=x;
                flag=1;
                break;
                }
            }
    return flag;
    }
int main(){
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    long a,b,i,j,k,sum=0;
    scanf("%ld%ld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%ld",&a);
        for(j=1;j<=a;j++){
            scanf("%ld",&b);
            map[i][b]=1;
            }
        }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            q[j]=0;
        sum+=match(i);
        }
    printf("%ld\n",sum);
   // system("pause");
    return 0;
    }
