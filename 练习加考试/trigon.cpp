#include<stdio.h>
long map[501][501],f[501][501];
int main()
{
    freopen("trigon.in","r",stdin);
    freopen("trigon.out","w",stdout);
    long i,j,k,n,flag,max=0,q,w;
    char a;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++,getchar())
        for(j=1;j<=2*n-i;j++)
        {
            scanf("%c",&a);
            if(a=='-')
                map[i][j]=1;
            else
                map[i][j]=0;
        }
   /* for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=2*n-i;j++)
            printf("%d",map[i][j]);*/
    for(i=1;i<=n;i++)
        for(j=i;j<=2*n-i;j++)
            if(map[i][j]==1)
            {
                f[i][j]=f[i-1][j-1];
                if(f[i][j]>f[i-1][j])
                    f[i][j]=f[i-1][j];
                if(f[i][j]>f[i-1][j+1])
                    f[i][j]=f[i-1][j+1];
                f[i][j]+=1;  
                if(f[i][j]>max && (i+j)%2==0)
                {
                    max=f[i][j];
                    /*printf("%d %d %d\n",max,i,j);
                    for(q=i;q<=i+f[i][j]-1;q++,printf("\n"))
                        for(w=j-f[q][j]+1;w<=j+f[q][j]-1;w++)
                            printf("%d",map[q][w]);
                    printf("\n");*/
                }
            }
        else
            f[i][j]=0;
    for(i=n;i>=1;i--)
        for(j=i;j<=2*n-i;j++)
            if(map[i][j]==1)
            {
                f[i][j]=f[i+1][j-1];
                if(f[i][j]>f[i+1][j])
                    f[i][j]=f[i+1][j];
                if(f[i][j]>f[i+1][j+1])
                    f[i][j]=f[i+1][j+1];
                f[i][j]+=1;  
                if(f[i][j]>max && (i+j)%2==1)
                {
                    max=f[i][j];
                    /*printf("%d %d %d\n",max,i,j);
                    for(q=i;q<=i+f[i][j]-1;q++,printf("\n"))
                        for(w=j-f[q][j]+1;w<=j+f[q][j]-1;w++)
                            printf("%d",map[q][w]);
                    printf("\n");*/
                }
            }
        else
            f[i][j]=0;
   
 /*   for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=2*n-i;j++)
            printf("%d ",f[i][j]);*/
    printf("%d\n",max*max);
    return 0;
}
