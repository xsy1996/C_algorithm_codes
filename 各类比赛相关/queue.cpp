#include<stdio.h>
long ans[100001],a[100001],n,m;
void multiplication(long x[],long y)
{
    long i,j,k;
    for(i=1;i<=x[0];i++)
        x[i]*=y;
    for(i=1;i<=x[0];i++)
        if(x[i]>=10)
        {
            x[i+1]+=x[i]/10;
            x[i]%=10;
        }
    while(x[x[0]+1]>0)
    {
        x[0]++;
        if(x[x[0]]>=10)
        {
            x[x[0]+1]+=x[x[0]]/10;
            x[x[0]]%=10;
        }
    }
    return;
}
void del()
{
    long i,j,k;
    for(i=1;i<=ans[0];i++)
        ans[i]-=a[i];
    for(i=1;i<=ans[0];i++)
        if(ans[i]<0)
        {
            ans[i+1]--;
            ans[i]+=10;
        }
    while(ans[ans[0]]==0)
        ans[0]--;
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long i,j,k;
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)
    {   
        printf("0\n");
        return 0;
    }
    ans[0]=1;
    ans[1]=1;
    for(i=2;i<=n+2;i++)
        multiplication(ans,i);
    for(i=n-m+4;i<=n+3;i++)
        multiplication(ans,i);
    a[0]=1;
    a[1]=2;
    for(i=2;i<=n+1;i++)
        multiplication(a,i);
    for(i=n-m+3;i<=n+2;i++)
        multiplication(a,i);
    del();
    for(i=ans[0];i>=1;i--)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}
