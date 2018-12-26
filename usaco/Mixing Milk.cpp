/*
ID:xsy19962
PROB:milk
LANG:C++
*/
#include<stdio.h>
long a[5001][2];
void qsort(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=a[(i+j)/2][0];
    while(i<=j){
        while(a[i][0]<x)i++;
        while(a[j][0]>x)j--;
        if(i<=j){
            k=a[i][0];a[i][0]=a[j][0];a[j][0]=k;
            k=a[i][1];a[i][1]=a[j][1];a[j][1]=k;
            i++;j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    }
int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    long i,j,k,n,m,sum=0;
    scanf("%ld%ld",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%ld%ld",&a[i][0],&a[i][1]);
    qsort(1,m);
    i=0;
    while(n>0){
        i++;
        if(a[i][1]<=n){
            n-=a[i][1];
            sum+=a[i][1]*a[i][0];
            }
        else{
            sum+=n*a[i][0];
            n=0;
            }
        }
    printf("%ld\n",sum);
    return 0;
    }
