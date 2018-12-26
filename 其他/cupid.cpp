#include<stdio.h>
#include<string.h>
long cost[101][101],n,dis,x[101],y[101],v[101],p[101],s[101],map[101][101],ans=0,min;
char name[101][101],c1[101],c2[101],w[10]="End";
long comp(char a[],char b[])
{
    long i,j,k,lena,lenb;
    lena=strlen(a);
    lenb=strlen(b);
    if(lena!=lenb)
        return 0;
    for(i=0;i<lena;i++)
        if(a[i]-b[i]!=0 && a[i]-b[i]!=32 && a[i]-b[i]!=-32)
            return 0;
    return 1;
}
long match(long a)
{
    long i,j,k;
    v[a]=1;
    for(i=n;i<=2*n;i++)
        if(cost[a][i]==s[a]+s[i] && v[i]==0)
        {
            v[i]=1;   
            if(p[i]==0 || match(p[i]))
            {
                p[i]=a;
                return 1;
            }
        }
    return 0;
}
int main()
{
    freopen("cupid.in","r",stdin);
    freopen("cupid.out","w",stdout);
    long i,j,k,q1,q2,flag;
    char c;
    scanf("%d%d",&dis,&n);
    for(i=1;i<=2*n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        getchar();
        scanf("%s",name[i]);
    }
    getchar();
    scanf("%s",c1);
    while(!comp(c1,w))
    {
        getchar();
        scanf("%s",c2);
        scanf("%d",&k);
    //    printf("%s %s %d\n",c1,c2,k);
        for(i=1;i<=2*n;i++)
            if(comp(name[i],c1))
                q1=i;
        for(i=1;i<=2*n;i++)
            if(comp(name[i],c2))
                q2=i;
//      printf("%d  %d\n",q1,q2);
        map[q1][q2]=k;
        map[q2][q1]=k;                
        getchar();
        scanf("%s",c1);
    }
    for(i=1;i<=n;i++)
        for(j=n+1;j<=2*n;j++)
            cost[i][j]=-2147483600;
    for(i=1;i<=n;i++)
        for(j=n+1;j<=2*n;j++)
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=dis*dis)
            {
                flag=1;
                for(k=1;k<=2*n;k++)
                    if(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[i]*y[k]-x[j]*y[i]-x[k]*y[j]==0 && ((x[i]==x[j] && ((y[i]<y[k] && y[k]<y[j]) || (y[i]>y[k] && y[k]>y[j]))) || (x[i]<x[k] && x[k]<x[j]) || (x[i]>x[k] && x[k]>x[j])))
                        flag=0;
                if(flag==1)
                {
                    if(map[i][j]>0)
                        cost[i][j]=map[i][j];
                    else
                        cost[i][j]=1;
                }
            }
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=n+1;j<=2*n;j++)
            printf("%d ",cost[i][j]);*/
    for(i=1;i<=n;i++)
        for(j=n+1;j<=2*n;j++)
            if(cost[i][j]>s[i])
                s[i]=cost[i][j];              
    for(i=1;i<=n;i++)
        while(match(i)==0)
        {
            min=2147483600;
            for(j=1;j<=n;j++)
                if(v[j]==1)
                    for(k=n+1;k<=2*n;k++)
                        if(v[k]==0 && cost[j][k]>0 && s[j]+s[k]-cost[j][k]<min)
                            min=s[j]+s[k]-cost[j][k];
            for(j=1;j<=n;j++)
                if(v[j]==1)
                    s[j]-=min;
            for(j=n+1;j<=2*n;j++)
                if(v[j]==1)
                    s[j]+=min;
            for(j=1;j<=2*n;j++)
                v[j]=0;
        }
   /* for(i=n+1;i<=n*2;i++)
        printf("%d %d %d\n",i,p[i],cost[p[i]][i]);*/
    for(i=1;i<=2*n;i++)
        ans+=s[i];
    printf("%d\n",ans);
    return 0;
}
