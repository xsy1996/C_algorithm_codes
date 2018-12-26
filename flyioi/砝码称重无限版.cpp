#include<stdio.h>
#include<stdlib.h>
int a[101],d[1000001][3];//Ì¿¬Î     ∂”¡– 
bool v[1000001]; //≈–÷ÿ 
int main(){
    int x,y,f,l,m,n,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==m){
            printf("1\n");
            system("pause");
            return 0;
            }
        else if(x<m)
            v[x]=1;
        }
    y=0;
    for(i=1;i<=m;i++)
        if(v[i]==1){
            y++;
            a[y]=i;
            v[i]=0;
            }
    for(i=1;i<=y;i++){
        d[i][0]=a[i];
        d[i][1]=1;
        d[i][2]=i;
        }
    l=y;f=0;
    while(f<l){
        f++;
        for(i=d[f][2];i<=y;i++){
            x=d[f][0]+a[i];
            if(x==m){
                printf("%d",d[f][1]+1);
                system("pause");
                return 0;
                }
            else if(x<m && v[x]==0){
                l++;
                v[x]=1;
                d[l][0]=x;
                d[l][1]=d[f][1]+1;
                d[l][2]=i;
                }
            }
        }          
    printf("IMPOSSIBLE\n");
    system("pause");
    return 0;
    }
