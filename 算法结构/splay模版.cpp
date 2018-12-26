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

const int MAXN=110000,INF=1000000007,MOD=1000000007,KIND=26;

int n,m;
struct Node{  
    int key, sz, cnt;  
    Node *ch[2], *pnt;//左右儿子和父亲  
    Node(){}  
    Node(int x, int y, int z){  
    key = x, sz = y, cnt = z;  
    }  
    void rs(){  
    sz = ch[0]->sz + ch[1]->sz + cnt;  
    }  
}nil(0, 0, 0), *NIL = &nil;  

struct Splay{//伸展树结构体类型  
    Node *root;  
    int ncnt;//计算key值不同的结点数，注意已经去重了  
    Node nod[MAXN];  
    void init(){// 首先要初始化  
        root = NIL;  
        ncnt = 0;  
    }  
    void rotate(Node *x, bool d){//旋转操作，d为true表示右旋  
        Node *y = x->pnt;  
        y->ch[!d] = x->ch[d];  
        if (x->ch[d] != NIL)  
            x->ch[d]->pnt = y;  
        x->pnt = y->pnt;  
        if (y->pnt != NIL){  
            if (y == y->pnt->ch[d])  
                y->pnt->ch[d] = x;  
            else  
                y->pnt->ch[!d] = x;  
        }  
        x->ch[d] = y;  
        y->pnt = x;  
        y->rs();  
        x->rs();  
    }  
    void splay(Node *x, Node *target){//将x伸展到target的儿子位置处  
        Node *y;  
        while (x->pnt != target){  
            y = x->pnt;  
            if (x == y->ch[0]){  
                if (y->pnt != target && y == y->pnt->ch[0])  
                    rotate(y, true);  
                    rotate(x, true);  
            }  
            else{  
                if (y->pnt != target && y == y->pnt->ch[1])  
                    rotate(y, false);  
                    rotate(x, false);  
            }  
        }  
        if (target == NIL)  
            root = x;  
    }  
    /************************以上一般不用修改************************/  
    void insert(int key,int pos){//插入一个值  
        if (root == NIL){  
            ncnt = 0;  
            root = &nod[++ncnt];  
            root->ch[0] = root->ch[1] = root->pnt = NIL;  
            root->key = key;  
            root->sz = root->cnt = 1;  
            return;  
        }  
        Node *x = root, *y;  
        while (1){  
            x->sz++;  
            if(pos==0 || (x->ch[0]!=NIL && x->ch[0]->sz>=pos))
            {  
                if (x->ch[0] != NIL) 
                    x = x->ch[0]; 
                else
                {  
                    x->ch[0] = &nod[++ncnt];  
                    y = x->ch[0];  
                    y->key = key;  
                    y->sz = y->cnt = 1;  
                    y->ch[0] = y->ch[1] = NIL;  
                    y->pnt = x;  
                    break;  
                }  
            }  
            else{  
                pos--;
                if(x->ch[0]!=NIL)
                    pos-=x->ch[0]->sz;
                if (x->ch[1] != NIL)  
                    x = x->ch[1];  
                else
                {  
                    x->ch[1] = &nod[++ncnt];  
                    y = x->ch[1];  
                    y->key = key;  
                    y->sz = y->cnt = 1;  
                    y->ch[0] = y->ch[1] = NIL;  
                    y->pnt = x;  
                    break;  
                }  
            }  
        }  
        splay(y, NIL);  
    }  
    Node* search(int key){//查找一个值，返回指针  
        if (root == NIL)  
            return NIL;  
        Node *x = root, *y = NIL;  
        while (1){  
            if (key == x->key){  
                y = x;  
                break;  
            }  
            else if (key > x->key){  
                if (x->ch[1] != NIL)  
                x = x->ch[1];  
                else  
                    break;  
            }  
            else{  
                if (x->ch[0] != NIL)  
                    x = x->ch[0];  
                else  
                    break;  
            }  
        }  
        splay(x, NIL);  
        return y;  
    }  
    Node* searchmin(Node *x){//查找最小值，返回指针  
        Node *y = x->pnt;  
        while (x->ch[0] != NIL){//遍历到最左的儿子就是最小值  
            x = x->ch[0];  
        }  
            splay(x, y);  
            return x;  
    }  
    void del(int key){//删除一个值  
        if (root == NIL)  
            return;  
        Node *x = search(key), *y;  
        if (x == NIL)  
            return;  
        if (x->cnt > 1){  
            x->cnt--;  
            x->rs();  
            return;  
        }  
        else if (x->ch[0] == NIL && x->ch[1] == NIL){  
            init();  
            return;  
        }  
        else if (x->ch[0] == NIL){  
            root = x->ch[1];  
            x->ch[1]->pnt = NIL;  
            return;  
        }  
        else if (x->ch[1] == NIL){  
            root = x->ch[0];  
            x->ch[0]->pnt = NIL;  
            return;  
        }  
        y = searchmin(x->ch[1]);  
        y->pnt = NIL;  
        y->ch[0] = x->ch[0];  
        x->ch[0]->pnt = y;  
        y->rs();  
        root = y;  
    }  
    int rank(int key){//求结点高度  
        Node *x = search(key);  
        if (x == NIL)  
            return 0;  
        return x->ch[0]->sz + 1/* or x->cnt*/;  
    }  
    Node* findk(int kth){//查找第k小的值  
        if (root == NIL || kth > root->sz)  
            return NIL;  
        Node *x = root;  
        while (1){  
            if (x->ch[0]->sz +1 <= kth && kth <= x->ch[0]->sz + x->cnt)  
                break;  
            else if (kth <= x->ch[0]->sz)  
                x = x->ch[0];  
            else{  
                kth -= x->ch[0]->sz + x->cnt;  
                x = x->ch[1];  
            }  
        }  
        splay(x, NIL);  
        return x;  
    }  
    void print(Node *x)
    {
        if(x->ch[0]!=NIL)
            print(x->ch[0]);
        printf(" %d",x->key);
        if(x->ch[1]!=NIL)
            print(x->ch[1]);
    }
}sp;  

struct person
{
    int height,pos;
}a[MAXN];

bool cmp(person x,person y)
{
    return x.height>y.height;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cas=0;
    int ans;
    scanf("%d",&t);
    while(++cas<=t)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].height,&a[i].pos);
        sort(a+1,a+n+1,cmp);
        sp.init();
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i<=a[i].pos)
            {
                ans=-1;
                break;
            }
            sp.insert(a[i].height,min(a[i].pos,i-a[i].pos-1));
        }
        if(ans==-1)
            printf("Case #%d: impossible\n",cas);
        else
        {
            printf("Case #%d:",cas);
            sp.print(sp.root);
            printf("\n");
        }
    }
    return 0;
}