#include<stdio.h>
#include<stdlib.h>
long map[101][101],n,m,f[101],s[10001][3],sum,v[101][101],dist[101][101],num,flag;
void qsort(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=s[(i+j)/2][0];
    while(i<=j){
        while(s[i][0]<x)i++;
        while(s[j][0]>x)j--;
        if(i<=j){
            k=s[i][0];
            s[i][0]=s[j][0];
            s[j][0]=k;
            k=s[i][1];
            s[i][1]=s[j][1];
            s[j][1]=k;
            k=s[i][2];
            s[i][2]=s[j][2];
            s[j][2]=k;
            i++;
            j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    }
long father(long x){
    if(f[x]==x)
        return x;
    else{
        f[x]=father(f[x]);
        return f[x];
        }
    }
void find(long x,long y,long z){
    long i,j,k;
    if(flag==1)
        return;
    if(y==z){
        flag=1;
        return;
        }
    for(i=1;i<=n;i++)
        if(v[i][y]==1){
            v[i][y]=0;
            if(dist[x][i]==-1){
                if(map[y][i]>dist[y][x]){
                    dist[x][i]=map[y][i];
                    dist[i][x]=map[y][i];
                    }
                else{
                    dist[x][i]=dist[y][x];
                    dist[i][x]=dist[y][x];
                    }
                }
            find(x,i,z);
            v[i][y]=1;
            }
    return;
    }
void kruskal(){
    long i,j,k;
    qsort(1,m);
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=m;i++)
        if(father(s[i][1])!=father(s[i][2])){
            sum+=s[i][0];
            v[s[i][1]][s[i][2]]=1;
            v[s[i][2]][s[i][1]]=1;
            f[father(s[i][1])]=father(s[i][2]);
            num--;
            }
    return;
    }
int main(){
    long i,j,k,q,a,b,c,min;
    scanf("%ld",&q);
    for(;q>=1;q--){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                map[i][j]=0;
                v[i][j]=0;
                dist[i][j]=-1;
                }
        sum=0;
        min=1000000000;
        scanf("%ld%ld",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%ld%ld%ld",&a,&b,&c);
            map[a][b]=c;
            map[b][a]=c;
            s[i][0]=c;
            s[i][1]=a;
            s[i][2]=b;
            }
        num=n;
        kruskal();
        if(num>1){
            sum=0;
            for(i=1;i<=m;i++)
                sum+=s[i][0];
            printf("%ld\n",sum);
            }
       else{
             for(i=1;i<=m;i++)
                if(v[s[i][1]][s[i][2]]==0 && s[i][0]-dist[s[i][1]][s[i][2]]<min){
                    if(dist[s[i][1]][s[i][2]]==-1){
                        flag=0;
                        find(s[i][1],s[i][1],s[i][2]);
                        }    
                    min=s[i][0]-dist[s[i][1]][s[i][2]];    
                    }
            if(min==0)
                printf("Not Unique!\n");
            if(min>0)
                printf("%ld\n",sum);
            }
        }
    
    system("pause");
    return 0;
    }
    
    
    
    
    
/*
Given a connected undirected graph, tell if its minimum spanning tree is unique. 

Definition 1 (Spanning Tree): Consider a connected, undirected graph G = (V, E). A spanning tree 
of G is a subgraph of G, say T = (V', E'), with the following properties: 
1. V' = V. 
2. T is connected and acyclic. 

Definition 2 (Minimum Spanning Tree): Consider an edge-weighted, connected, undirected graph G =
 (V, E). The minimum spanning tree T = (V, E') of G is the spanning tree that has the smallest 
 total cost. The total cost of T means the sum of the weights on all the edges in E'. 

Input

The first line contains a single integer t (1 <= t <= 20), the number of test cases. Each case 
represents a graph. It begins with a line containing two integers n and m (1 <= n <= 100), the
 number of nodes and edges. Each of the following m lines contains a triple (xi, yi, wi), 
 indicating that xi and yi are connected by an edge with weight = wi. For any two nodes, there 
 is at most one edge connecting them.
Output

For each input, if the MST is unique, print the total cost of it, or otherwise print the string 
'Not Unique!'.
*/
