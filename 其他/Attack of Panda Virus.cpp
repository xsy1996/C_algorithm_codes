#include<stdio.h>
#include<string.h>
long map[1001][1001],x[1000001],y[1000001],n,m,t,z[1000001],s[1001],fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}},v[1001][1001],time[1000001];
long max(long a,long b)
{
    if(a>b)
        return a;
    else
        return b;
}
void up(long a)
{
    long i,j,k;
    if(a==1)
        return;
    if(time[a/2]>time[a] || (time[a/2]==time[a] && z[a/2]>z[a]))
    {
        k=x[a/2];
        x[a/2]=x[a];
        x[a]=k;
        k=y[a/2];
        y[a/2]=y[a];
        y[a]=k;
        k=z[a];
        z[a]=z[a/2];
        z[a/2]=k;
        k=time[a];
        time[a]=time[a/2];
        time[a/2]=k;
        up(a/2);
    }
    return;
}
void down(long a)
{
    long i,j,k,q;
    k=a;
    if(a*2<=t && (time[k]>time[2*a] || (time[k]==time[2*a] && z[a*2]<z[k])))
        k=a*2;
    if(a*2+1<=t && (time[k]>time[2*a+1] || (time[k]==time[2*a+1] && z[a*2+1]<z[k])))
        k=a*2+1;
    if(k!=a)
    {
        q=x[k];
        x[k]=x[a];
        x[a]=q;
        q=y[k];
        y[k]=y[a];
        y[a]=q;
        q=z[k];
        z[k]=z[a];
        z[a]=q;
        q=time[k];
        time[k]=time[a];
        time[a]=q;
        down(k);
    }
    return;
}
int main()
{
    long i,j,k,x1,y1,q,a,b,c,d;
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(v,0,sizeof(v));
        memset(s,0,sizeof(s));
        t=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]>0)
                {
                    t++;
                    x[t]=i;
                    y[t]=j; 
                    z[t]=map[i][j];
                    time[t]=0;
                    map[i][j]=1;
                    up(t);
                }
                else
                    map[i][j]*=-1;
            }
        while(t>0)
        {
            while(v[x[1]][y[1]]==1)
            {
                x[1]=x[t];
                y[1]=y[t]; 
                z[1]=z[t];
                time[1]=time[t];
                t--;
                down(1);
            }
            v[x[1]][y[1]]=1;
            s[z[1]]++;
            a=x[1];
            b=y[1];
            c=z[1];
            d=time[1];
            x[1]=x[t];
            y[1]=y[t]; 
            z[1]=z[t];
            time[1]=time[t];
            t--;
            down(1);
            for(i=0;i<=3;i++)
            {
                x1=a+fx[i][0];
                y1=b+fx[i][1];
                if(x1<1 || x1>n || y1<1 || y1>m || v[x1][y1]==1)
                    continue;
                t++;
                x[t]=x1;
                y[t]=y1; 
                z[t]=c;
                time[t]=max(map[x1][y1],d);
                up(t);
            } 
        }
        scanf("%d",&q);  
        for(i=1;i<=q;i++)
        {
            scanf("%d",&k);
            printf("%d\n",s[k]);
        }
    }
    return 0;
}
