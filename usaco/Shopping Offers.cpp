/*
ID:xsy19962 
TASK:shopping
LANG:C++
*/
#include<stdio.h>
long n,m,a[101][6][2],q[101][6],kind[101],c[101],max[101],v[1001],ans=100000000,f[10][10][10][10][10],w;

int main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    long i,j,k,s=0,k1,k2,k3,k4,k5;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&kind[i]);
        for(j=1;j<=kind[i];j++)
            scanf("%d%d",&a[i][j][0],&a[i][j][1]);
        scanf("%d",&c[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&j,&max[i],&k);
        v[j]=i;
        n++;
        kind[n]=1;
        a[n][1][0]=j;
        a[n][1][1]=1;
        c[n]=k;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=kind[i];j++)
        {
            if(v[a[i][j][0]]==0)
                c[i]=1000000001;
            q[i][v[a[i][j][0]]]=a[i][j][1];
        }
    f[0][0][0][0][0]=1;
   /* for(i=1;i<=n;i++)
        printf("%d %d %d %d %d\n",q[i][1],q[i][2],q[i][3],q[i][4],q[i][5]);*/
    for(i=1;i<=n;i++)
        for(k1=0;k1<=max[1];k1++)
            for(k2=0;k2<=max[2];k2++)
                for(k3=0;k3<=max[3];k3++)
                    for(k4=0;k4<=max[4];k4++)
                        for(k5=0;k5<=max[5];k5++)
                            if(f[k1][k2][k3][k4][k5]>0
                            && k1+q[i][1]<=max[1] && k2+q[i][2]<=max[2] && k3+q[i][3]<=max[3] && k4+q[i][4]<=max[4] && k5+q[i][5]<=max[5]
                            && (f[k1+q[i][1]][k2+q[i][2]][k3+q[i][3]][k4+q[i][4]][k5+q[i][5]]>f[k1][k2][k3][k4][k5]+c[i]
                            || f[k1+q[i][1]][k2+q[i][2]][k3+q[i][3]][k4+q[i][4]][k5+q[i][5]]==0))
                                f[k1+q[i][1]][k2+q[i][2]][k3+q[i][3]][k4+q[i][4]][k5+q[i][5]]=f[k1][k2][k3][k4][k5]+c[i];
    printf("%d\n",f[max[1]][max[2]][max[3]][max[4]][max[5]]-1);
    return 0;
}
