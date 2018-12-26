#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[101],v[27];
int main(){
    long len,max=0,min=200,i,j,k,flag=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
      if(a[i]>='A' && a[i]<='Z')
        v[a[i]-'A'+1]++;
      else if(a[i]>='a' && a[i]<='z')
        v[a[i]-'a'+1]++;
      }
    for(i=1;i<=26;i++){
      if(v[i]>max)
        max=v[i];
      if(v[i]<min && v[i]>0)
        min=v[i];
      }
    if(min==200)
      min=0;
    k=max-min;
    if(k==1 || k==0){
      printf("No Answer\n0\n");
      system("pause");
      return 0;
      }
    for(i=2;i<k;i++)
      if(k%i==0){
        flag=1;
        break;
        }
    if(flag)
      printf("No Answer\n0\n");
    else
      printf("Lucky Word\n%d\n",max-min);
    system("pause");
    return 0;
    }
