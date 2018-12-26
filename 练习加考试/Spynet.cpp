#include<stdio.h>
long s[3001],c[3001],t=0,f[3001],v[3001],map[3001][3001],d[3001],ff,ll,q[3001];
long fa(long x)
{
    if(f[x]==100001)
        return 100001;
    if(f[x]!=x)
        f[x]=fa(f[x]);
    return f[x];
}
void qsort(long l,long r)
{
    long i,j,k,x;
    i=l;j=r;
    x=c[s[(i+j)/2]];
    while(i<=j)
    {
        while(c[s[i]]<x)i++;
        while(c[s[j]]>x)j--;
        if(i<=j)
        {
            k=s[i];
            s[i]=s[j];
            s[j]=k;
            i++;j--;
        }
    }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
}
int main()
{
    freopen("Spynet.in","r",stdin);
    freopen("Spynet.out","w",stdout);
    long i,j,k,m,n,x,y,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        f[i]=i;
    scanf("%d",&t);
    v[0]=1;f[0]=100001;
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        s[i]=x;
        c[x]=y;
        v[x]=1;
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
    }
    for(i=1;i<=t;i++)
    {
        ff=0;ll=1;
        d[1]=s[i];
        while(ff<ll)
        {
            ff++;
            for(j=1;j<=n;j++)
                if((q[j]==0 || (v[j]>0 && c[fa(j)]>c[s[i]])) && map[d[ff]][j]==1)
                {
                    f[j]=s[i];
                    ll++;
                    d[ll]=j;
                    q[j]=1;
                }
        } 
    }  
  /*  for(i=1;i<=n;i++)
        printf("%d  ",fa(i));
    printf("\n");*/
    for(i=1;i<=n;i++)
        if(q[i]==0 && v[i]==0)
        {
            printf("NO\n%d\n",i);
            return 0;
        }
    qsort(1,t);
    sum=0;
   /* for(i=1;i<=t;i++)
        printf("%d  ",c[s[i]]);
    printf("\n");*/
    for(i=1;i<=t;i++)
        if(fa(s[i])!=100001)
        {
            sum+=c[fa(s[i])];
            f[fa(s[i])]=100001;
        }
    printf("YES\n%d\n",sum);
}
