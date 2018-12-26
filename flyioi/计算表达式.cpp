#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
char ss[200],sr[200],fh[101];
int ans[101];
int main(){
    int len,alen,i,j,top=0,k,n,a=0,b=0;
    gets(sr);
    alen=strlen(sr);
    k=0;
    for(i=0;i<alen;i++)
      switch(sr[i]){
        case '(':k++;fh[k]=sr[i];break;
        case ')':while(fh[k]!='('){
                   ss[top]=fh[k];
                   k--;
                   top++;
                   ss[top]=' ';
                   top++;
                   }
                 k--;
                 break;
        case '+':
        case '-':while(k!=0 && fh[k]!='('){
                   ss[top]=fh[k];
                   k--;
                   top++;
                   ss[top]=' ';
                   top++;  
                   }
                 k++;
                 fh[k]=sr[i];
                 break;
        case '*':
        case '/':while(fh[k]!='+' && fh[k]!='-' && k!=0 && fh[k]!='('){
                   ss[top]=fh[k];
                   k--;
                   top++;
                   ss[top]=' ';
                   top++;  
                   }
                 k++;
                 fh[k]=sr[i];
                 break;
        default: while(sr[i]>='0' && sr[i]<='9'){
                   ss[top]=sr[i];
                   top++;i++;
                   }
                i--;
                ss[top]=' ';
                top++;
        }
      if(k>0)
        while(k!=0){
          ss[top]=fh[k];
          k--;
          top++;
          ss[top]=' ';
          top++;  
          }  
    ss[top]='\0';

    len=strlen(ss);
    for(i=0;i<len;i++){
      if(ss[i]==' ')
         continue;
      if(ss[i]=='+'){
        ans[a-1]=ans[a-1]+ans[a];
        a=a-1;
        }  
      else if(ss[i]=='*'){
        ans[a-1]=ans[a-1]*ans[a];
        a=a-1;
        }  
      else if(ss[i]=='/'){
        ans[a-1]=ans[a-1]/ans[a];
        a=a-1;
        }  
      else if(ss[i]=='-'){
        ans[a-1]=ans[a-1]-ans[a];
        a=a-1;
        }  
      else{
       b=0;
        while(ss[i]!=' '){
          b=b*10+ss[i]-'0';
          i++;
          }
        a++;
        ans[a]=b;
        }
      }
      printf("%d\n",ans[a]);
    system("pause");
    return 0;
    }
