/*
ID:xsy19962
TASK:lamps
LANG:C++
*/
#include<stdio.h>
long a[5][11],c,n,s1[11];
long s[8][6]={
            {1,1,1,1,1,1},
            {0,0,0,0,0,0},
            {0,1,0,1,0,1},
            {1,0,1,0,1,0},
            {0,1,1,0,1,1},
            {1,0,0,1,0,0},
            {0,0,1,1,1,0},
            {1,1,0,0,0,1}
            };
int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    long i,j,k,flag=0;
    scanf("%d%d",&n,&c);
    scanf("%d",&k);
    if(c>3)
        c=3;
    while(k!=-1)
    {
        s1[(k-1)%6]=2;
        scanf("%d",&k);
    }
    scanf("%d",&k);
    while(k!=-1)
    {
        s1[(k-1)%6]=1;
        scanf("%d",&k);
    }
    a[0][0]=1;
    a[1][0]=4;a[1][1]=1;a[1][2]=2;a[1][3]=4;a[1][4]=3;
    a[2][0]=7;a[2][1]=1;a[2][2]=6;a[2][3]=2;a[2][4]=5;a[2][5]=3;a[2][6]=7;a[2][7]=0;
    a[3][0]=8;a[3][1]=1;a[3][2]=6;a[3][3]=2;a[3][4]=4;a[3][5]=5;a[3][6]=3;a[3][7]=7;a[3][8]=0;
    for(i=1;i<=a[c][0];i++)
    {
        k=0;
        for(j=0;j<=5;j++)
            if(s1[j]!=0 && s1[j]!=s[a[c][i]][j]+1)
                k=1;
        if(k==0)
        {
            flag=1;
            for(j=1;j<=n;j++)
                printf("%d",s[a[c][i]][(j-1)%6]);
            printf("\n");
        }
    }
              //  printf("%d\n",c);
    if(flag==0)
        printf("IMPOSSIBLE\n");
    return 0;
}
