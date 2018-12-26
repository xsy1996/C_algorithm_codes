#include<stdio.h>
long c[1101][1101];
int main()
{
    FILE *fin=fopen("factor.in","r");
    FILE *fout=fopen("factor.out","w");
    long i,j,k,n,m,a,b,q;
    fscanf(fin,"%ld%ld%ld%ld%ld",&a,&b,&k,&n,&m);
    a%=10007;
    b%=10007;
    q=1;
    for(i=1;i<=n;i++)
    {
        q*=a;
        q%=10007;
    }
    for(i=1;i<=m;i++)
    {
        q*=b;
        q%=10007;
    }
    c[1][1]=1;
    for(i=2;i<=k+1;i++)
        for(j=1;j<=i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=10007;
        }
    q*=c[k+1][n+1];
    q%=10007;
    fprintf(fout,"%ld\n",q);
    fclose(fin);
    fclose(fout);
    return 0;
}


