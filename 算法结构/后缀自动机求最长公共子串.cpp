#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define Abs(a) (((a)>0)?(a):(-1*(a)))
#define lowbit(x) ((x)&((x)^((x)-1)))

using namespace std;

const int MAXN=251000,INF=1000000007,MOD=1000007,KIND=26;
 
struct State  
{  
    State *pre,*go[KIND];  
    int step;  
    void clear()  
    {  
        pre=0;  
        step=0;  
        memset(go,0,sizeof(go));  
    }  
}*root,*last;  
  
State statePool[MAXN*2],*cur; 
int ans; 
  
void init()  
{  
    cur=statePool;  
    root=last=cur++;  
    root->clear();  
}  
  
void Insert(int w)  
{  
    State *p=last;  
    State *np=cur++;  
    np->clear();  
    np->step=p->step+1;  
    while(p&&!p->go[w])  
        p->go[w]=np,p=p->pre;  
    if(p==0)  
        np->pre=root;  
    else  
    {  
        State *q=p->go[w];  
        if(p->step+1==q->step)  
            np->pre=q;  
        else  
        {  
            State *nq=cur++;  
            nq->clear();  
            memcpy(nq->go,q->go,sizeof(q->go));  
            nq->step=p->step+1;  
            nq->pre=q->pre;  
            q->pre=nq;  
            np->pre=nq;  
            while(p&&p->go[w]==q)  
                p->go[w]=nq, p=p->pre;  
        }  
    }  
    last=np;  
}  

void SAM(char *str,int n)
{
    State *p=root;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int k=str[i]-'a';
       // cout<<str[i]<<"  ";
        if(p->go[k])
        {
            p=p->go[k];
            len++;
        }
        else
        {
            if(len>ans)
                ans=len;
            while(p && !(p->go[k]))
                p=p->pre;
            if(!p)
            {
                p=root;
                len=0;
            }
            else
            {
                len=p->step+1;
                p=p->go[k];
            }
        }
       // cout<<len<<endl;
    }
    if(len>ans)
        ans=len;
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,lena,lenb;
    char A[MAXN],B[MAXN];
    scanf("%s %s",A,B);
    lena=strlen(A);
    lenb=strlen(B);
    init();
    for(int i=0;i<lena;i++)
        Insert(A[i]-'a');
    ans=0;
    SAM(B,lenb);
    printf("%d\n",ans);
    return 0;
}