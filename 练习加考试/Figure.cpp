#include<stdio.h>
long h[10001];
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    long i,j,k,x,y,z,max=0,min=100001;
    while(scanf("%d%d%d",&x,&y,&z)!=EOF)
    {
        for(i=x;i<z;i++)
            if(y>h[i])
                h[i]=y;
        if(z>max)
            max=z;
        if(x<min)
            min=x;
    }
    printf("%d ",min);
    for(i=min+1;i<=max;i++)
    {
        while(h[i]==h[i-1] && i<=max)
            i++;
        if(i<=max)
            printf("%d %d ",h[i-1],i);
    }
    printf("0\n");
}
