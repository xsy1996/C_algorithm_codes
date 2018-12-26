/*
ID:xsy19962 
TASK:prefix
LANG:C++
*/
#include<stdio.h>
#include<string.h>
long f[200001],m=0,len[2001],n=0;
char a[201][101],s[200100],c[101];
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    long i,j,k,q;
    char w;
    scanf("%s",c);
    while(c[0]!='.')
    {
        n++;
        len[n]=strlen(c);
        for(i=1;i<=len[n];i++)
            a[n][i]=c[i-1];
        scanf("%s",c);
    }
    while(scanf("%c",&w)!=EOF)
        if(w>='A' && w<='Z')
        {   
            m++;
            s[m]=w;
        }
    f[0]=1;
    for(i=0;i<=m;i++)
        if(f[i]==1)
            for(j=1;j<=n;j++)
                if(i+len[j]<=m && f[i+len[j]]==0)
                {
                    k=0;
                    for(q=1;q<=len[j];q++)
                        if(a[j][q]!=s[i+q])
                        {
                            k=1;
                            break;
                        }
                    if(k==0)
                        f[i+len[j]]=1;
                }
    k=0;           
    for(i=1;i<=m;i++)
        if(f[i]==1)
            k=i;
    printf("%d\n",k);
    return 0;
}
