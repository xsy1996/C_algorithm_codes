#include<stdio.h>
#include<stdlib.h>
int a[105];
int main(){
    int sum=0,i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        if(a[i]>a[j]){
          k=a[i];
          a[i]=a[j];
          a[j]=k;
          }
    n=n/2+1;
    for(i=1;i<=n;i++)
      sum+=a[i]/2+1;
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
