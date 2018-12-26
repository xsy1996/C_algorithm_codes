#include<stdio.h>
long n,m,f[100001],a[100001],s[100001],l[100001],r[1000001],q;
long father(long x)
{
	if(f[x]!=x)
		f[x]=father(f[x]);
	return f[x];
}
long find(long x,long y)
{
    if(l[x]==0 && r[x]==0)
        return x;
    if(s[l[x]]>=y)
        return find(l[x],y);
    if(s[l[x]]==y-1)
        return x;
    if(s[r[x]]>=y-s[l[x]]-1)
        return find(r[x],y-s[l[x]]-1);
    return -1;
}
void add(long x,long y)
{
    s[x]++;
    if(a[y]<a[x])
    {
        if(l[x]==0)
        {
            l[y]=0;
            r[y]=0;
            s[y]=1;
            l[x]=y;
        }
        else 
            add(l[x],y);
    }
    else
    {
        if(r[x]==0)
        {
            l[y]=0;
            r[y]=0;
            s[y]=1;
            r[x]=y;
        }
        else
            add(r[x],y);
    }
    return;    
}
void uni(long x,long y)
{
    long i,j,k;
    if(l[y]==0 && r[y]==0)
    {
        add(x,y);
        return;
    }
    if(l[y]!=0)
    {
        uni(x,l[y]);
        l[y]=0;
    }
    if(r[y]!=0)
    {
        uni(x,r[y]);
        r[y]=0;
    }
    add(x,y);
    return;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long i,j,k,x,y;
	char c;
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
		f[i]=i;
		s[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%ld%ld",&x,&y);
        if(x==0 || y==0)
            continue;
        if(s[father(x)]>s[father(y)])
        {
            uni(father(x),father(y));
            s[father(x)]+=s[father(y)];
            f[father(y)]=father(x);
        }
        else
        {
            uni(father(y),father(x));
            s[father(y)]+=s[father(x)];
            f[father(x)]=father(y);
        }
	}
	scanf("%ld",&q);
	for(;q>=1;q--)
	{
		scanf("%s",&c);
		scanf("%ld%ld",&x,&y);
		if(c=='B')
		{
            if(s[father(x)]>s[father(y)])
            {
                uni(father(x),father(y));
                s[father(x)]+=s[father(y)];
                f[father(y)]=father(x);
            }
            else
            {
                uni(father(y),father(x));
                s[father(y)]+=s[father(x)];
                f[father(x)]=father(y);
            }
        }
		else if(c=='Q')
		{
			x=father(x);
			printf("%ld\n",find(x,y));
		}
	}
	return 0;
}
