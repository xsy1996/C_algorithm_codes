#include<stdio.h>
#include<stdlib.h>
double a,b,c,d;
double f(double x){
     return a*x*x*x+b*x*x+c*x+d;
     }
int main(){
    double i;
    int k,s=0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    i=-100;
    if(f(i)>0)
      k=1;
    if(f(i)<0)
      k=-1;
    while(i<=100){
      if(f(i)*k<=0){
        printf("%0.2f ",i);
        k*=-1;
        }
      i+=0.01;
      }
    system("pause");
    return 0;
    }
