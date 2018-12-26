#include<stdio.h>
#include<math.h>
long q[1000001],f,l,t[1000001],v[1000001];
int main()
{
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    long i,j,k,a,b,x,y,z;
    scanf("%d%d",&a,&b);
    f=0;l=1;
    q[1]=a;t[1]=1;
    v[a]=0;
    while(f<l)
    {
        f++;
        x=sqrt(q[f]);
        for(i=2;i<=x;i++)
            if(q[f]%i==0)
            {    
                if(q[f]+i<=b && v[q[f]+i]==0)
                {   
                    if(q[f]+i==b)
                    {
                        printf("%d\n",t[f]);
                        return 0;
                    }
                    v[q[f]+i]=1;
                    l++;
                    t[l]=t[f]+1;
                    q[l]=q[f]+i;
                  //  printf("%d %d %d\n",l,q[l],t[l]);
                }
                if(q[f]+q[f]/i<=b && v[q[f]+q[f]/i]==0)
                {   
                    if(q[f]+q[f]/i==b)
                    {
                        printf("%d\n",t[f]);
                        return 0;
                    }
                    v[q[f]+q[f]/i]=1;
                    l++;
                    t[l]=t[f]+1;
                    q[l]=q[f]+q[f]/i;
                   // printf("%d %d %d\n",l,q[l],t[l]);
                }
            }
    }
    printf("-1\n");
    return 0;
}
