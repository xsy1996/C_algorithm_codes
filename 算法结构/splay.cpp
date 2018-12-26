long findroot(long x)
{
    if(root[x])
        return x;
    else
        return findroot(dad[x]);
}
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
        root[y]=0;
        root[x]=1;
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
            if((x==kid[y][1])==(y==kid[dad[y]][1]))
                rotate(y);
            else
                rotate(x);
        }
    update(x);
    return;        
}
