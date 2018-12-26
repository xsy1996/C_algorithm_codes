#include<stdio.h>
long ans,q[200001],step[200001],v[200001],f,l,x,y;
int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    long i,j,k;
    scanf("%d%d",&x,&y);
    q[1]=x;
    step[1]=1;
    v[x]=1;
    f=0;
    l=1;
    if(x==y)
    {
        printf("0\n");
        return 0;
    }
    while(f<l)
    {
        f++;
        if(q[f]*2==y || q[f]-1==y || q[f]+1==y)
        {
            ans=step[f];
            break;
        }
        if(q[f]<y && v[q[f]*2]==0)
        {
            l++;
            q[l]=q[f]*2;
            v[q[l]]=1;
            step[l]=step[f]+1;
        }
        if(q[f]>1 && v[q[f]-1]==0)
        {
            l++;
            q[l]=q[f]-1;
            v[q[l]]=1;
            step[l]=step[f]+1;  
        }
        if(q[f]<y && v[q[f]+1]==0)
        {
            l++;
            q[l]=q[f]+1;
            v[q[l]]=1;
            step[l]=step[f]+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
