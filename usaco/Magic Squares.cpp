/*
ID:xsy19962
TASK:msquare
LANG:C++
*/
#include<stdio.h>
bool v[100001];
long a[10],b[10],aim,queue[100001],pre[100001],step[100001],f=0,l=1,ans[1001],t=0,roll[10];
long count()
{
    long i,j,k,rand=0;
    for(i=1;i<=8;i++)
    {
        k=0;
        for(j=i+1;j<=8;j++)
            if(b[j]<b[i])
                k++;
        rand+=k*roll[9-i];
    }
   /* for(i=1;i<=8;i++)
        printf("%d",b[i]);
    printf("       %d\n",rand);*/
    return rand;
}
int main()
{
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    long i,j,k;
    roll[1]=0;
    roll[2]=1;
    for(i=3;i<=8;i++)
        roll[i]=roll[i-1]*(i-1);
    for(i=1;i<=8;i++)
    {
        scanf("%d",&k);
        aim=aim*10+k;
        queue[1]=queue[1]*10+i;
    }
    if(queue[1]==aim)
    {
        printf("0\n\n");
        return 0;
    }
    while(f<l)
    {
        f++;
        for(i=8;i>=1;i--)
        {
            a[i]=queue[f]%10;
            queue[f]/=10;
        }
        l++;
        step[l]=0;
        pre[l]=f;
        queue[l]=a[8]*10000000+a[7]*1000000+a[6]*100000+a[5]*10000+a[4]*1000+a[3]*100+a[2]*10+a[1];
        k=queue[l];
        for(i=8;i>=1;i--)
        {
            b[i]=k%10;
            k/=10;
        }
        if(queue[l]==aim)
            break;
        if(v[count()]==1)
            l--;
        else
            v[count()]=1;
        l++;
        step[l]=1;
        pre[l]=f;
        queue[l]=a[4]*10000000+a[1]*1000000+a[2]*100000+a[3]*10000+a[6]*1000+a[7]*100+a[8]*10+a[5];
        if(queue[l]==aim)
            break; 
        k=queue[l];
        for(i=8;i>=1;i--)
        {
            b[i]=k%10;
            k/=10;
        }
        if(v[count()]==1)
            l--;
        else
            v[count()]=1;
        l++;
        step[l]=2;
        pre[l]=f;
        queue[l]=a[1]*10000000+a[7]*1000000+a[2]*100000+a[4]*10000+a[5]*1000+a[3]*100+a[6]*10+a[8];
        if(queue[l]==aim)
            break;
        k=queue[l];
        for(i=8;i>=1;i--)
        {
            b[i]=k%10;
            k/=10;
        }
        if(v[count()]==1)
            l--;
        else
            v[count()]=1;
    }
    while(l!=1)
    {
        t++;
        ans[t]=step[l];
        l=pre[l];
    }
    printf("%d\n",t);
    for(;t>=1;t--)
        printf("%c",'A'+ans[t]);
    printf("\n");
    return 0;    
}
