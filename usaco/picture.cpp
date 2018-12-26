/*
ID:xsy19962
TASK:picture
LANG:C++ 
*/
#include<stdio.h>
long a[10001][4],b[10001][4],x[10001],y[10001],xx[20100],yy[20100],maxx,maxy,ans=0;
long v[30001];
void qsorta(long l,long r)
{
    long i,j,k,q,w;
    i=l;j=r;
    q=a[(i+j)/2][3];
    w=a[(i+j)/2][0];
    while(i<=j)
    {
        while(a[i][3]<q || (a[i][3]==q && a[i][0]>w))i++;
        while(a[j][3]>q || (a[j][3]==q && a[j][0]<w))j--;
        if(i<=j)
        {
            k=a[i][0];
            a[i][0]=a[j][0];
            a[j][0]=k;
            k=a[i][1];
            a[i][1]=a[j][1];
            a[j][1]=k;
            k=a[i][2];
            a[i][2]=a[j][2];
            a[j][2]=k;
            k=a[i][3];
            a[i][3]=a[j][3];
            a[j][3]=k;
            i++;j--;    
        }
    }
    if(i<r)qsorta(i,r);
    if(l<j)qsorta(l,j);
    return;
}
void qsortb(long l,long r)
{
    long i,j,k,q,w;
    i=l;j=r;
    q=b[(i+j)/2][3];
    w=b[(i+j)/2][0];
    while(i<=j)
    {
        while(b[i][3]<q || (b[i][3]==q && b[i][0]>w))i++;
        while(b[j][3]>q || (b[j][3]==q && b[j][0]<w))j--;
        if(i<=j)
        {
            k=b[i][0];
            b[i][0]=b[j][0];
            b[j][0]=k;
            k=b[i][1];
            b[i][1]=b[j][1];
            b[j][1]=k;
            k=b[i][2];
            b[i][2]=b[j][2];
            b[j][2]=k;
            k=b[i][3];
            b[i][3]=b[j][3];
            b[j][3]=k;
            i++;j--;    
        }
    }
    if(i<r)qsortb(i,r);
    if(l<j)qsortb(l,j);
    return;
}

int main()
{
    freopen("picture.in","r",stdin);
    freopen("picture.out","w",stdout);
    long i,j,k,x1,y1,x2,y2,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[2*i-1][0]=1;
        a[2*i-1][1]=x1+10001;
        a[2*i-1][2]=x2+10001;
        a[2*i-1][3]=y1+10001;
        a[2*i][0]=-1;
        a[2*i][1]=x1+10001;
        a[2*i][2]=x2+10001;
        a[2*i][3]=y2+10001;
        xx[x1+10001]=1;
        xx[x2+10001]=1;
        b[2*i-1][0]=1;
        b[2*i-1][1]=y1+10001;
        b[2*i-1][2]=y2+10001;
        b[2*i-1][3]=x1+10001;
        b[2*i][0]=-1;
        b[2*i][1]=y1+10001;
        b[2*i][2]=y2+10001;
        b[2*i][3]=x2+10001;
        yy[y1+10001]=1;
        yy[y2+10001]=1;
    }
    k=0;
    for(i=1;i<=20001;i++)
        if(xx[i]==1)
        {
            k++;
            x[k]=i;
            xx[i]=k;
        }
    maxx=k;
    k=0;
    for(i=1;i<=20001;i++)
        if(yy[i]==1)
        {
            k++;
            y[k]=i;
            yy[i]=k;
        }
    maxy=k;
    for(i=1;i<=2*n;i++)
    {
        a[i][1]=xx[a[i][1]];
        a[i][2]=xx[a[i][2]];
        a[i][3]=yy[a[i][3]];
        b[i][1]=yy[b[i][1]];
        b[i][2]=yy[b[i][2]];
        b[i][3]=xx[b[i][3]];
    }
    qsorta(1,n*2);
    qsortb(1,2*n);
   /* for(i=1;i<=2*n;i++)
        printf("%d %d %d %d\n",b[i][0],b[i][1],b[i][2],b[i][3]);*/
    for(i=1;i<=2*n;i++)
        for(j=a[i][1];j<a[i][2];j++)
        {
            if(v[j]==0)
                ans+=x[j+1]-x[j];
            v[j]+=a[i][0];
            if(v[j]==0)
                ans+=x[j+1]-x[j];
        }
    for(i=1;i<=2*n;i++)
        for(j=b[i][1];j<b[i][2];j++)
        {
            if(v[j]==0)
                ans+=y[j+1]-y[j];
            v[j]+=b[i][0];
            if(v[j]==0)
                ans+=y[j+1]-y[j];
        }
    printf("%d\n",ans);
    return 0;
}
