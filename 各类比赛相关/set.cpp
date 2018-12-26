#include<stdio.h>
long long ans=1,f[20][5001];
long n,max[101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long i,j,k,s,x,y;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
        if(i%2!=0 && i%3!=0)
        {
            s=0;
            for(j=i;j<=n;j*=2)
            {
                s++;
                max[s]=1;
                k=n/j;
                while(k>0)
                {
                    k/=3;
                    max[s]*=2;
                }        
                if(s==1)
                {
                    for(x=0;x<max[s];x++)
                        if((x&(x*2))==0)
                            f[s][x]=1;
                }
                else
                {
                    for(y=0;y<max[s];y++)
                        if((y&(y<<1))==0)
                            for(x=0;x<max[s-1];x++)
                                if(f[s-1][x]>0 && (x&y)==0)
                                {
                                    f[s][y]+=f[s-1][x];
                                    f[s][y]%=1000000001;
                               //     printf("%d %d %d %I64d\n",s,x,y,f[s][y]);
                                }
                }
            }	
            k=0;
            for(j=0;j<=max[s];j++)
                k+=f[s][j];
            ans*=k;
            ans%=1000000001;
            for(x=1;x<=s;x++)
            {
                for(y=0;y<max[x];y++)
                    f[x][y]=0;
                max[x]=0;
            }
        }
	printf("%I64d\n",ans);
	return 0;
}
