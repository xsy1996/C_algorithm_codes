#include<stdio.h>
#include<stdlib.h>
long a[1001],w[1001][1001],s[1001][1001],dl[1001][2];
bool v[1001][1001];
long dp(long l,long r){
    long i,j,k,t;
    if(l==r)
        return 0;
    if(v[l][r]==1)    
        return w[l][r];
    for(i=l;i<r;i++){
        k=dp(l,i)+dp(i+1,r)+(a[l]+a[r])*a[i];
        if(k>w[l][r]){
            w[l][r]=k;
            s[l][r]=i;
            }
        }
    v[l][r]=1;
    return w[l][r];
    }
int main(){
    long i,j,k,n,sum,f,l;
    freopen("separate.in","r",stdin);
    freopen("separate.out","w",stdout);
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    sum=dp(1,n);
    printf("%ld\n",sum);
    f=0;l=1;
    dl[1][0]=1;
    dl[1][1]=n;
    while(f<l){
        f++;
        if(dl[f][0]==dl[f][1])
            continue;
        printf("%ld ",s[dl[f][0]][dl[f][1]]);
        l++;
        dl[l][0]=dl[f][0];
        dl[l][1]=s[dl[f][0]][dl[f][1]];
        l++;
        dl[l][0]=s[dl[f][0]][dl[f][1]]+1;
        dl[l][1]=dl[f][1];
        }
    printf("\n");     
    //system("pause");
    return 0;
    }
/*
来自： 
日常测试20121221
*/
