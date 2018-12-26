#include<stdio.h>
#include<stdlib.h>
int a[101],ans[100001],l[101];
int main(){
    int i,j,k,n,m,min,t;
    freopen("panda.in","r",stdin);
    freopen("panda.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    ans[0]=1;
     for(i=1;i<=m;i++){
       min=2147483640;
       for(j=1;j<=n;j++){
         k=l[j];
         while(k<i-1 && ans[k]*a[j]<=ans[i-1])
           k++;
         if(ans[k]*a[j]<min)
           min=ans[k]*a[j];
         l[j]=k;
         }
       ans[i]=min;
       } 
    printf("%ld\n",ans[m]);   
    system("pause");
    return 0;
    }
