/*
ID:xsy19962 
TASK:comehome
LANG:C++
*/
#include<stdio.h>
long n,map[201][201],v[201],dis[201];
int main()
{
    long i,j,k,min;
    char x,y,c;
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%c",&x);
        getchar();
        scanf("%c",&y);
        scanf("%d",&k);
        if(map[x][y]==0 || map[x][y]>k)
        {
            map[x][y]=k;
            map[y][x]=k;
        }
    }
   /* for(i='A';i<='z';i++)
        for(j='A';j<='z';j++)
            if(map[i][j]!=0)
                printf("%c %c %d\n",i,j,map[i][j]);*/
    for(i='A';i<='z';i++)
        dis[i]=100000000;
    dis['Z']=0;
    while(1)
    {
        min=100000000; 
        for(i='A';i<='z';i++)
            if(dis[i]<min && v[i]==0)
            {
                min=dis[i];
                c=i;
            }    
        if(c>='A' && c<'Z')
            break;
        for(i='A';i<='z';i++)
            if(map[c][i]!=0 && map[c][i]+dis[c]<dis[i])
                dis[i]=map[c][i]+dis[c];/**/
        v[c]=1;
    }
    printf("%c %d\n",c,dis[c]);

    return 0; 
}
