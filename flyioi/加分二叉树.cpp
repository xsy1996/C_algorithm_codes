#include<stdio.h>
#include<stdlib.h>
long f[31][31],a[31],root[31][31],n;
long tree(long l,long r){
    long i,j,k;
    if(f[l][r])
      return f[l][r];    
    if(r==l+1){
      root[l][r]=l;
      f[l][r]=a[r]+a[l];
      return a[r]+a[l];
      }  
    if(r==l){
      f[r][r]=a[r];
      return a[r];
      }
    for(i=l+1;i<r;i++){
      k=tree(l,i-1)*tree(i+1,r)+a[i];
      if(k>f[l][r]){
        f[l][r]=k;
        root[l][r]=i;
        }
      }
    return f[l][r];
    }
void printf(int l,int r){
    if(r<l)return;
    int i,j,k;
    printf("%d ",root[l][r]);
    printf(l,root[l][r]-1);
    printf(root[l][r]+1,r);
    return;
    }
int main(){
    long i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&a[i]);
      f[i][i]=a[i];
      }
    for(i=1;i<=n;i++)
      root[i][i]=i;
    printf("%ld\n",tree(1,n));
    printf(1,n);
     printf("\n");
    system("pause");
    return 0;
    }
