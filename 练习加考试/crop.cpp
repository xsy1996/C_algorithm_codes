#include<stdio.h>
long long s[10];
int main()
{
    freopen("crop.in","r",stdin);
    freopen("crop.out","w",stdout);
    long long i,j,k,n,m,a,b,c,d,x,y,sum=0;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d,&x,&y,&m);  
	for(i=1;i<=n;i++)
    {
        s[(x%3)*3+y%3]++;
		x=(a*x+b)%m;
		y=(c*y+d)%m;
	}
	for(i=0;i<=8;i++)
	   sum+=s[i]*(s[i]-1)*(s[i]-2)/6;
	for(i=0;i<=8;i++)
	   for(j=i+1;j<=8;j++)
	       for(k=j+1;k<=8;k++)
	           if((i/3+j/3+k/3)%3==0 && (i%3+j%3+k%3)%3==0)
	               sum+=s[i]*s[j]*s[k];
    printf("%I64d\n",sum);
    return 0;
}
