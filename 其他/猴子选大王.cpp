#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int i,j,k,m,n;
    struct node *head,*p,*q;
    scanf("%d%d",&n,&m);
    
    p=(struct node*)malloc(sizeof(struct node));
    p->data=1;p->next=p;
    head=p;
    
    for(i=2;i<=n;i++)
    {
        q=(struct node*)malloc(sizeof(struct node));
        q->data=i;q->next=head;
        p->next=q;
        p=q;
    }
    
    k=1;p=head;
    while(p->next!=p){
        if(k+1==m){
            p->next=p->next->next;
            k=1;
            p=p->next;
        }else{
            k++;
            p=p->next;
        }    
    }
    printf("%d\n",p->data);
    system("pause");
    return 0;
}
