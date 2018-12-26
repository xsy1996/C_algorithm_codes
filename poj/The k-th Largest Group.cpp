#include<stdio.h>
long a[200001],n,m,s[200001],f[200001],ss;
long father(long x)
{
    if(f[x]!=x)
        f[x]=father(f[x]);
    return f[x];
}
void add(long k,long d)
{
    long i,j;
    while(k<=n)
    {
        a[k]+=d;
        k+=k&(k^(k-1));
    }
    return;
}
long find(long k)
{ 
    int ans=0, cnt=0,i; 
    for (i=20;i>=0;i--)
    { 
        ans+=(1<<i); 
        if(ans>=n || cnt+a[ans]>=k)  
            ans-=(1<<i); 
        else 
            cnt+=a[ans];
    }
    return ans+1;
}
int main()
{
   // freopen("k.in","r",stdin);
    //freopen("k.out","w",stdout);
    long i,j,k,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        f[i]=i;
        s[i]=1;
    }
    add(1,n);
    ss=n;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==0)
        {
            scanf("%d%d",&x,&y);
            x=father(x);
            y=father(y);
            if(x==y)
                continue;
            add(s[x],-1);
            add(s[y],-1);
            add(s[x]+s[y],1);
            f[x]=y;
            s[y]+=s[x];
            ss--;
        }
        if(k==1)
        {
            scanf("%d",&x);
            printf("%d\n",find(ss-x+1));
        }
    }
    return 0;
}
