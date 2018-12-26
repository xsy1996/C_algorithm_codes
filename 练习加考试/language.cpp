#include<stdio.h>
#include<string.h>
char a[201][101];
long q[10001][3],path[201][101],f,l;
int main()
{
    long i,j,k,n,flag,len;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%s",a[i]);
    }
    f=0;l=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            flag=0;
            len=strlen(a[i]);
            for(k=0;k<=len;k++)
                if(a[i][k]!=a[j][k])
                    flag=1;
            if(flag==0)
            {
                l++;
                q[l][1]=i;
                q[l][2]=strlen(a[j])-len;
                q[l][0]=len;
            }
        }
    while(f<=l)
    {
        f++;
        for(j=1;j<=n;j++)
        {
            flag=0;
            len=q[f][2]-1
            if(flag==0)
            {
                l++;
                q[l][1]=i;
                q[l][2]=strlen(a[j])len;
                q[l][0]=len;
            }
        }
    }
    return 0;
}
