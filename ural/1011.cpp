#include<stdio.h>
#include<stdlib.h>
int main(){
    double q,p;
    long i,j,k,x,y;
    scanf("%lf%lf",&p,&q);
    i=0;
    while(1)
    {
      i++;
      x=(long)(i*1.0*p*100)/10000+1;
      y=(long)(i*1.0*q*100)/10000;
      if((long)(i*1.0*q*100)%10000!=0)y++;
      if(x<y)
      {
        printf("%ld\n",i);
        break;
      }
    }
    system("pause");
    return 0;
}

