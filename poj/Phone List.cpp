#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long s[100001][11],len;
char a[11];
int main(){
    long i,j,n,q,flag,t=100001;
    long k;
    scanf("%ld",&q);
    for(;q>=1;q--){
        for(i=0;i<=t;i++)
            for(j=0;j<=10;j++)
                s[i][j]=0;
        t=9;
        flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            getchar();
            scanf("%s",a);
            len=strlen(a);
            k=a[0]-'0';
            for(j=1;j<len;j++){
                if(s[k][10]==1 || (j==len-1 && s[k][a[j]-'0']!=0)){
                    flag=1;
                    break;
                    }
                if(s[k][a[j]-'0']==0){
                    t++;
                    s[k][a[j]-'0']=t;
                    }
                k=s[k][a[j]-'0'];
                }
            s[k][10]=1;
            }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
        }
    system("pause");
    return 0;
    }
/*
Description

Given a list of phone numbers, determine if it is consistent in the sense that no number is the 
prefix of another. Let's say the phone catalogue listed these numbers:

Emergency 911
Alice 97 625 999
Bob 91 12 54 26
In this case, it's not possible to call Bob, because the central would direct your call to the 
emergency line as soon as you had dialled the first three digits of Bob's phone number. So this
 list would not be consistent.

Input

The first line of input gives a single integer, 1 ¡Ü t ¡Ü 40, the number of test cases. Each test
 case starts with n, the number of phone numbers, on a separate line, 1 ¡Ü n ¡Ü 10000. Then follows
  n lines with one unique phone number on each line. A phone number is a sequence of at most ten 
  digits. 

Output

For each test case, output "YES" if the list is consistent, or "NO" otherwise.

*/
