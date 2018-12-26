#include<stdio.h>
#include<stdlib.h>
long a[1001],b[1001],dp[1001][1001],g[1001][1001];
void qsorta(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=a[(i+j)/2];
    while(i<=j){
        while(a[i]>x)i++;
        while(a[j]<x)j--;
        if(i<=j){
            k=a[i];
            a[i]=a[j];
            a[j]=k;
            i++;j--;
            }
        }
    if(l<j)qsorta(l,j);
    if(i<r)qsorta(i,r);
    return;
    }
void qsortb(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=b[(i+j)/2];
    while(i<=j){
        while(b[i]>x)i++;
        while(b[j]<x)j--;
        if(i<=j){
            k=b[i];
            b[i]=b[j];
            b[j]=k;
            i++;j--;
            }
        }
    if(l<j)qsortb(l,j);
    if(i<r)qsortb(i,r);
    return;
    }
int main(){
    long i,j,k,n;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%ld",&b[i]);
    qsorta(1,n);
    qsortb(1,n);
    dp[0][1]=-200;
    if(a[1]>b[1])
        dp[1][0]=200;
    else if(a[1]==b[1])
        dp[1][0]=0;
    else
        dp[1][0]=-200;
    for(i=0;i<=n;i++)
        for(j=0;j<=n-i;j++){
            k=-20000000;
            if(i!=0){
                if(a[i]<b[i+j])
                    k=dp[i-1][j]-200;
                else if(a[i]==b[i+j])
                    k=dp[i-1][j];
                else
                    k=dp[i-1][j]+200;
                }
            if(j!=0 && dp[i][j-1]-200>k)
                k=dp[i][j-1]-200;
            if(i==0 && j==0)
                dp[i][j]=0;
            else
                dp[i][j]=k;
            }
    k=-20000000;
    for(i=0;i<=n;i++)
        if(dp[i][n-i]>k)
            k=dp[i][n-i];
    printf("%ld\n",k);
    system("pause");
    return 0;
    }
