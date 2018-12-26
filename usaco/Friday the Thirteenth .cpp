/*
ID:xsy19962
PROG:friday
LANG:C++
*/
#include<stdio.h>
int week[7];
int main(){
    int day,i,j,n,k,year,month;
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    scanf("%d",&n);
    day=6;
    week[6]++;
    for(year=1900;year<=1900+n-1;year++)
      for(month=1;month<=12;month++){
        if(year==1900+n-1 && month==12)
          break;
        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
          day+=31;
        else if(month==4 || month==6 || month==9 || month==11)
          day+=30;
        else if(month==2){
          if((year%4==0 && year%100!=0) || year%400==0)
            day+=29;
          else
            day+=28;
          }
        day%=7;
        week[day]++;
        }
    printf("%d %d %d %d %d %d %d\n",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
    return 0;
    }
