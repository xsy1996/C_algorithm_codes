/*
ID:xsy19962 
TASK:concom
LANG:C++
*/
#include<stdio.h>
long n,p[101][101],c[101][101],d[10001][2],f=0,l=0,fa[101]; 
int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    long i,j,k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y,&k);
        p[x][y]=k;
        if(k>50 && x!=y)
        {
            l++;
            d[l][0]=x;
            d[l][1]=y;
            c[x][y]=1;
            fa[y]=x;
        }
    }
    while(f<l)
    {
        f++;
        x=d[f][0];
        y=d[f][1];
        for(i=1;i<=100;i++)
        {
            p[x][i]+=p[y][i];
            if(p[x][i]>50 && c[x][i]==0)
            {
                l++;
                d[l][0]=x;
                d[l][1]=i;
                c[x][i]=1;
                fa[i]=x;
            }    
        }
        k=fa[x];
      //  j=0;
        while(k!=0)
        {
            if(c[k][y]==0)
            {
               for(i=1;i<=100;i++)
                    p[k][i]+=p[y][i];   
                c[k][y]=1;
            }
            else
                break;
            k=fa[k];
          /*  printf("%d,%d\n",k,fa[k]);
            j++;
            if(j>1000)
                return 0;*/
        }
    }
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
            if(c[i][j] && i!=j)
                printf("%d %d\n",i,j);
    return 0;
}
