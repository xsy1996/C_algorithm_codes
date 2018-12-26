#include<stdio.h>
#include<string.h>
int map[500][500];           //边
int ans;                     //割边数量
int num;                     //可以连通的点的个数
int adjN,edgeN;              //点个数，边个数
int low[500];                //点的最小深度
int depth[500];              //点的深度
int mark[500];               //遍历过做标志
void junge(int now,int par)
//判断图是否连通
{
 for(int i=1;i<=adjN;i++)
 {
  if(map[now][i]==1&&i!=par&&mark[i]!=1)
  {
   mark[i]=1;
   num++;
   junge(i,now);
  }
 }
}
void cutline(int now,int par,int dep)
//求割边数
{
 depth[now]=dep;
 low[now]=dep;
 for(int i=1;i<=adjN;i++)
 {
  if(par!=i&&map[now][i]==1)
  {
   if(depth[i]==0)
   {
      cutline(i,now,dep+1);
      if(low[i]<low[now])
      {
       low[now]=low[i];
      }
      if(low[i]>depth[now])
      {
       ans++;
      }
   }
   else if(depth[i]<low[now])
           low[now]=depth[i];
  }
 }
}
int main()
{
 freopen("input.txt","r",stdin);
 while(scanf("%d %d ",&adjN,&edgeN)==2)
 {
   int m,n;
   ans=0;
   num=1;
   memset(depth,0,sizeof(depth));
      memset(low,0,sizeof(low));
   memset(mark,0,sizeof(mark));
   memset(map,0,sizeof(map));
      for(int i=1;i<=edgeN;i++)
   {
      scanf("%d %d ",&m,&n);
      map[m][n]=1;
   map[n][m]=1;
   }
   mark[1]=1;
   junge(1,-1);
   if(num==adjN)
   {
         cutline(1,0,1);
         printf("%d\n",ans);
   }
   else
    printf("%d\n",-1);
 }
 return 0;
}