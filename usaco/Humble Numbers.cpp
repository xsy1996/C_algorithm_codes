/*
ID:xsy19962
TASK:humble 
LANG:C++
*/
#include<stdio.h>
long n,m,a[101],h[100001],v[101],min;
int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    m++;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    h[1]=1;
    for(i=1;i<=n;i++)
        v[i]=1;
    for(i=2;i<=m;i++)
    {
        min=2147383600;
        for(j=1;j<=n;j++)
        {
            while(h[v[j]]*a[j]<=h[i-1])
                v[j]++;
            if(h[v[j]]*a[j]<min)
                min=h[v[j]]*a[j];
        }
        h[i]=min;
    }
    printf("%d\n",h[m]);
    return 0;
}
