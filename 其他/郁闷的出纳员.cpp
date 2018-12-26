#include<stdio.h>
long tree[800001][3],l[800001],r[800001],s[800001],n=1,m,mi,change=0,sum=0,ans=0;
void t(long x,long ll,long rr)
{
    long i,j,k;
    l[x]=ll;
    r[x]=rr;
    if(ll==rr)
        return;
    tree[x][0]=(ll+rr)/2;
    n++;
    tree[x][1]=n;
    t(n,ll,(ll+rr)/2);
    n++;
    tree[x][2]=n;
    t(n,(ll+rr)/2+1,rr);
    return;
}
void add(long x,long k)
{
    long i,j;
    s[x]++;
    if(l[x]<r[x])
    {
        if(k<=tree[x][0])
            add(tree[x][1],k);
        else
            add(tree[x][2],k);
    }
    return;
}
long find(long x,long y)
{
    long i,j,k;
    if(l[x]==r[x])
        return l[x];
    if(s[tree[x][1]]>=y)
        return find(tree[x][1],y);
    else
        return find(tree[x][2],y-s[tree[x][1]]);
}
long min(long x,long y)
{
    if(x<y)
        return x;
    return y;
}
long max(long x,long y)
{
    if(x>y)
        return x;
    return y;
}
long check(long x,long ll,long rr)
{
    long i,j,k=0;
    if(s[x]==0)
        return 0;
    if(l[x]==r[x])
    {
        ans+=s[x];
        sum-=s[x];
        k=s[x];
        s[x]=0;
        return k;
    }
    if(ll<=tree[x][0])
        k+=check(tree[x][1],ll,min(rr,tree[x][0]));
    if(rr>tree[x][0])
        k+=check(tree[x][2],max(ll,tree[x][0]+1),rr);
        s[x]-=k;
    return k;
}
int main()
{
    freopen("y.in","r",stdin);
    freopen("y.out","w",stdout);
    long i,j,k;
    char ord;
    scanf("%d%d",&m,&mi);
    mi+=100000;
    t(1,1,300001);
    for(;m>=1;m--)
    {
        getchar();
      //  printf("%d\n",change);
        scanf("%c%d",&ord,&k);
        if(ord=='I')
        {
            k+=100000;
            if(k<mi)
                continue;
            k-=change;
            add(1,k);
            sum++;
        }
        if(ord=='A')
            change+=k;
        if(ord=='S')
            change-=k;
        if(ord=='F')
        {
            if(sum<k)
                printf("-1\n");
            else
                printf("%d\n",find(1,sum-k+1)+change-100000);
        }
        check(1,1,mi-change-1);
       // printf("%d %d %d\n",find(1,1),find(1,2),find(1,3));
    }
    printf("%d\n",ans);
    return 0;
}
