#include<stdio.h>
#include<stdlib.h>
int fm[51][2],a[2000],s[100001];
bool f[100021];
int main(){
    int z,x,i,j,k,t=0,n=0;
    scanf("%d",&z);
    for(i=1;i<=z;i++)
      scanf("%d",&fm[i][0]);
    for(i=1;i<=z;i++)
      scanf("%d",&fm[i][1]);
    for(i=1;i<=z;i++)
      for(j=1;j<=fm[i][1];j++){
        n++;
        a[n]=fm[i][0];
        }
    for(i=1;i<=n;i++)
      for(j=t;j>=0;j--)
        if(f[s[j]+a[i]]==0){
          t++;
          s[t]=s[j]+a[i];
          f[s[j]+a[i]]=1;
          }
    printf("%d\n",t);
    system("pause");
    return 0;
    }
