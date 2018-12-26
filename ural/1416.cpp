#include<stdio.h>
#include<stdlib.h>
long map[501][501],v[501][501],dist[501][501],s[250001][2];
bool visit[501];
int main(){ 
    long min,a,b,c,i,j,k,m,n,x,y,sum=0,l=0;
    scanf("%ld%ld",&n,&m);
    min=0;
    map[0][0]=100000000;
    for(i=1;i<=m;i++){
        scanf("%ld%ld%ld",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
        s[i][0]=a;
        s[i][1]=b;
        v[a][b]=1;
        v[b][a]=1;
        }
    visit[1]=1;
    for(c=1;c<n && l==c-1;c++){
        min=100000000;
        for(i=1;i<=m;i++)
            if(v[s[i][0]][s[i][1]]==1 && visit[s[i][0]]+visit[s[i][1]]==1 && map[s[i][0]][s[i][1]]<min){
                if(visit[s[i][0]]==1){
                    x=s[i][0];
                    y=s[i][1];
                    }
                else{
                    y=s[i][0];
                    x=s[i][1];
                    }
                min=map[x][y];
                } 
        if(min!=100000000){
            for(i=1;i<=n;i++)
                if(visit[i]==1){
                    if(map[x][y]>dist[i][x]){
                        dist[y][i]=map[x][y]; 
                        dist[i][y]=map[x][y];
                        }
                    else{
                        dist[i][y]=dist[i][x];
                        dist[y][i]=dist[x][i];
                        }
                    }
                visit[y]=1;
                v[x][y]=2;
                v[y][x]=2;
                l++;
                sum+=min;
            }
        }
    if(l!=n-1)
        printf("Cost: -1\nCost: -1\n");
    else{
        printf("Cost: %ld\n",sum);
        min=100000000;
        for(i=1;i<=m;i++)
            if(v[s[i][0]][s[i][1]]==1 && map[s[i][0]][s[i][1]]-dist[s[i][0]][s[i][1]]<min)  
                min=map[s[i][0]][s[i][1]]-dist[s[i][0]][s[i][1]];
        if(min==100000000)
            printf("Cost: -1\n");
        else 
            printf("Cost: %ld\n",sum+min);
        }
    system("pause");
    return 0;
    }

