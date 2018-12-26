#include<stdio.h>
long v[2001][2001],n,m,costmin[1001];
char s[10001];
int main()
{
    freopen("cheappal.in","r",stdin);
    freopen("cheappal.out","w",stdout);
    long i,j,k,x,y;
    char a;
    scanf("%d%d",&m,&n);
    getchar();
    scanf("%s",s+1);
    for(i=1;i<=m;i++)
    {
        getchar();
        scanf("%c",&a);
        scanf("%d%d",&x,&y);
        if(x<y)
            costmin[a]=x;
        else
            costmin[a]=y;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            v[i][j]=2147483600;
    s[0]=-100;
    s[n+1]=-321;
    for(i=1;i<=n;i++)
        v[1][i]=0;
    for(i=1;i<n;i++)
        if(s[i]==s[i+1])
            v[2][i]=0;
    for(i=1;i<n;i++)
        for(j=1;j<=n;j++)
        {
            if(v[i][j]==2147483600)
                continue;
            if(j>1 && j+i<=n && s[j-1]==s[i+j] && v[i][j]<v[i+2][j-1])
                v[i+2][j-1]=v[i][j];
            if(j>1 && v[i][j]+costmin[s[j-1]]<v[i+1][j-1])
                v[i+1][j-1]=v[i][j]+costmin[s[j-1]];
            if(j+i<=n && v[i][j]+costmin[s[i+j]]<v[i+1][j])
                v[i+1][j]=v[i][j]+costmin[s[j+i]];
        }
    printf("%d\n",v[n][1]);
    return 0;
}
