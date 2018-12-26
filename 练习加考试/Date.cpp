#include<stdio.h>
long y,m,d,rest;
long month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    freopen("Date.in","r",stdin);
    freopen("Date.out","w",stdout);
    long i,j,k;
    scanf("%d",&rest);
    scanf("%d%d%d",&y,&m,&d);
    rest+=d-1;
    d=1;
    m--;
    for(;m>=1;m--)
    {
        if((y%4==0 && y%100!=0) || y%400==0)
            rest+=month2[m];
        else
            rest+=month1[m];
    }
    while(1)
    {
        if((y%4==0 && y%100!=0) || y%400==0)
            if(rest>=366)
            {
                rest-=366;
                y++;
            }
            else
                break;
        else
            if(rest>=365)
            {
                rest-=365;
                y++;
            }
            else
                break;
    }
    for(m=1;m<=12;m++)
        if((y%4==0 && y%100!=0) || y%400==0)
            if(rest>=month2[m])
                rest-=month2[m];
            else
                break;
        else
            if(rest>=month1[m])
                rest-=month1[m];
            else
                break;
    d+=rest;
    printf("%d-%d-%d\n",y,m,d);
    return 0;
}
