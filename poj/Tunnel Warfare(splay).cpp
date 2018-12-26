#include<stdio.h>
long l[50001],r[50001],f[50001],n,m,s[50001],e[50001],x,last[50001],top=0;
void ro(long a)
{   
    long b;
    b=f[a];
    if(l[f[b]]==b)
        l[f[b]]=a;
    else
        r[f[b]]=a;
    f[a]=f[b];
    f[b]=a;
    if(l[b]==a)
    {
        if(r[a]!=0)
            f[r[a]]=b;
        l[b]=r[a];
        r[a]=b;
    }
    else
    {
        if(l[a]!=0)
            f[l[a]]=b;
        r[b]=l[a];
        l[a]=b;
    }
    s[b]=s[l[b]]+s[r[b]]+1;
    s[a]=s[l[a]]+s[r[a]]+1;
    return;
}
void rotate(long a)
{
    long i,j,k;
   // printf("%d %d %d %d %d\n",a,f[a],f[f[a]],f[f[f[a]]],f[f[f[f[a]]]]);
    while(f[f[a]]!=0)
    {
        if((l[f[f[a]]]==f[a] && l[f[a]]==a) || (r[f[f[a]]]==f[a] && r[f[a]]==a))
        {
            ro(f[a]);
            ro(a);
        }
        else
        {
            ro(a);
            ro(a);
        }
    }
    if(f[a]!=0)
        ro(a);
    return;
}
void R()
{
    x=last[top];
    top--;
    rotate(x);
    e[x]=1;
    if(e[x-1]==1)
    {
        rotate(x-1);
        f[x-1]=x;
        l[x]=x-1;
    }
    if(e[x+1]==1)
    {
        rotate(x+1);
        f[x+1]=x;
        r[x]=x+1;
    }
    s[x]=s[l[x]]+s[r[x]]+1;
    return;
}
void d()
{
    top++;
    last[top]=x;
    rotate(x);
    e[x]=0;
    s[x]=0;
    f[l[x]]=0;
    f[r[x]]=0;
    l[x]=0;
    r[x]=0;
    return;
}
void q()
{
    long i,j,k;
    rotate(x);
    printf("%d\n",s[x]);
    return;
}
int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    long i,j,k;
    char o;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        r[i]=i+1;
        s[i]=n-i+1;
        e[i]=1;
        f[i]=i-1;
    }
    r[n]=0;
    for(i=1;i<=m;i++)
    {
        getchar();
        scanf("%c",&o);
        if(o!='R')
            scanf("%d",&x);
        if(o=='Q')
            q();
        if(o=='R')
            R();
        if(o=='D')
            d();
    /*    for(j=1;j<=n;j++)
            printf("%d ",s[j]);
        printf("\n");*/
    }
    return 0;
}
