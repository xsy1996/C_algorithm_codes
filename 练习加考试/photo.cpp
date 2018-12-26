#include<stdio.h>
#include<stdlib.h>
char map[80][80];
int jd=0,fz=0,s=0,xmax=0,xmin=80,ymax=0,ymin=80,fx[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
void photo(int x,int y){
     int i,j,k;
     map[x][y]='.';
     s++;
     if(x<xmin)
       xmin=x;
     if(x>xmax)
       xmax=x;
     if(y<ymin)
       ymin=y;
     if(y>ymax)
       ymax=y;
     for(i=0;i<=3;i++)
       if(map[x+fx[i][0]][y+fx[i][1]]=='#')
         photo(x+fx[i][0],y+fx[i][1]);  
     return;
     }
int main(){
   
    int i,j,a,b,m,n;
    char k;
    scanf("%d%d",&m,&n);
    k=getchar();
    for(i=1;i<=m;i++,getchar())
      for(j=1;j<=n;j++)
        scanf("%c",&map[i][j]);
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
        if(map[i][j]=='#'){
          photo(i,j);
          if(s==(xmax-xmin+1)*(ymax-ymin+1))
            fz++;
          else
            jd++;
          s=0;xmin=80;xmax=0;ymax=0;ymin=80;
          }
    printf("%d\n%d\n",fz,jd);
    system("pause");
    return 0;
    }
