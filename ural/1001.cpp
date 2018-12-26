#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long a[200001];
int main(){
    long long i,n=0;
    while(scanf("%I64d",&a[++n])!=EOF); 
    for(i=n-1;i>=1;i--)
      printf("%0.4lf\n",sqrt(a[i]*1.0));
    system("pause");
    return 0;
    } 
