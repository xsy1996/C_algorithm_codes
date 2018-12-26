#include<stdio.h>
#include<string.h>
#define lowbit(k) ((k)&((k)^((k)-1)))
long long n,m,t,c[2000001],a1[20001],a2[20001],a3[20001],ans=0,up[20001],down[20001],b,b1,b2,b3,s[20001];
bool map[10005][10005];
void add1(long long k,long long a)
{
    while(k<=m)
    {
        a1[k]+=a;
        k+=lowbit(k);
    }
    return;
}
void add2(long long k,long long a)
{
    while(k<=m)
    {
        a2[k]+=a;
        k+=lowbit(k);
    }
    return;
}
void add3(long long k,long long a)
{
    while(k<=m)
    {
        a3[k]+=a;
        k+=lowbit(k);
    }
    return;
}
long long count1(long long k)
{
    long long sum=0;
    while(k>0)
    {
        sum+=a1[k];
        k-=lowbit(k);
    }
    return sum;
}
long long count2(long long k)
{
    long long sum=0;
    while(k>0)
    {
        sum+=a2[k];
        k-=lowbit(k);
    }
    return sum;
}
long long count3(long long k)
{
    long long sum=0;
    while(k>0)
    {
        sum+=a3[k];
        k-=lowbit(k);
    }
    return sum;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long i,j,k,x,y;
	scanf("%I64d%I64d%I64d",&n,&m,&t);
	for(i=1;i<=t;i++)
    {
		scanf("%I64d%I64d",&x,&y);
		map[x][y]=1;
    }   
    for(j=1;j<=m;j++)
        s[j]=(s[j-1]+j)%1000000009;
    for(i=1;i<=n;i++)
    {
        k=-1;
        for(j=1;j<=m;j++)
        {
            if(map[i][j]==1)
                k=-1;
            else
            {
                k++;
                c[(i-1)*m+j]=k;
            }
        }
    }
    for(i=n;i>=1;i--,k=-1)
        for(j=m;j>=1;j--)
        {
            if(map[i][j]==1)
                k=-1;
            else
            {
                k++;
                if(k<c[(i-1)*m+j])
                    c[(i-1)*m+j]=k;
            }
        }
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=10005;i++)
        {
            a1[i]=0;
            a2[i]=0;
            a3[i]=0;
        }
        b=0;b1=0;b2=0;b3=0;
        //printf("------------------------\n%I64d\n\n",j); 
        for(i=1;i<=n;i++)
            if(map[i][j]!=1)
                up[i]=up[i-1]+1;
            else
                up[i]=0;
        for(i=n;i>=1;i--)
            if(map[i][j]!=1)
                down[i]=down[i+1]+1;
            else
                down[i]=0;    
      /*  for(i=1;i<=n;i++)   
            printf("%I64d %I64d\n",up[i],down[i]); */
        for(i=1;i<=n;i++)
        {
            if(map[i][j]==1 && map[i-1][j]==0)
            {
                memset(a1,0,sizeof(a1));
                memset(a2,0,sizeof(a2));
                memset(a3,0,sizeof(a3));
                b=0;b1=0;b2=0;b3=0;
            }
            if(map[i][j]==1)
            {
                if(b!=0)
                {
                    add1(b,b1);
                    add2(b,b2);
                    add3(m-b+1,b3);
                }
                continue;
            }
            if(down[i]>=1)
            {
                ans+=(down[i]-1)*(c[(i-1)*m+j]*count1(c[(i-1)*m+j]-1)-count2(c[(i-1)*m+j]-1)+s[c[(i-1)*m+j]-1]*(count3(m-c[(i-1)*m+j]+1)))%1000000009;
                ans%=1000000009;
            }
            if(b!=0)
            {
                add1(b,b1);
                add2(b,b2);
                add3(m-b+1,b3);
            }
            b=c[(i-1)*m+j];
            b1=c[(i-1)*m+j]*(up[i]-1)%1000000009;
            b2=s[c[(i-1)*m+j]]*(up[i]-1)%1000000009;
            b3=up[i]-1;
         //   printf("%I64d %I64d  %I64d %I64d %I64d %I64d       %I64d\n",i,j,b,b1,b2,b3,ans);
        }
    }
    printf("%I64d\n",ans);
	return 0;
}
