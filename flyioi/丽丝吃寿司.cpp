#include<stdio.h>
#include<stdlib.h>
long a[100001];
int main(){
    long i,j,k,m,n,max=0,h,t,max2;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
      scanf("%ld",&a[i-1]);
    scanf("%ld",&m);
    for(i=0;i<m;i++)
        max+=a[i];
    max2=max;
    h=0;t=m-1;
    for(i=1;i<n;i++)
    {
        max2-=a[h];h++;t++;if(t==n)t=0;max2+=a[t];
        if(max2>max)max=max2;
    }
    printf("%ld\n",max);
    system("pause");
    return 0;
    }
