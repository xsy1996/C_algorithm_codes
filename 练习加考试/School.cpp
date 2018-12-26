#include<stdio.h>
char date[7][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
long m[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}},y[2]={365,366};
int main()
{
    freopen("School.in","r",stdin);
    freopen("School.out","w",stdout);
    long year,month,day,rest,i,j,k,week;
    char a[20];
    scanf("%d%d%d",&year,&month,&day);
    getchar();
    scanf("%s",a);
    scanf("%d",&rest);
    for(j=1;j<=7;j++)
    {
        k=0;
        for(i=0;i<=5;i++)
            if(date[j][i]!=a[i])
                k=1;
        if(k==0)
            week=j;
    }
    rest+=day;
    week+=280-day;
    week%=7;
    day=0;
    month--;
    if(year%4!=0 || (year%100==0 && year%400!=0))
        k=0;
    else
        k=1;
    for(;month>0;month--)
    {
        rest+=m[k][month];
        week+=280-m[k][month];
        week%=7;  
    }
    month++;
    while(rest>=y[k])
    {
        year++;
        rest-=y[k];
        week+=y[k];
        week%=7;
        if(year%4!=0 || (year%100==0 && year%400!=0))
            k=0;
        else
            k=1;
    }
    if(rest==0)
    {
        year--;
        month=12;
        day=31;
    }
    else
    {
        while(rest>m[k][month])
        {
            rest-=m[k][month];
            week+=m[k][month];
            week%=7;
            month++;
        }
        day=rest;
        week+=rest;
        week%=7;
    }
    printf("%d %d %d %s\n",year,month,day,date[week]);
    return 0;
}
