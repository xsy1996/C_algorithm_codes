#include <cmath>  
#include <vector>  
#include <cstdio>  
#include <climits>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define  pb push_back  
#define  mp make_pair  
#define  sz(x) ((int)(x).size())  
using namespace std;  
  
const int N = 20010;  
const int INF = (int)1e9;  
int fa[N], L[N], n, m, anc[N][33];  

struct Edge {  
    int e, w, next;  
}edge[N * 10];  

int head[N], cnt = 0; 
int s[N],ans[N]; 
  
void addedge(int a, int b){  
    edge[cnt].e = b;  
    edge[cnt].next = head[a];  
    head[a] = cnt++;  
}  
  
struct LCA_online {  
    void initi(){  
        cnt = L[1] = 0;  
        memset(head, -1, sizeof head);  
    }  
  
    void dfs(int u, int f) {  
        fa[u] = f;  
        for(int it = head[u]; ~it; it = edge[it].next) {  
            int v = edge[it].e;  
            if(v != f) {    
                L[v] = L[u] + 1;  
                dfs(v, u);  
            }  
        }  
    }  
  
    void process() {  
        for(int i = 1; i <= n; i++) {  
            anc[i][0] = fa[i];  
            for(int j = 1; (1 << j) < n; j++) anc[i][j] = -1;  
        }  
        for(int j = 1; (1 << j) < n; j++)  
            for(int i = 1; i <= n; i++)  
                if(anc[i][j - 1] != -1) {  
                    int a = anc[i][j - 1];  
                    anc[i][j] = anc[a][j - 1];  
                }  
    }  
      
    int query(int p, int q) {  
        int lo;  
        if(L[p] < L[q]) swap(p, q);  
        for(lo = 1; (1 << lo) <= L[p]; lo++); lo--;  
        for(int i = lo; i >= 0; i--)  
            if(L[p] - (1 << i) >= L[q])   
                p = anc[p][i];  
        if(p == q)  
            return p;         
        for(int i = lo; i >= 0; i--)  
            if(anc[p][i] != -1 && anc[p][i] != anc[q][i]) {  
                p = anc[p][i];  
                q = anc[q][i];  
            }  
        return fa[p];  
    }  
}g;  

void dp(int u,int f)
{
    for(int it = head[u]; ~it; it = edge[it].next) {  
            int v = edge[it].e;  
            if(v != f) {     
                dp(v, u);  
                ans[u]+=ans[v];
            }  
        }  
    ans[u]-=s[u]*2;
    return;
}
  
int main() {  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,cas=0;  
    scanf("%d",&T);  
    while(++cas<=T) {  
        memset(s,0,sizeof(s));
        memset(ans,0,sizeof(ans));
        g.initi();  
        scanf("%d%d",&n,&m);  
        for(int i = 1; i < n; i++) {  
            int a, b;  
            scanf("%d%d", &a, &b);  
            addedge(a, b);  
            addedge(b, a);         
        }  
        g.dfs(1, -1);  
        g.process();   
        for(int i=n;i<=m;i++) 
        {  
            int a, b;  
            scanf("%d%d", &a, &b);  
            int anc = g.query(a, b);  
            s[anc]++;
            ans[b]++;
            ans[a]++;
        }  
        dp(1,-1);
        int min=INF;
        for(int i=2;i<=n;i++)
            if(ans[i]<min)
                min=ans[i];
        printf("Case #%d: %d\n",cas,min+1);
    }  
    return 0;  
}  