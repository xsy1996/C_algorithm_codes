#include<stdio.h>
#include<string.h>
long len;
char s[201],put[20]={0,0,'S','B','Q','W','S','B','Q','Y','S','B'};
int main()
{
    freopen("Read.in","r",stdin);
    freopen("Read.out","w",stdout);
    long i,j,k,n;
    scanf("%s",s+1);
    len=strlen(s+1);
    if(s[1]=='-')
        printf("F");
    i=1;
    if(s[1]=='-' || s[1]=='+')
        i++;
    while(s[i]=='0')
        i++;
    n=len+1;
    for(j=i;j<=len;j++)
        if(s[j]=='.')
            n=j;
    if(i==n)
        printf("0");
    for(;i<n;i++)
    {
        if(s[i]=='0')
        {
            while(s[i]=='0' && i<n)
            {
                if(n-i==9 || n-i==5)
                    printf("%c",put[n-i]);
                i++;
            }
            if(i==n)
                break;
            if(n-i!=8 && n-i!=4)
                printf("0");
        }
        printf("%d",s[i]-'0');
        if(put[n-i]!=0)
            printf("%c",put[n-i]);
    }
    if(n<len)
        printf("D");
    for(i=n+1;i<=len;i++)
        printf("%d",s[i]-'0');
    return 0;
}
