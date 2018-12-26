/*
ID:xsy19962
TASK:ttwo
LANG:C
*/
#include<stdio.h>
long map[12][12],v[101][4][101][4],xc,yc,xf,yf,flag=0,sum=0;
void find(long fxc,long fxf){
    if(flag!=0)
        return;
    if(fxc==0){
        if(map[xc-1][yc]!=1)
            xc--;
        else
            fxc=(fxc+1)%4;
        }
    else if(fxc==1){
        if(map[xc][yc+1]!=1)
            yc++;
        else
            fxc=(fxc+1)%4;
        }
    else if(fxc==2){
        if(map[xc+1][yc]!=1)
            xc++;
        else
            fxc=(fxc+1)%4;
        }
    else if(fxc==3){
        if(map[xc][yc-1]!=1)
            yc--;
        else
            fxc=(fxc+1)%4;
        }
    if(fxf==0){
        if(map[xf-1][yf]!=1)
            xf--;
        else
            fxf=(fxf+1)%4;
        }
    else if(fxf==1){
        if(map[xf][yf+1]!=1)
            yf++;
        else
            fxf=(fxf+1)%4;
        }
    else if(fxf==2){
        if(map[xf+1][yf]!=1)
            xf++;
        else
            fxf=(fxf+1)%4;
        }
    else if(fxf==3){
        if(map[xf][yf-1]!=1)
            yf--;
        else
            fxf=(fxf+1)%4;
        }
    sum++;
    if(xc==xf && yc==yf)
        flag=1;
    else if(v[(xc-1)*10+yc][fxc][(xf-1)*10+yf][fxf]==0)
        v[(xc-1)*10+yc][fxc][(xf-1)*10+yf][fxf]=1;
    else
        flag=-1;
    find(fxc,fxf);
    return;
    }
int main(){
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    long i,j,k;
    char a;
    for(i=0;i<=11;i++){
        map[i][0]=1;
        map[i][11]=1;
        map[0][i]=1;
        map[11][i]=1;
        }
    for(i=1;i<=10;i++,getchar())
        for(j=1;j<=10;j++){
            scanf("%c",&a);
            if(a=='*')
                map[i][j]=1;
            if(a=='.')
                map[i][j]=0;
            if(a=='C'){
                map[i][j]=0;
                xc=i;yc=j;
                }    
            if(a=='F'){
                map[i][j]=0;
                xf=i;yf=j;
                }    
            }
    v[(xc-1)*10+yc][0][(xf-1)*10+yf][0]=1;
    find(0,0);
    if(flag==1)
        printf("%ld\n",sum);
    else
        printf("0\n");
    return 0;
    }
