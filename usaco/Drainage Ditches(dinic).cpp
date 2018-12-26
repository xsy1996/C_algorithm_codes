/*
ID:xsy19962
PROB:ditch
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
long map[201][201],c[201][201],sum=0,n,m,s[201],flag=0,path[201],t=0,v[201];
void find(){
    long i,j,k,min=10000001;
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
    long i,j,k;
    if(x==n){
        
        find();
        return;
        }
    for(i=2;i<=n;i++)
        if((s[i]==s[x]+1 || i==n) && c[x][i]<map[x][i]){
            t++;
            path[t]=i;
            dfs(i);
            t--;
            }
    return;
    }
void cct(){
    long i,j,k,dl[201],f,l,q=0;
    f=0;l=1;
    for(i=1;i<=n;i++){
        v[i]=0;
        s[i]=-1;
        }
    s[1]=0;
    dl[1]=1;
    v[1]=1;
    while(f<l){
        f++;
        for(i=1;i<=n;i++)
            if(c[dl[f]][i]<map[dl[f]][i] && v[i]==0){
                if(i==n){
                    flag=1;
                    continue;
                    }
                l++;dl[l]=i;
                s[dl[l]]=s[dl[f]]+1;                
                v[i]=1;
                }
        } 
    return;
}
void dinic(){
    long i,j,k; 
    while(1){
        flag=0;
        cct();
        if(flag==0)
            break;
        t=1;
        path[1]=1;
        dfs(1);
    }
    return;
}
int main(){
    long i,j,k,a,b,w;
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%ld%ld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%ld%ld%ld",&a,&b,&w);
        map[a][b]+=w;
    }
    dinic();
    printf("%ld\n",sum);
  //  system("pause");
    return 0;
}
