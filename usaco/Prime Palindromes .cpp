/*
ID:xsy19962
TASK:pprime 
LANG:C++
*/
#include<stdio.h>
bool a[10001];
long ss[10001],top=0,string[100],t;
int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    long i,j,k,n,m,q,w,x,y,e,r,flag;
    scanf("%d%d",&x,&y);
    a[1]=1;
    for(i=2;i<=1000;i++)
        if(a[i]==0)
            for(j=i*2;j<=10000;j+=i)
                a[j]=1;
    for(i=1;i<=10000;i++)
        if(a[i]==0)
        {
            top++;
            ss[top]=i;
        }
    for(i=1;i<=100001;i++)
    {
        if(i==10 && x<=11 && y>=11)
            printf("11\n");
        t=0;w=i;q=1;
        while(w>0)
        {
            t++;
            q*=10;
            w/=10;
        }
        q/=10;
        if((i/q)%2==0 && i!=2)
            continue;
        w=i;
        for(j=1;j<=t;j++)
        {
            string[j]=w/q;
            w%=q;
            q/=10;
        }
        for(j=t+1;j<=2*t-1;j++)
            string[j]=string[2*t-j];
        q=0;w=2*t-1;
        for(j=1;j<=w;j++)
            q=q*10+string[j];
        if(q>=x && q<=y)
        {   
            flag=0;
            for(j=1;j<=top;j++)
                if(q%ss[j]==0 && q!=ss[j])
                {
                    flag=1;
                    break;
                }
            if(flag==0)
                printf("%d\n",q);
        }
        if(q>y)
            break;
    }
    return 0;
}
