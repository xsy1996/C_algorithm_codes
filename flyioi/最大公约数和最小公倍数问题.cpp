#include<stdio.h>
#include<stdlib.h>
int main()
{
    long i,j,k,n,sum=0,x,y;    
    scanf("%d%d",&x,&y);
    if(y%x!=0)
        printf("0\n");
    else
    {
        n=y/x;
        for(i=2;i<=n;i++)
        {
            k=0;
            while(n%i==0)
            {    
                k=1;
                n/=i;
            }    
            sum+=k;
        }
        k=1;
        for(i=1;i<=sum;i++)
            k*=2;    
        printf("%d\n",k);
    }
    system("pause");
    return 0;    
}