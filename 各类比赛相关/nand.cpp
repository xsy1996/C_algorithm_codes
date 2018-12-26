#include<stdio.h>
long long n,m,l[101],r[101],getl,getr,mark[101],a[1001][101],v[1001],t=0,s[1001],ch[1001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long i,j,k,ll,rr;
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&ll,&rr);
    s[0]=1;
    for(i=1;i<=m;i++)
        s[i]=s[i-1]*2;
    rr++;
    if(ll>=s[m])
    {
        printf("0\n");
        return 0;
    }
    if(rr>=s[m])
        r[m+1]=1;
    else
    {
        j=0;
        while(rr>0)
        {
            j++;
            r[j]=rr%2;
            rr/=2;
        }
    }
    j=0;
    while(ll>0)
    {
        j++;
        l[j]=ll%2;
        ll/=2;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&k);
        j=0;
        while(k>0)
        {
            j++;
            a[i][j]=k%2;
            k/=2;
           // printf("%I64d",a[i][j]);
        }
      //  printf("\n");
    }
    for(i=1;i<=m;i++)
        mark[i]=i;
    for(i=1;i<=m;i++)
        for(j=i+1;j<=m;j++)
            if(mark[j]==j)
            {
                for(k=1;k<=n;k++)
                    if(a[k][i]!=a[k][j])
                        break;
                if(k==n+1)
                    mark[j]=mark[i];
            }
  /*  for(i=1;i<=m;i++)
        printf("%I64d %I64d\n",i,mark[i]);*/
    for(i=1;i<=m;i++)
        if(v[mark[i]]==0)
        {
            t++;
            v[mark[i]]=1;
        }
    k=0;
    for(i=1;i<=m;i++)
        v[i]=0;
    for(i=m;i>=1;i--)
    {
        if(l[i]==0 && ch[mark[i]]==1)
            break;
        if(l[i]==1)
        {
            if(v[mark[i]]==1 && ch[mark[i]]==0)
            {
                getl+=s[t-k];
                break;
            }
            if(v[mark[i]]==0)
            {
                getl+=s[t-k-1];
                v[mark[i]]=1;
                ch[mark[i]]=1;
                k++;
            }
        }
        if(v[mark[i]]==0)
        {
            v[mark[i]]=1;
            ch[mark[i]]=0;
            k++;
        }
    }
    if(r[m+1]==1)
        getr=s[k];
    else
    {
        k=0;
        for(i=1;i<=m;i++)
        {
            v[i]=0;
            ch[i]=0;
        }
        for(i=m;i>=1;i--)
        {
            if(r[i]==0 && ch[mark[i]]==1)
                break;
            if(r[i]==1)
            {
                if(v[mark[i]]==1 && ch[mark[i]]==0)
                {
                    getr+=s[t-k];
                    break;
                }
                if(v[mark[i]]==0)
                {
                    getr+=s[t-k-1];
                    v[mark[i]]=1;
                    ch[mark[i]]=1;
                    k++;
                }
            }
            if(v[mark[i]]==0)
            {
                v[mark[i]]=1;
                ch[mark[i]]=0;
                k++;
            }
        }
      //  printf("%I64d ",getr);
    }
    //printf("\n%I64d\n",getr);
    printf("%I64d",getr-getl);
    return 0;
}
