/*
ID:xsy19962
PROB:ditch
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long map[1001][1001],c[1001][1001],s[1001],n,m,sum=0,path[1001],t,mark[1001],v=0;
void find(){
    long i,j,k,min=1000000001;
    for(i=1;i<t;i++)
        if(map[path[i]][path[i+1]]-c[path[i]][path[i+1]]<min)
            min=map[path[i]][path[i+1]]-c[path[i]][path[i+1]];
    for(i=1;i<t;i++){
        c[path[i]][path[i+1]]+=min;
        c[path[i+1]][path[i]]-=min;
        }
    sum+=min;
    return;
    }
void dfs(long x){
    long i,j,k,flag=0,min=1000000001;
    if(v==1)
        return;
    if(x==n){
        find();
        return;
        }
    for(i=1;i<=n;i++)
        if(c[x][i]<map[x][i] && (s[i]==s[x]-1 || i==n)){
            flag=1;
            t++;
            path[t]=i;
            dfs(i);
            if(s[i]<min)
                min=s[i];
            t--;
            }
    mark[s[x]]--;
    if(mark[s[x]]<=0 && min+1!=s[x] && s[x]!=0)
        v=1;
    if(flag==1)
        s[x]=min+1;
    else
        s[x]++;
    mark[s[x]]++;
    return;
    }
void sap(){
    while(s[1]<n && v==0){
        t=1;
        path[1]=1;
        dfs(1);
        }
    return;
    }
int main(){
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    long a,b,w,i,j,k;
    scanf("%ld%ld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%ld%ld%ld",&a,&b,&w);
        map[a][b]+=w;
        }
    sap();
    printf("%ld\n",sum);
    //system("pause");
    return 0;
    }
