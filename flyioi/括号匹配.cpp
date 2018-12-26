#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char x[101];
char y[101];
int main(){
    int a,b=0,c=0,i,j,k,n,flag;
    scanf("%s",&x);
    n=strlen(x);
    a=0;
    flag=4;
    for(i=0;i<n;i++){
      if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
        y[a]=x[i];
        a++;
        }
      if(x[i]=='}'){  
         if(a==0){
          flag=2;
          break;
          }
        if(y[a-1]!='{'){
          flag=1;
          break;
          }
        else{
          a--;
                   
          }           
        }
      if(x[i]==')'){  
         if(a==0){
          flag=2;
          break;
          }
        if(y[a-1]!='('){
          flag=1;
          break;
          }
        else{
          a--;
          
          }           
        }
      if(x[i]==']'){  
         if(a==0){
          flag=2;
          break;
          }
        if(y[a-1]!='['){
          flag=1;
          break;
          }
        else{
          a--;
          y[a]=0;
          }           
        }
      }
    if(flag==4 && a!=0)
        flag=3;
    printf("%d\n",flag);   
     
    system("pause");
    return 0;
    }
