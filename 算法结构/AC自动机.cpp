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

using namespace std;

const int MAXN=110001,INF=1000000007,MOD=1000007,KIND=26;

class node
{
public:
    int num; 
    int next[KIND];
    int fail; 
    void init()
    {
    	num=0;
    	fail=-1;
        for(int i=0;i<KIND;i++)
            next[i]=-1;
    }
}tnode[MAXN*7];

int q[MAXN*7]; 
int head,tail;
int last[MAXN],size=0;
char sav[10][10];

void insert(int num,char *word,int root)
{
    int index,len;
    int p = root;
    len = strlen(word);
    for(int i=0;i<len;i++)
    {  
        index=word[i]-'a';
        if(tnode[p].next[index]==-1)
        {
            ++size;
            tnode[size].init();
            tnode[p].next[index]=size;
          //  cout<<size<<"  "<<char(index+'a')<<endl;
        }
        p=tnode[p].next[index];
    }
    tnode[p].num=num;
}

void build_ac_automation(int root)
{
    head=0;tail=1;
    q[head]=root;
    int p,temp;
    while(head<tail)
    {
        temp=q[head++];
        for(int i=0;i< KIND ;i ++)
        {
            if(tnode[temp].next[i]!=-1)
            {
                if(temp==root)
                    tnode[tnode[temp].next[i]].fail=root;
                else 
                {
                    p=tnode[temp].fail;
                    while(p!=-1)
                    {
                        if(tnode[p].next[i]!=-1)
                        {
                            tnode[tnode[temp].next[i]].fail=tnode[p].next[i];
                            break;
                        }
                        p=tnode[p].fail;
                    }
                    if(p==-1)
                        tnode[tnode[temp].next[i]].fail=root;
                }
                q[tail++]=tnode[temp].next[i];
            }
        } 
    }                
}

void query(int root,char *str)
{
    int i,index,len=strlen(str);
    int p=root;
    for(i=0;i<len;i++)
    {
        index=str[i]-'a';
       // cout<<"  "<<index<<endl;
        while(tnode[p].next[index]==-1 && p!=root)
            p=tnode[p].fail;
        p=tnode[p].next[index];
        if(p==-1)
            p=root;
        int temp=p;
        while(temp!=root)
        {
        	if(tnode[temp].num!=0)
        		cout<<i<<"  "<<sav[tnode[temp].num]<<endl;
            temp=tnode[temp].fail;   
        }
   }
   return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cas=0,n,m,type;
    char str[100];
    int root=0;  
    while(scanf(" %s",str)!=EOF)
    {    
        ++cas;
        memset(last,-1,sizeof(last));
        size=0;
        tnode[0].init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %s",sav[i]);
             //cout<<keyword<<endl;
            insert(i,sav[i],root);
        }
        build_ac_automation(root);
        query(root,str);
    }

   return 0;
}

