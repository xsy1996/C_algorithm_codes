/*
ID:xsy19962
PROB:dualpal
LANG:C++
*/
#include<stdio.h>
long sum;
void dualpal(long x,long y){
    long i,flag=1,k,t=0,a[1001];
    k=x;
    while(k>0){
        t++;
        a[t]=k%y;
        k/=y;
        }
    for(i=1;i<=t;i++)
        if(a[i]!=a[t-i+1]){
            flag=0;
            break;
            }
    sum+=flag;
    return;
    }
int main(){
    long i,j,k,n;
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%ld%ld",&n,&i);
    while(n>0){
        i++;
        sum=0;
        for(j=2;j<=10;j++)
            dualpal(i,j);
        if(sum>=2){
            n--;
            printf("%ld\n",i);
            }
        }
    return 0;
    }
