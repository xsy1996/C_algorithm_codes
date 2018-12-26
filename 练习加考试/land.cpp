#include<stdio.h>
long s[2001],t,n;
double x[2001],y[2001],xl[2001];
void qsort(long l,long r)
{
    long i,j;
    double a,b,k;
    i=l;j=r;
    a=x[(i+j)/2];
    b=y[(i+j)/2];
    while(i<=j)
    {    
        while(x[i]<a || (x[i]==a && y[i]<b))i++;
        while(x[j]>a || (x[j]==a && y[j]>b))j--;
        if(i<=j)
        {
            k=x[i];
            x[i]=x[j];
            x[j]=k;
            k=y[i];
            y[i]=y[j];
            y[j]=k;
            i++;j--;
        }
    }
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
    return;
}
void tb()
{
    long i,j;
    double k;
    t=1;
    xl[t]=2147483600;
    s[t]=1;
    for(i=2;i<=n;i++)
    {
        if(x[i]-x[s[t]]==0)
            k=2147483600;
        else
            k=(y[i]-y[s[t]])*1.0/(x[i]-x[s[t]]);
        while(k>xl[t])
        {
            t--;
            if(x[i]-x[s[t]]==0)
                k=2147483600;
            else
                k=(y[i]-y[s[t]])*1.0/(x[i]-x[s[t]]);
        }
        t++;
        s[t]=i;
        xl[t]=k;
    }
    xl[t]=-2147483600;
    for(i=n-1;i>=1;i--)
    {
        if(x[i]-x[s[t]]==0)
            k=-2147483600;
        else
            k=(y[i]-y[s[t]])*1.0/(x[s[t]]-x[i]);
        while(k<xl[t])
        {
            t--;
            if(x[i]-x[s[t]]==0)
                k=2147483600;
            else
                k=(y[i]-y[s[t]])*1.0/(x[s[t]]-x[i]);
        }
        t++;
        s[t]=i;
        xl[t]=k;
    }
    return;
}
double jdz(double a)
{
    if(a>=0)
        return a;
    else
        return -1.0*a;
}
double ss(long i,long j,long a)
{
    return jdz((x[i]-x[a])*(y[j]-y[a])-(x[j]-x[a])*(y[i]-y[a]));
}
int main()
{
    freopen("land.in","r",stdin);
    freopen("land.out","w",stdout);
    long i,j,a,b,k;
    double max=0,max1,max2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    qsort(1,n);
    s[0]=1;
    xl[0]=2147483600;
    tb();
    for(i=1;i<=t;i++)
    {    
        a=i;b=i+1;
        for(j=i+1;j<=t;j++)
        {   
            max1=ss(s[i],s[j],s[a]);
            max2=ss(s[i],s[j],s[b]);
            while(a+1<j && max1<=ss(s[i],s[j],s[a+1]))
            {
                max1=ss(s[i],s[j],s[a+1]);
                a++;
            }    
            while(b!=i && max2<=ss(s[i],s[j],s[((b==t)?1:(b+1))%t]))
            {
                b=(b==t)?1:(b+1);
                max2=ss(s[i],s[j],s[(b)%t]);
            }    
            if(max1+max2>max)
                max=max1+max2;
        }
    }
/*    printf("%d\n",t);
    for(i=1;i<=t;i++)
        printf("%lf %lf \n",x[s[i]],y[s[i]]);*/
    printf("%0.3lf\n",max/2);
    return 0;
}
