/*
ID:xsy19962
TASK:spin 
LANG:C++
*/
#include<stdio.h>
long a[101],f[101],l[101],t=0,v[101],s[101];
int main()
{
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    long i,j,k,q;
    for(i=1;i<=5;i++)
    {
        scanf("%d",&s[i]);
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            t++;
            scanf("%d%d",&f[t],&l[t]);
            l[t]+=f[t];
            a[t]=i;
        }
    }
    for(i=0;i<=359;i++)
    {
        for(k=0;k<=359;k++)
        {
            for(j=1;j<=5;j++)
                v[j]=0;
            for(j=1;j<=t;j++)
                if(f[j]<=k && l[j]>=k ||((f[j]<=k || l[j]>=k)&& l[j]<f[j]))
                    v[a[j]]=1;
            q=0;
            for(j=1;j<=5;j++)
                q+=v[j];
            if(q==5)
            {
                printf("%d\n",i);
                return 0;
            }
        }
        for(j=1;j<=t;j++)
        {
            f[j]+=s[a[j]];
            l[j]+=s[a[j]];
            f[j]%=360;
            l[j]%=360;
        }
    }
    printf("none\n");
    return 0;
}
