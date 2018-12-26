#include<stdio.h>
#include<stdlib.h>
int a[101],time[101],t,n,f[1001];
int main(){
    int z,x,i,j,k;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
      scanf("%d%d",&time[i],&a[i]);
    for(i=1;i<=n;i++)
      for(j=t;j>=time[i];j--)
          if(f[j]<f[j-time[i]]+a[i])
            f[j]=f[j-time[i]]+a[i];
    printf("%d\n",f[t]);
    system("pause");
    return 0;
    }
