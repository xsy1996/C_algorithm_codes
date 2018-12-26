#include<stdio.h>
long long ta,sum=0;
int main()
{
    freopen("Soldiers.in","r",stdin);
    freopen("Soldiers.out","w",stdout);
    long long i,j,k,n;
    char c;
    scanf("%I64d",&n);
            i=0;
            ta=0;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='<')
        {
            i++;
            ta++;
            sum+=i-ta;
        }
        if(c=='>')
        {
            i++;
        }
    }
    printf("%I64d\n",sum);
    return 0;
}
