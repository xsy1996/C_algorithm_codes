#include<stdio.h>
#include<string.h>
char e[101]="ENDOFINPUT",a[101],x[1000001];
double p[27],ss,k;
long s[100],sum,t;
double q(double i)
{
    return i*i;
}
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    long i,j,flag,len;
    p[4]=0.1268;
    p[19]=0.0978;
    p[0]=0.0788;
    p[14]=0.0766;
    p[8]=0.0707;
    p[13]=0.0706;
    p[18]=0.0634;
    p[17]=0.0594;
    p[7]=0.0573;
    while(1)
    {
        gets(a);
      //  puts(a);
        len=strlen(a+1);
        flag=0;
        for(i=0;i<len;i++)
            if(a[i]!=e[i])
                flag=1;
        if(flag==0)
            break;
        sum=0;
        for(i=0;i<26;i++)
            s[i]=0;
        gets(x+1);
        len=strlen(x+1);
        for(i=1;i<=len;i++)
        {
            if(x[i]>='A' && x[i]<='Z')
            {
                s[x[i]-'A']++;
                sum++;
            }
        
            if(x[i]>='a' && x[i]<='z')
            {
                s[x[i]-'a']++;
                sum++;
            }
        }
        ss=2147483600;
        for(i=0;i<26;i++)
        {
            k=0;
            for(j=0;j<26;j++)
                if(p[(i+j)%26]!=0)
                k+=q(s[j]*1.0/sum-p[(i+j)%26]);
            if(k<ss)
            {
                ss=k;
                t=i;
            }
        }
        for(i=1;i<=len;i++)
            if(x[i]>='A' && x[i]<='Z')
                printf("%c",(x[i]-'A'+t)%26+'A');
            else if(x[i]>='a' && x[i]<='z')
                printf("%c",(x[i]-'a'+t)%26+'A');
            else
                printf("%c",x[i]);
        printf("\n");
        gets(a);
      //  puts(a);
    }
    return 0;
}
