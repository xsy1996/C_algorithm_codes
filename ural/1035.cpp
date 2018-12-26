#include<stdio.h>
#include<stdlib.h>
long a[202][202],dl[40001][2],sum,fx[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};
bool v[202][202][5];
long jdz(long x){
    if(x>=0)
        return x;
    else
        return -1*x;
    }
long dfs(long x,long y){
    long i,j,k,s=0;
    if(v[x][y][4]){
        s=jdz(a[x][y]);
        for(i=0;i<=3;i++)
            if(v[x][y][i]){
                v[x][y][4]=0;
                s+=dfs(x+fx[i][0],y+fx[i][1]);
                }
        }
    return s;
    }
int main(){
    long i,j,k,n,m,f,l,s;
    char b;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=1;i<=n;i++,getchar())
        for(j=1;j<=m;j++){
            scanf("%c",&b);
            if(b=='\\'){
                a[i][j]++;
                a[i+1][j+1]++;
                v[i][j][1]=1;
                v[i+1][j+1][3]=1;
                v[i][j][4]=1;
                v[i+1][j+1][4]=1;
                }
            else if(b=='X'){
                a[i][j]++;
                a[i+1][j]++;
                a[i][j+1]++;
                a[i+1][j+1]++;
                v[i][j][1]=1;
                v[i+1][j][0]=1;
                v[i][j+1][2]=1;
                v[i+1][j+1][3]=1;
                v[i][j][4]=1;
                v[i+1][j][4]=1;
                v[i][j+1][4]=1;
                v[i+1][j+1][4]=1;
                }
            else if(b=='/'){
                a[i+1][j]++;
                a[i][j+1]++;
                v[i][j+1][2]=1;
                v[i+1][j][0]=1;
                v[i+1][j][4]=1;
                v[i][j+1][4]=1;
                }
            }  
    for(i=1;i<=n;i++,getchar())
        for(j=1;j<=m;j++){
            scanf("%c",&b);
            if(b=='\\'){
                a[i][j]--;
                a[i+1][j+1]--;
                v[i][j][1]=1;
                v[i+1][j+1][3]=1;
                v[i][j][4]=1;
                v[i+1][j+1][4]=1;
                }
            else if(b=='X'){
                a[i][j]--;
                a[i+1][j]--;
                a[i][j+1]--;
                a[i+1][j+1]--;
                v[i][j][1]=1;
                v[i+1][j][0]=1;
                v[i][j+1][2]=1;
                v[i+1][j+1][3]=1;
                v[i][j][4]=1;
                v[i+1][j][4]=1;
                v[i][j+1][4]=1;
                v[i+1][j+1][4]=1;
                }
            else if(b=='/'){
                a[i+1][j]--;
                a[i][j+1]--;
                v[i][j+1][2]=1;
                v[i+1][j][0]=1;
                v[i+1][j][4]=1;
                v[i][j+1][4]=1;
                }
            }    
   
	sum=0;
    for(i=1;i<=n+1;i++)
        for(j=1;j<=m+1;j++) 
            if(v[i][j][4]){
                s=dfs(i,j);
                if(s==0)
                    sum++;
                else
                    sum+=s/2;
                }
    printf("%d\n",sum);
    return 0;
    }

/*
3 3
\\\
\\\
\\\
///
///
///
*/
