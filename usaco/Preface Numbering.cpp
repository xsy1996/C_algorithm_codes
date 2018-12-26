/*
ID:xsy19962
TASK:preface
LANG:C++
*/
#include<stdio.h>
long s[10],ge[10][10],shi[10][10],bai[10][10],n;
char c[10]={0,'I','V','X','L','C','D','M'};
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    long i,j,k,x,y,z,q;
    scanf("%d",&n);
    ge[1][1]=1;
    ge[2][1]=2;
    ge[3][1]=3;
    ge[4][1]=1;
    ge[4][2]=1;
    ge[5][2]=1;
    ge[6][1]=1;
    ge[6][2]=1;
    ge[7][1]=2;
    ge[7][2]=1;
    ge[8][1]=3;
    ge[8][2]=1;
    ge[9][1]=1;
    ge[9][3]=1;
    
    shi[1][3]=1;
    shi[2][3]=2;
    shi[3][3]=3;
    shi[4][3]=1;
    shi[4][4]=1;
    shi[5][4]=1;
    shi[6][3]=1;
    shi[6][4]=1;
    shi[7][3]=2;
    shi[7][4]=1;
    shi[8][3]=3;
    shi[8][4]=1;
    shi[9][3]=1;
    shi[9][5]=1;
    
    bai[1][5]=1;
    bai[2][5]=2;
    bai[3][5]=3;
    bai[4][5]=1;
    bai[4][6]=1;
    bai[5][6]=1;
    bai[6][5]=1;
    bai[6][6]=1;
    bai[7][5]=2;
    bai[7][6]=1;
    bai[8][5]=3;
    bai[8][6]=1;
    bai[9][5]=1;
    bai[9][7]=1;
    
    for(i=1;i<=n;i++)
    {
        x=i%10;
        y=i/10%10;
        z=i/100%10;
        q=i/1000;
        for(j=1;j<=7;j++)
            s[j]+=ge[x][j]+shi[y][j]+bai[z][j];
        s[7]+=q;
    }
    for(i=1;i<=7;i++)
        if(s[i]!=0)
            printf("%c %d\n",c[i],s[i]);
    return 0;
}
