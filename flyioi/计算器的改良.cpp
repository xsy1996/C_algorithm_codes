#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1001],x;
int main()
{
    long i,j,k,q,a[2],s1[2],n,w=0;
    a[1]=0;a[0]=0;s1[0]=0;s1[1]=0;
    scanf("%s",s+1);
    n=strlen(s+1);
    i=1;
    while(i<=n)
    {
        k=0;q=1;
        if(s[i]=='-')
        { 
            i++;
            q=-1;
        }
        if(s[i]=='+')
            i++;
        while(s[i]>='0' && s[i]<='9')
        {
            k=k*10+s[i]-'0'; 
            i++; 
        }
        if(s[i]>='a' && s[i]<='z')
        {
            x=s[i];
            i++;
            if(k==0)
                a[w]+=q;
            else
                a[w]+=q*k; 
        }
        else
            s1[w]+=k*q;
        if(s[i]=='=')
        {
            i++;  
            w++;
        }
    }
    printf("%c=%0.3lf\n",x,(s1[1]-s1[0])*1.0/(a[0]-a[1])*1.0);
    system("pause");
    return 0;
}