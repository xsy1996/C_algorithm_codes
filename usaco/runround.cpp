/*
ID:xsy19962
TASK:runround 
LANG:C++
*/
#include<stdio.h>
long m,n,v[20],a[20],flag=0;
long round()
{
    long k,s=0,i;
    k=n;
    for(i=1;i<=n;i++)
        v[i]=0;
    while(v[k]==0)
    {
        v[k]=1;
        s++;
        k=(n+1-k+a[k]-1)%n+1;
        k=n+1-k;
    }
    if(s==n && k==n)
        return 1;
    else
        return 0;
}
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    long i,j,k;
    scanf("%d",&m);
    n=0;
    while(m>0)
    {
        n++;
        a[n]=m%10;
        m/=10;
    }
    while(flag==0)
    {
        a[1]++;
        for(i=1;i<=n;i++)
            if(a[i]>=10)
            {
                a[i]-=10;
                a[i+1]++;
            }
        if(a[n+1]>0)
            n++;
        k=0;
        for(i=1;i<=9;i++)
            v[i]=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==0 || v[a[i]]!=0)
            {
                k=1;
                break;
            }
            v[a[i]]=1;
        }
        if(k)
            continue;
        flag=round();
    }
    for(i=n;i>=1;i--)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}
