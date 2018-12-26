/*
ID:xsy19962
PROB:barn1
LANG:C++ 
*/
#include<stdio.h>
#include<stdlib.h>
bool live[201];
long a[201];
void qsort(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=a[(i+j)/2];
    while(i<=j){
        while(a[i]>x)i++;
        while(a[j]<x)j--;
        if(i<=j){
            k=a[i];a[i]=a[j];a[j]=k;
            i++;j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    }
int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    long sum,min=32767,max=0,t=0,i,j,k,s,n,m;
    scanf("%ld%ld%ld",&m,&s,&n);
    for(i=1;i<=n;i++){
        scanf("%ld",&k);
        if(k<min)
            min=k;
        if(k>max)
            max=k;
        live[k]=1;
        }
    k=0;
    for(i=min;i<=max;i++){
        if(live[i]==0)k++;
        else if(k!=0){
            t++;
            a[t]=k;
            k=0;
            }
        }
    qsort(1,t);
    sum=max-min+1;
    for(i=1;i<m;i++)
        sum-=a[i];
    printf("%ld\n",sum);
    return 0;
    }
