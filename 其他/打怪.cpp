#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x,y;  
  }zb;
zb dl[10001];
int jx[102][102]; 
int x[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    int n,m,f,r,fx,sum=0,fy,i,j,k;
    
    scanf("%d%d",&m,&n);

    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++){
        scanf("%d",&k);
        if(k==1)
          jx[i][j]=0;
        if(k==0)
          jx[i][j]=1;
        if(k==2)
		  jx[i][j]=2;   
          }
    f=0;
    r=1;
    dl[1].x=1;
    dl[1].y=1;
    jx[1][1]=0;
    while(f<=r){
      f++;
      for(i=0;i<=3;i++){
	    fx=dl[f].x+x[i][0];
	    fy=dl[f].y+x[i][1];
		if(jx[fx][fy]!=0){
		  r++;
		  if(jx[fx][fy]==2)
		    sum++;
		  dl[r].x=fx;
		  dl[r].y=fy;
		  jx[fx][fy]=0;
			}
		  }
      }
    printf("%d\n",sum);
    system("pause");
    return 0;
    }
