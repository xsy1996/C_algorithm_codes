/*
ID:xsy19962
TASK:clocks
LANG:C++
*/
#include<stdio.h>
long a[10],ans=100,q[101],b[10],v=10000000;
long around[10][10]={{0,0,0,0,0,0,0,0,0,0},
                                  {0,1,1,0,1,1,0,0,0,0},
                                  {0,1,1,1,0,0,0,0,0,0},
                                  {0,0,1,1,0,1,1,0,0,0},
                                  {0,1,0,0,1,0,0,1,0,0},
                                  {0,0,1,0,1,1,1,0,1,0},
                                  {0,0,0,1,0,0,1,0,0,1},
                                  {0,0,0,0,1,1,0,1,1,0},
                                  {0,0,0,0,0,0,0,1,1,1},
                                  {0,0,0,0,0,1,1,0,1,1},
                                 };     

int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    long i,k,j,t1,t2,t3,t4,t5,t6,t7,t8,t9,flag;
    for(i=1;i<=9;i++)
    {
        scanf("%d",&k);
        a[i]=k/3;
    }   
    for(t1=0;t1<=3;t1++)
        for(t2=0;t2<=3;t2++)
            for(t3=0;t3<=3;t3++)   
                for(t4=0;t4<=3;t4++)
                    for(t5=0;t5<=3;t5++)   
                        for(t6=0;t6<=3;t6++)
                            for(t7=0;t7<=3;t7++)
                                for(t8=0;t8<=3;t8++)
                                    for(t9=0;t9<=3;t9++)
                                    {
                                        for(i=1;i<=9;i++)
                                            b[i]=a[i];
                                        for(i=1;i<=t1;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[1][j];
                                        for(i=1;i<=t2;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[2][j];
                                        for(i=1;i<=t3;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[3][j];
                                        for(i=1;i<=t4;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[4][j];
                                        for(i=1;i<=t5;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[5][j];
                                        for(i=1;i<=t6;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[6][j];
                                        for(i=1;i<=t7;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[7][j];
                                        for(i=1;i<=t8;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[8][j];
                                        for(i=1;i<=t9;i++)
                                            for(j=1;j<=9;j++)
                                                b[j]+=around[9][j];
                                        flag=0;
                                        for(i=1;i<=9;i++)
                                            if(b[i]%4!=0)
                                                flag=1;
                                        k=t9+t8*4+t7*16+t6*64+t5*256+t4*1024+t3*4096+t2*16384+t1*65536;
                                        if(flag==0 && ((t1+t2+t3+t4+t5+t6+t7+t8+t9<ans) || (t1+t2+t3+t4+t5+t6+t7+t8+t9==ans && k<v)))
                                        {
                                            ans=t1+t2+t3+t4+t5+t6+t7+t8+t9;
                                            v=k;
                                            q[1]=t1;q[2]=t2;q[3]=t3;q[4]=t4;q[5]=t5;q[6]=t6;q[7]=t7;q[8]=t8;q[9]=t9;
                                        }
                                    }
    i=1;
    while(q[i]==0)
        i++;
    printf("%d",i);
    for(j=1;j<q[i];j++)
        printf(" %d",i);
    i++;
    for(;i<=9;i++)                                
        for(j=1;j<=q[i];j++)
            printf(" %d",i);
    printf("\n");
    return 0;
}
