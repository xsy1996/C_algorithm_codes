#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x,y,bs;  
  }zb;
zb dl[10001];
int jx[102][102]; 
int x[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    int n,m,f,r,fx,fy,i,j,k;
    char a,b;
    scanf("%d%d",&m,&n);
    getchar();
    for(i=1;i<=m;i++,getchar())
      for(j=1;j<=n;j++){
        scanf("%c",&a);
        if(a=='*')
          jx[i][j]=1;
        if(a=='|')
          jx[i][j]=0;
          }
    f=0;
    r=1;
    dl[1].x=1;
    dl[1].y=1;
    dl[1].bs=1;
    jx[1][1]=0;
    while(f<=r){
      f++;
      for(i=0;i<=3;i++){
	    fx=dl[f].x+x[i][0];
	    fy=dl[f].y+x[i][1];
		
		if(jx[fx][fy]!=0){
		  r++;
		  dl[r].x=fx;
		  dl[r].y=fy;
		  dl[r].bs=dl[f].bs+1;
		  jx[fx][fy]=0;
		  if(fx==m && fy==n){
		    printf("%d\n",dl[r].bs);
		    system("pause");
			return 0;
			}
		  }
		}
	  }
    system("pause");
    return 0;
    }
