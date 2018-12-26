#include<stdio.h>
#include<stdlib.h>
long f[101],s[5000][3],min,num,n,m;
void qsort(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=s[(i+j)/2][0];
    while(i<=j){
        while(s[i][0]>x)i++;
        while(s[j][0]<x)j--;
        if(i<=j){
            k=s[i][0];
            s[i][0]=s[j][0];
            s[j][0]=k;
            k=s[i][1];
            s[i][1]=s[j][1];
            s[j][1]=k;
            k=s[i][2];
            s[i][2]=s[j][2];
            s[j][2]=k;
            i++;j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    } 
long father(long x){
    if(f[x]==x)
        return x;
    else{
        f[x]=father(f[x]);
        return f[x];
        }
    }
void kruskal(){
    long i,j,k;
    for(i=1;i<=n;i++)    
        f[i]=i;
    for(i=m;i>=1;i--)
        if(father(s[i][1])!=father(s[i][2])){
            f[father(s[i][1])]=father(s[i][2]);
            k=i;
            num--;
            }
    if(num==1 && s[k][0]-s[m][0]<min)
        min=s[k][0]-s[m][0];
    return;
    }
void find(){
    long k;
    num=n;
    kruskal();
    while(num==1){
        k=s[m][0];
        while(s[m][0]<=k)
            m--;
        num=n;
        kruskal();
        }
    return;
    } 
int main(){
    long i,j,k;
    scanf("%ld%ld",&n,&m);
    while(n!=0 || m!=0){
        if(n==0 || m==0){
            printf("-1\n");
            scanf("%ld%ld",&n,&m);
            continue;
            }
        min=100000000;
        for(i=1;i<=m;i++)
            scanf("%ld%ld%ld",&s[i][1],&s[i][2],&s[i][0]);
        qsort(1,m);
        find();
        if(min==100000000)
            printf("-1\n");
        else
            printf("%ld\n",min);
        scanf("%ld%ld",&n,&m);
        }
    system("pause");
    return 0;
    }



