#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    long flag;
    struct node *letter[26];
};

struct node *head,*t,*p;
long fx[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char map[1052][1052];
char s[1051][1051];
long i,j,k,len,n,x1,y1,x,y,q,ans[1051][3];
int main(){
    scanf("%d%d%d",&x,&y,&n);
    for(i=1;i<=x;i++)
    {
        getchar();
        for(j=1;j<=y;j++)
            scanf("%c",&map[i][j]);
    }
    head=(struct node*)malloc(sizeof(struct node));
    for(i=0;i<=25;i++)
        head->letter[i]=NULL;
    head->flag=0;
    for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%s",s[i]);
        len=strlen(s[i]);
        p=head;
        for(j=0;j<len;j++)
        {   
            if(p->letter[s[i][j]-'A']==NULL)
            {
                t=(struct node*)malloc(sizeof(struct node));
                for(q=0;q<=25;q++)
                    t->letter[q]=NULL;
                t->flag=0;
                p->letter[s[i][j]-'A']=t;     
            }    
            p=p->letter[s[i][j]-'A'];
            if(j==len-1)
                p->flag=i;
        }
    }
    for(i=1;i<=x;i++)   
        for(j=1;j<=y;j++)
        {
            if(head->letter[map[i][j]-'A']==NULL)
                continue;
            for(k=0;k<8;k++)
            {
                x1=i;
                y1=j;
                p=head;
                while(x1<=x && x1>=1 && y1<=y && y1>=1 && p->letter[map[x1][y1]-'A']!=NULL)
                {
                    if(p->letter[map[x1][y1]-'A']->flag!=0)
                    {
                        ans[p->letter[map[x1][y1]-'A']->flag][0]=i;
                        ans[p->letter[map[x1][y1]-'A']->flag][1]=j;
                        ans[p->letter[map[x1][y1]-'A']->flag][2]=k;
                        p->letter[map[x1][y1]-'A']->flag=0;
                    }
                    p=p->letter[map[x1][y1]-'A'];
                    x1+=fx[k][0];
                    y1+=fx[k][1];
                }  
            }
        }
    for(i=1;i<=n;i++)
        printf("%ld %ld %c\n",ans[i][0]-1,ans[i][1]-1,ans[i][2]+'A');
    system("pause");
    return 0;
}

