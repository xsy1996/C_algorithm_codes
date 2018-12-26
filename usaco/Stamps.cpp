/*
ID:xsy19962
TASK:stamps
LANG:C++
*/
#include<stdio.h>
long s[2000001],n,a[51],m;
int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=0;;i++)
    {
        if(i>0 && s[i]==0)
        {
            printf("%d\n",i-1);
            break;
        }
        if(s[i]<m)
            for(j=1;j<=n;j++)
                if(s[i+a[j]]==0 || s[i+a[j]]>s[i]+1)
                    s[i+a[j]]=s[i]+1;
    }
    return 0;
}
