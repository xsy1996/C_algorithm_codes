#include<stdio.h>
#include<string.h>
long n,m,s[1001],len,v[16000001],ans=0;
char a[100001];
int main()
{
    long i,j,k=0,q;
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%s",a+1);
    len=strlen(a+1);
    for(i=1;i<=len;i++)
        if(s[a[i]]==0)
        {
            k++;
            s[a[i]]=k;
        }
    k=0;
    for(i=1;i<=n;i++)
        k=k*m+s[a[i]];
    q=1;
    for(i=1;i<n;i++)
        q*=m;
    v[k]=1;
    ans=1;
    for(i=n+1;i<=len;i++)
    {
        k=(k-q*s[a[i-n]])*m+s[a[i]];
        if(v[k]==0)
        {
            ans++;
            v[k]=1;
        }
    }
    printf("%d\n",ans);
 //   scanf("%d",&k);
    return 0;
}
