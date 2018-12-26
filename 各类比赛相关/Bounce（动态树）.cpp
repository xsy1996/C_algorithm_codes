#include<stdio.h>
const int MAXn=300000,INF=1000000000;
long dad[MAXn],kid[MAXn][2],s[MAXn],n,m;
bool root[MAXn];
void update(long x)
{
    s[x]=s[kid[x][1]]+s[kid[x][0]]+1;
    return;
}
void rotate(long x)
{
    long y=dad[x];
    bool t=(x==kid[y][1]);
    if((kid[y][t]=kid[x][!t]))
        dad[kid[y][t]]=y;
    dad[x]=dad[y];
    if(root[y])
    {
        root[x]=1;
        root[y]=0;
    }
    else
        kid[dad[y]][(y==kid[dad[y]][1])]=x;
    kid[x][!t]=y;
    dad[y]=x;
    update(y);
    return;
}
void splay(long x)
{
    for(long y;!root[x];rotate(x))
        if(!root[y=dad[x]])
        {
            if((x==kid[y][0])==(y==kid[dad[y]][0]))
                rotate(y);
            else
                rotate(x);
        }
    update(x);
    return;        
}
int main()
{
    freopen("Bounce.in","r",stdin);
    freopen("Bounce.out","w",stdout);
    long i,j,k;
    long o,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&dad[i]);
        dad[i]+=i;
        s[i]=root[i]=1; 
    }
    scanf("%d",&m);
    for(;m--;)
    {
        scanf("%d%d",&o,&a);
        a++;
        if(o==1)
        {
            splay(a);
            while(dad[a]<=n)
            {        
                b=dad[a];
                splay(b);
                if(kid[b][1])
                    root[kid[b][1]]=1;
                kid[b][1]=a;
                root[a]=0;
                update(b);
                splay(a);
            }
            printf("%d\n",s[kid[a][0]]+1);
        }
        else
        {
            scanf("%d",&b);
            splay(a);
            if(kid[a][0])
            {
                root[kid[a][0]]=1;
                dad[kid[a][0]]=dad[a];
                kid[a][0]=0;
            }
            dad[a]=a+b;
            update(a);
        }
    }
    return 0;
}
