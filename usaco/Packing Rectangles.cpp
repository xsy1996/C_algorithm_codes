/*
ID:xsy19662 
TASK:packrec
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long s[1000001][3],t=0,x[100],y[100],v[100],a[100];
void qsort(long l,long r)
{
    long i,j,k,x1,y1;
    i=l;j=r;
    x1=s[(i+j)/2][0];
    y1=s[(i+j)/2][1];
    while(i<=j)
    {
        while(s[i][0]<x1 || (s[i][0]==x1 && s[i][1]<y1))i++;
        while(s[j][0]>x1 || (s[j][0]==x1 && s[j][1]>y1))j--;
        if(i<=j)
        {
            k=s[i][0];
            s[i][0]=s[j][0];
            s[j][0]=k;
            k=s[i][1];
            s[i][1]=s[j][1];
            s[j][1]=k;
            k=s[i][2];
            s[i][2]=s[j][2];
            s[j][2]=k;
            i++;
            j--;
        }
    }
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
    return;
}
void count()
{
    long q,p,i,j,k;
    p=0;
    for(i=2;i<=8;i+=2)
        if(a[i]>p)
            p=a[i];
    q=a[1]+a[3]+a[5]+a[7];
    t++;
    s[t][0]=q*p;
    if(p>q)
    {
        s[t][1]=q;
        s[t][2]=p;
    }
    else
    {
        s[t][1]=p;
        s[t][2]=q;
    }
    
    p=a[1]+a[3]+a[5];
    if(p<a[7])
        p=a[7];
    q=0;
    for(i=2;i<=6;i+=2)
        if(q<a[i])
            q=a[i];
    q+=a[8];
    t++;
    s[t][0]=q*p;
    if(p>q)
    {
        s[t][1]=q;
        s[t][2]=p;
    }
    else
    {
        s[t][1]=p;
        s[t][2]=q;
    }
    
    if(a[2]>a[4])
        p=a[2];
    else
        p=a[4];
    p+=a[6];
    if(p<a[8])
        p=a[8];
    if(a[1]+a[3]>a[5])
        q=a[1]+a[3];
    else
        q=a[5];
    q+=a[7];
    t++;
    s[t][0]=q*p;
    if(p>q)
    {
        s[t][1]=q;
        s[t][2]=p;
    }
    else
    {
        s[t][1]=p;
        s[t][2]=q;
    }
    
    if(a[3]>a[5])
        p=a[3];
    else
        p=a[5];
    p+=a[1]+a[7];
    if(a[2]>a[8])
        q=a[2];
    else
        q=a[8];
    if(q<a[4]+a[6])
        q=a[4]+a[6];
    t++;
    s[t][0]=q*p;
    if(p>q)
    {
        s[t][1]=q;
        s[t][2]=p;
    }
    else
    {
        s[t][1]=p;
        s[t][2]=q;
    }
/*  */  
    p=a[7]+a[5];
    if(a[6]<a[8])
    {
        if(a[3]+a[7]>p)
            p=a[3]+a[7];
        if(a[4]+a[6]<=a[8] && a[1]>p)
            p=a[1];    
        if(a[4]+a[6]>a[8] && a[1]+a[3]>p)
            p=a[1]+a[3];
    }
    else if(a[6]>=a[8]+a[2])
    {
        if(a[3]>p)
            p=a[3];
        if(a[1]+a[5]>p)
            p=a[1]+a[5];
    }
    else if(a[6]>=a[8] && a[6]<a[8]+a[2])
    {
        if(a[3]+a[1]>p)
            p=a[3]+a[1];
        if(a[1]+a[5]>p)
            p=a[1]+a[5];
    }           
    if(a[2]+a[8]>a[4]+a[6])
        q=a[2]+a[8];
    else
        q=a[4]+a[6];
/*  */
    t++;
    s[t][0]=q*p;
    if(p>q)
    {
        s[t][1]=q;
        s[t][2]=p;
    }
    else
    {
        s[t][1]=p;
        s[t][2]=q;
    }
}
void dfs(long o)
{
    long i,j,k;
    if(o==4)
    {
        count();
        return;
    }
    for(i=1;i<=4;i++)
        if(v[i]==0)
        {   
            v[i]=1;
            a[2*o+1]=x[i];
            a[2*o+2]=y[i];
            dfs(o+1);
            a[2*o+1]=y[i];
            a[2*o+2]=x[i];
            dfs(o+1);
            v[i]=0;
        }
    return;
}
int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    long i,j,k,q;
    for(i=1;i<=4;i++)
        scanf("%d%d",&x[i],&y[i]);
    dfs(0);
    qsort(1,t);
    i=1;
    printf("%d\n",s[1][0]);
    while(s[i][0]==s[1][0])
    {
        if(s[i][1]==s[i-1][1])
        {
            i++;
            continue;
        }
        printf("%d %d\n",s[i][1],s[i][2]);
        i++;
    }
    return 0;
}
