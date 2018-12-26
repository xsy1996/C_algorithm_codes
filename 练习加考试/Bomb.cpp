#include<stdio.h>
long x[1001],y[1001],max=0,a,b;
int main()
{
    freopen("Bomb.in","r",stdin);
    freopen("Bomb.out","w",stdout);
    long i,j,k,n,s;
    n=1;
    while(scanf("%d%d",&x[n],&y[n])!=EOF)
        n++;
    n--;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            s=0;
            a=x[i]-x[j];
            b=y[i]-y[j];
            for(k=1;k<=n;k++)
                if((x[i]-x[k])*b==(y[i]-y[k])*a)
                    s+=1;
            if(s>max)
                max=s;
        }
    printf("%d\n",max);
    return 0;
}
