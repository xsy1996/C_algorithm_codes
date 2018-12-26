#include<stdio.h>
long w,z,a,b,f[1000001];
int main()
{
    freopen("step.in","r",stdin);
    freopen("step.out","w",stdout);
    long i,j,k;
    scanf("%d%d%d%d",&w,&z,&a,&b);
    w-=z;
    f[w]=1;
    for(i=w;i>=0;i--)
        if(f[i]>0)
        {
            if(i-a>=0)
                f[i-a]+=f[i];
            if(i-b>=0)
                f[i-b]+=f[i];
        }
    printf("%d\n",f[0]);
    return 0;
} 
