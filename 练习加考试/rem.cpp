#include<stdio.h>
long a[101],b[101];
int main()
{
    freopen("rem.in","r",stdin);
    freopen("rem.out","w",stdout);
    long i,j,k,n,x,y,s1,s2,q1,q2,t1,t2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x]++;
        b[y]++;
        s1=0;s2=0;q1=0;q2=101;
        while(a[q1]==0 && q1<=100)
            q1++;
        s1=a[q1];t1=0;
        while(b[q2]==0 && q2>=1)
            q2--;
        s2=b[q2];t2=0;
        k=0;
        while(q1<=100 || q2>=1)
        {
            while(s1<=t2 && q1<=100)
            {
                q1++;
                t1=s1;
                s1+=a[q1];
            }
            while(s2<=t1 && q2>=1)
            {
                q2--;
                t2=s2;
                s2+=b[q2];
            }
            if(q1<=100 && q2>=1 && q1+q2>k)
                k=q1+q2;
            q1++;
            while(a[q1]==0 && q1<=100)
                q1++;
            t1=s1;
            s1+=a[q1];
        }
        printf("%d\n",k);
    }
    
    return 0;
}
