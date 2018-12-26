#include<stdio.h>
#include<string.h>
char a[1001];
long p1,p2,p3;
void deal(long x,long y)
{
    long i,j,k;
    char s[101],t=0;
    if(x>=y)
        printf("-");
    else if(x==y-1)
        return;
    else if(x>='A' && x<='Z' && y>='A' && y<='Z')
    {
        if(p1==1)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]=i+'a'-'A';
                }
        if(p1==2)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]=i;
                }
        if(p1==3)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]='*';
                }
        if(p3==1)
            for(i=1;i<=t;i++)
                printf("%c",s[i]);
        else
            for(i=t;i>=1;i--)
                printf("%c",s[i]);
    }
    else if(x>='a' && x<='z' && y>='a' && y<='z')
    {
        if(p1==1)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]=i;
                }
        if(p1==2)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]=i-'a'+'A';
                }
        if(p1==3)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]='*';
                }
        if(p3==1)
            for(i=1;i<=t;i++)
                printf("%c",s[i]);
        else
            for(i=t;i>=1;i--)
                printf("%c",s[i]);
    }
    else if(x>='0' && x<='9' && y>='0' && y<='9')
    {
        if(p1==3)
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]='*';
                }
        else
            for(i=x+1;i<y;i++)
                for(j=1;j<=p2;j++)
                {
                    t++;
                    s[t]=i;
                }
        if(p3==1)
            for(i=1;i<=t;i++)
                printf("%c",s[i]);
        else
            for(i=t;i>=1;i--)
                printf("%c",s[i]);
    }
    else
        printf("-");
    return;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    long i,j,k,n;
    scanf("%d%d%d",&p1,&p2,&p3);
    getchar();
    scanf("%s",a+1);
    n=strlen(a+1);
    for(i=1;i<=n;i++)
    {
        if(a[i]!='-')
            printf("%c",a[i]);
        else
            deal(a[i-1],a[i+1]);
    }
    printf("\n");
    return 0;
}
