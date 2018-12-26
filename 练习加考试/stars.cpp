#include<stdio.h>
#include<string.h>
bool s[1001],t[1001],a[1001],r[1001];
char star[1001];
int main(){
    FILE *fin=fopen("stars9.in","r");
    FILE *fout=fopen("stars.out","w");
    long long n,i,ss=0,ts=0,as=0,rs=0,st,tt=0,at=0,rt=0;
    long long zs,xs=0,ys=32700;
    fscanf(fin,"%s",star);
    n=strlen(star);
    for(i=0;i<n;i++){
      if(star[i]=='S'){
        s[i]=1;
        ss++;
        }
      if(star[i]=='T'){
        t[i]=1;
        ts++;
        }
      if(star[i]=='A'){
        a[i]=1;
        as++;
        }
      if(star[i]=='R'){
        r[i]=1;
        rs++;
        }
      }
    if(ys>ss)
      ys=ss;
    if(ys>as)
      ys=as;
    if(ys>ts)
      ys=ts;
    if(ys>rs)
      ys=rs;
    zs=ss*ts*as*rs;
    for(st=0;st<n;st++)
      if(s[st]){
        if(st+1>tt)
          tt=st+1;
        while(!t[tt] && tt<n)
          tt++;
        if(tt+1>at)
          at=tt+1;
        while(!a[at] && at<n)
          at++;
        if(at+1>rt)
          rt=at+1;
        while(!r[rt] && rt<n)
          rt++;
        if(t[tt] && a[at] && r[rt]){
          xs++;
          tt++;
          at++;
          rt++;
          }
        else
          break;
        }
    fprintf(fout,"%I64d %I64d %I64d\n",zs,ys,xs);
    fclose(fin);
    fclose(fout);
    return 0;
    }
