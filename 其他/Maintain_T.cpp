#include<stdio.h>

int n,m;
int a[201][201],d[201],lj[201],p[201];

int main(){
    
    int i,j,k,m,sx=0,sum=0,flag,max;
    int x,y,w,s,t,x1,y1;
    int i1,j1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);                 
        if(a[x][y]!=0){
            if(a[x][y]>w){
                sum -= a[x][y];
                sum += w;                
                a[x][y]=w;
                a[y][x]=w;
            }
            if(sx<n-1)
                printf("-1\n");
            else
                printf("%d\n",sum);          
            continue;
        }            
        for(j=1;j<=n;j++)lj[j]=0;
        for(j=1;j<=n;j++)p[j]=0;
        s=0;t=1;d[1]=x;
        flag=0;p[x]=1;
        while(s<t){
            s++;
            for(j=1;j<=n;j++)
                if(a[d[s]][j]!=0 && p[j]==0){
                    t++;
                    d[t]=j;
                    p[j]=1;
                    lj[j]=d[s];
                    if(j==y){
                        flag=j;
                        break;
                    }
                }
            if(flag!=0)break;
        }      
        if(flag==0){
            sx++;
            sum +=w;
            a[x][y]=w;
            a[y][x]=w;
        }else{                          
            k=flag;max=0;
            while(lj[k]!=0){
                if(a[k][lj[k]]>max){
                    max=a[k][lj[k]];
                    x1=k;y1=lj[k];
                }
                k=lj[k];
            }
            if(w<max){
                sum -=max;
                sum +=w;
                a[x1][y1]=0;
                a[y1][x1]=0; 
                a[x][y]=w;
                a[y][x]=w;                               
            }
        }
        if(sx<n-1)
            printf("-1\n");
        else
            printf("%d\n",sum);
    }    
    return 0;
}
