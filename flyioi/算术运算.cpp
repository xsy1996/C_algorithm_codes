#include<stdio.h>
#include<stdlib.h>
int main(){
    float a,b;
    char t;
    scanf("%f%c%f",&a,&t,&b);
    if(t=='+')
      printf("%0.1f\n",a+b);
    if(t=='-')
      printf("%0.1f\n",a-b);
    if(t=='*')
      printf("%0.1f\n",a*b);
    if(t=='/')
      printf("%0.1f\n",a/b);
    system("pause");
    return 0;
    }
