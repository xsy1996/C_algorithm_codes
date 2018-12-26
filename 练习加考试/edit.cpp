#include<stdio.h>
#include<string.h>
long f[10001][10001];
char a[10001],b[10001];
int main()
{
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    long i,j,k,lena,lenb,min;
    scanf("%s",a+1);
    getchar();
    scanf("%s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    f[0][0]=1;
    for(i=0;i<lena;i++)
        for(j=0;j<lenb;j++)
        if(f[i][j]>0)
        {
            if(a[i+1]==b[j+1] && (f[i][j]<f[i+1][j+1] || f[i+1][j+1]==0))
                f[i+1][j+1]=f[i][j];
            else
            {
                if(f[i][j]+1<f[i+1][j+1] || f[i+1][j+1]==0)
                    f[i+1][j+1]=f[i][j]+1;
                if(f[i][j]+1<f[i+1][j] || f[i+1][j]==0)
                    f[i+1][j]=f[i][j]+1;
                if(f[i][j]+1<f[i][j+1] || f[i][j+1]==0)
                    f[i][j+1]=f[i][j]+1;
            }
        }
  /*  for(i=1;i<=lena;i++)
        for(j=1;j<=lenb;j++)
            printf("%d %d %d\n",i,j,f[i][j]);*/
    min=2147483600;
    for(i=1;i<=lena;i++)
        if(f[i][lenb]+lena-i<min && f[i][lenb]!=0)
            min=f[i][lenb]+lena-i;
    for(j=1;j<=lenb;j++)
        if(f[lena][j]+lenb-j<min && f[lena][j]!=0)
            min=f[lena][j]+lenb-j;
    printf("%d\n",min-1);
    return 0;
}
