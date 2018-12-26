#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <algorithm>  
#include <queue>  
  
using namespace std;  
class node      //定义树节点结构体
{  
public:  
    node *l,*r;  
    int h,size;  
    int key,dat;  
    node()
    {
        l=r=NULL,h=1,size=0;
    }  
    node(int tkey,int tdat)
    {
        dat=tdat;
        key=tkey;
        l=r=NULL;
        h=1;
        size=1;
    }
    int geth() 
    {  
        if(!this) 
            return 0;  
        else 
            return h;  
    }  
    int getsize() 
    {  
        if(!this) 
            return 0;  
        else 
            return size;  
    }  
    void update() 
    {  
        if(this) 
        {  
            h = max(l->geth() ,r->geth()) + 1;  
            size = l->getsize() + r->getsize() + 1;  
        }  
    }      
};
class AVL     //AVL树结构体
{  
public:  
    node *root; 
    AVL()
    {
        root=NULL;
    };   
    void Lrotate(node *p)    //左旋操作
    {  
        node * t = p->r->l;  
        p->r->l = p;  
        p= p->r;  
        p->l->r =t;  
        p->l->update();  
        p->update();  
    }  
    void Rrotate(node *p)   //右旋操作
    {  
        node * t = p->l->r;  
        p->l->r = p;  
        p= p->l;  
        p->r->l = t;  
        p->r->update();  
        p->update();  
    }  
    void maintain(node *p)   //一旦某节点两边高度差超过一，立刻旋转保持平衡
    {  
        int lh ,rh;  
        if(p->l->geth() > p->r->geth() + 1) 
        {
            lh = p->l->l->geth();  
            rh = p->l->r->geth();  
            if(lh >= rh)  
                Rrotate(p);  
            else 
            {  
                Lrotate(p->l);  
                Rrotate(p);  
            }  
        }  
        if(p->r->geth() > p->l->geth() + 1 ) 
        { 
            lh = p->r->l->geth();  
            rh = p->r->r->geth();  
            if(rh >= lh)  
                Lrotate(p);  
            else 
            {  
                Rrotate(p->r);  
                Lrotate(p);  
            }  
        }  
    }  
    void insert(node *p, int key, int dat)   //插入新节点
    {  
        if(root==NULL) 
        {  
            root = new node(key,dat);  
            return;  
        }  
        if(key <= p->key)
        {  
            if(p->l==NULL)
                p->l=new node(key,dat);
            else
                insert(p->l,key,dat);  
        }
        else  
        {
            if(p->r==NULL)
                p->r=new node(key,dat);
            else
                insert(p->r,key,dat);  
        }
        maintain(p);  
        p->update();  
    }  
    void erase(node *p, int key)    //删除节点
    {  
        if(!p) 
            return;  
        if(p->key == key) 
        {  
            if(p->l && p->r) 
            {  
                node * t = p->r;  
                while(t->l)  
                    t = t->l;  
                p->key = t->key;
                p->dat = t->dat;  
                erase(p->r,t->key);  
                maintain(p);  
            } 
            else if(p->l) 
            {  
                p->key = p->l->key;
                p->dat = p->l->dat;  
                p->l = NULL;  
            } 
            else if(p->r) 
            {  
                p->key = p->r->key;
                p->dat = p->r->dat;  
                p->r = NULL;  
            } 
            else p = NULL;  
            p->update();  
            return;  
        } 
        else if(key < p->key)  
            erase(p->l,key);  
        else  
            erase(p->r,key);  
        maintain(p);  
        p->update();  
    }  
    int findk(node *p, int key)    //查找节点，返回对应dat，若没有，返回－10000
    {  
        if(p==NULL)
            return -10000;
      //  cout<<p->key<<"  "<<p->dat<<endl;
        if(key == (p->key))  
            return p->dat;  
        else if(key < (p->key))
            return findk(p->l,key);  
        else
            return findk(p->r,key);  
        return -10000;
    }  
    void insert(int key,int dat) 
    {  
        insert(root, key, dat);  
    }  
    void erase(int key) 
    {  
        erase(root, key);  
    }  
    int findk(int k) 
    {   
        return findk(root, k);  
    }  
    void clear(node *p) 
    {  
        if(!p)  
            return;  
        clear(p->l);  
        clear(p->r);  
        delete p;  
    }  
    bool empty() 
    {  
        return (root->getsize() == 0);  
    }  
    int size() 
    {  
        return root->getsize();  
    }  
    node* getroot() {  
        return root;  
    }  
};  
   
int main() 
{  
 //   freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int n,key,data;  
    char cmd;  
    AVL tree;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf(" %c",&cmd);
        if(cmd == 'I')
        {
            cin>>key>>data;
            tree.insert(key,data);
        }
        else if(cmd == 'D')
        {
            int key;
            cin>>key;
            tree.erase(key);
        }
        else if(cmd == 'F')
        {
            int key;
            cin>>key;
            int u=tree.findk(key);
            if(u==-10000)
                cout<<key<<" unknown"<<endl;
            else
                cout<<key<<"  "<<u<<endl;
        }
    }
    return 0;  
}  