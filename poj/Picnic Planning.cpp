#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[101][101],a[101],b[101],dist[101];
long map[102][102],ss[101],n,s[4001][3],t=0,sum=0,f[101],num,v[101][101],m,mm=0;

void qsort(long l,long r){
    long i,j,k,x;
    i=l;j=r;
    x=s[(i+j)/2][0];
    while(i<=j){
        while(s[i][0]<x)i++;
        while(s[j][0]>x)j--;
        if(i<=j){
            k=s[i][0];
            s[i][0]=s[j][0];
            s[j][0]=k;
            k=s[i][1];
            s[i][1]=s[j][1];
            s[j][1]=k;
            k=s[i][2];
            s[i][2]=s[j][2];
            s[j][2]=k;
            i++;j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    }

long father(long x){
    if(f[x]!=x)
        f[x]=father(f[x]);
    return f[x];
    }

void find(long x,long p){
    long i,j,max;
    max=p;
    if(x==1){
        if(s[max][0]>s[mm][0])
            mm=max;
        return;
        }
    for(i=1;i<=n;i++)
        if(v[x][i]==1){
            v[x][i]=0;
            v[i][x]=0;
            if(s[max][0]<map[x][i] && x!=1)
                for(j=1;j<=t;j++)
                    if((s[j][2]==x && s[j][1]==i) || (s[j][1]==x && s[j][2]==i))    
                        max=j;
            find(i,max);
            v[x][i]=1;
            v[i][x]=1;
            }
    return;
    }

void update(){
    long i,j,max=0,x=0,y=0,z=0;
    for(i=2;i<=n;i++)
        if(v[i][1]==0 && ss[i]>0){
            v[i][1]=1;
            v[1][i]=1;
            mm=0;
            find(i,0);
            if(s[mm][0]-ss[i]>max){
                z=i;
                x=s[mm][1];
                y=s[mm][2];
                max=s[mm][0]-ss[i]; 
                }
            v[i][1]=0;
            v[1][i]=0;
            }
    v[z][1]=1;
    v[1][z]=1;
    v[x][y]=0;
    v[y][x]=0;
    sum-=max;
    return;
    }

int main(){
    long i,j,k,q,w,x;
    scanf("%ld",&m);
    getchar();
    n=1;
    name[1][0]='P';
    name[1][1]='a';
    name[1][2]='r';
    name[1][3]='k';
    for(i=1;i<=m;i++,getchar()){
        scanf("%s",a);
        getchar();
        scanf("%s",b);
        scanf("%ld",&k);
        q=0;
        for(j=1;j<=n;j++)
            if(strcmp(a,name[j])==0){
                q=j;
                break;
                }
        if(q==0){
            n++;
            q=n;
            strcpy(name[n],a);
            }
        w=0;
        for(j=1;j<=n;j++)
            if(strcmp(b,name[j])==0){
                w=j;
                break;
                }
        if(w==0){
            n++;
            w=n;
            strcpy(name[n],b);
            }
        map[q][w]=k;
        map[w][q]=k;
        if(q==1)
            ss[w]=k;
        else if(w==1)
            ss[q]=k;
        else{
            t++;
            s[t][0]=k;
            s[t][1]=w;
            s[t][2]=q;
            }   
        }
    scanf("%ld",&num);
    
    qsort(1,t);
    
    for(i=2;i<=n;i++)
        f[i]=i;
    for(i=1;i<=t;i++){
        if(v[s[i][1]][s[i][2]]==0 && father(s[i][1])!=father(s[i][2])){
            f[father(s[i][1])]=father(s[i][2]);
            sum+=s[i][0];
            v[s[i][2]][s[i][1]]=1;
            v[s[i][1]][s[i][2]]=1;
            }
        }
    
    for(i=1;i<=n;i++)
        if(ss[i]!=0 && (dist[father(i)]==0 || ss[i]<ss[dist[father(i)]]))
            dist[father(i)]=i;
    for(i=1;i<=n;i++)
        if(dist[i]>0){
            sum+=ss[dist[i]];
            v[dist[i]][1]=1;
            v[1][dist[i]]=1;
            num--;
            }
    for(i=1;i<=num;i++)
        update();
    printf("Total miles driven: %ld\n",sum);
    system("pause");
    return 0; 
    }
/*
The Contortion Brothers are a famous set of circus clowns, known worldwide for their incredible 
ability to cram an unlimited number of themselves into even the smallest vehicle. During the 
off-season, the brothers like to get together for an Annual Contortionists Meeting at a local park. However, the brothers are not only tight with regard to cramped quarters, but with money as well, so they try to find the way to get everyone to the party which minimizes the number of miles put on everyone's cars (thus saving gas, wear and tear, etc.). To this end they are willing to cram themselves into as few cars as necessary to minimize the total number of miles put on all their cars together. This often results in many brothers driving to one brother's house, leaving all but one car there and piling into the remaining one. There is a constraint at the park, however: the parking lot at the picnic site can only hold a limited number of cars, so that must be factored into the overall miserly calculation. Also, due to an entrance fee to the park, once any brother's car arrives at the park it is there to stay; he will not drop off his passengers and then leave to pick up other brothers. Now for your average circus clan, solving this problem is a challenge, so it is left to you to write a program to solve their milage minimization problem.
Input

Input will consist of one problem instance. The first line will contain a single integer n 
indicating the number of highway connections between brothers or between brothers and the park. 
The next n lines will contain one connection per line, of the form name1 name2 dist, where name1 
and name2 are either the names of two brothers or the word Park and a brother's name (in either 
order), and dist is the integer distance between them. These roads will all be 2-way roads, and 
dist will always be positive.The maximum number of brothers will be 20 and the maximumlength of 
any name will be 10 characters.Following these n lines will be one final line containing an
integer s which specifies the number of cars which can fit in the parking lot of the picnic site. 
You may assume that there is a path from every brother's house to the park and that a solution 
exists for each problem instance.
Output

Output should consist of one line of the form 
Total miles driven: xxx 
where xxx is the total number of miles driven by all the brothers' cars.
*/
