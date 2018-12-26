/*
ID:xsy19962
TASK:crypt1
LANG:C++
*/
#include<stdio.h>
long x,s1,s2,s,num[10],ans=0;
int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    long i,j,k,q,w,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        num[k]=1;
    }
    for(i=1;i<=9;i++)
    {
        if(num[i]==0)
            continue;
        for(j=1;j<=9;j++)
        {
            if(num[j]==0)
                continue;
            for(k=1;k<=9;k++)
            {
                if(num[k]==0)
                    continue;
                x=i*100+j*10+k;               
                for(q=1;q<=9;q++)
                {
                    if(num[q]==0)
                        continue;
                    s1=x*q;
                    if(s1>=1000 || s1<100 || num[s1%10]==0 || num[s1%100/10]==0 || num[s1/100]==0)
                        continue;
                    for(w=1;w<=9;w++)
                    {
                        if(num[w]==0)
                            continue;
                        s2=x*w;
                        if(s2>=1000 || s2<100 || num[s2%10]==0 || num[s2%100/10]==0 || num[s2/100]==0)
                            continue;
                        s=s1+s2*10;
                        if(s>=10000 || s<1000 || num[s%10]==0 || num[s%100/10]==0 || num[s%1000/100]==0 || num[s/1000]==0)
                            continue;
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
