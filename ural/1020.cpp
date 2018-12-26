#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
double a(double x){
    if(x>=0)
      return x*1.0;
    if(x<0)
      return -1.0*x;
    }
int main(){
    long n,i,j,k;
    double x1,y1,x2,y2,x,y,r,sum=0;
    scanf("%d%lf",&n,&r);
    scanf("%lf%lf",&x,&y);
    x1=x;y1=y;
    sum+=r*2*3.1415926;
    for(i=1;i<=n;i++){
      if(i==n){
        x2=x;
        y2=y;
        }
      else
        scanf("%lf%lf",&x2,&y2);
      sum+=sqrt(a(x2-x1)*a(x2-x1)*1.0+a(y1-y2)*a(y1-y2)*1.0);
      x1=x2;
      y1=y2;
      }
    printf("%0.2lf\n",sum);
    system("pause");
    return 0;
    }
