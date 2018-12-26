/*
ID:xsy19962
TASK:ratios
LANG:C++
*/
#include<stdio.h>
long long a[3],b[3],c[3],s[3],x,y,z,k;
int main()
{
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    long long i,j,b2,b3,c2,c3,s1,s2,s3,q1,q2;
    for(i=1;i<=3;i++)
        scanf("%lld",&s[i]);
    for(i=1;i<=3;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=3;i++)
        scanf("%lld",&b[i]);
    for(i=1;i<=3;i++)
        scanf("%lld",&c[i]);
    for(k=1;k<=100;k++)
    {
        s1=s[1]*k;
        b2=b[1]*a[2]-b[2]*a[1];
        c2=c[1]*a[2]-c[2]*a[1];
        s2=s1*a[2]-s[2]*k*a[1];
        b3=b[1]*a[3]-b[3]*a[1];
        c3=c[1]*a[3]-c[3]*a[1];
        s3=s1*a[3]-s[3]*k*a[1];
        c3=c3*b2-b3*c2;
        s3=s3*b2-b3*s2;
        q1=s2-s3/c3*c2;
        q2=s1-(s2-s3/c3*c2)/b2*b[1]-s3/c3*c[1];
        if(q1<0)
        {
            q1*=-1;
            b2*=-1;
        }
        if(s3<0)
        {
            s3*=-1;
            c3*=-1;
        }
     //   printf("%lld   %lld %lld   %lld   %lld %lld %lld\n",k,b2,c2,c3,s1,s2,s3);
        if(q2*a[1]>=0 && q1*b2>=0 && s3*c3>=0 && s3%c3==0 && q1%b2==0 && q2%a[1]==0)
        {
            printf("%lld %lld %lld %lld\n",q2/a[1],q1/b2,s3/c3,k);
            return 0;
        }
    }
    printf("NONE\n");
    return 0;
}
