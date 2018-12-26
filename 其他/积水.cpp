#include<stdio.h>
#include<stdlib.h>
long high[101][101],heap[10001][2],t,sum=0,fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool v[102][102];
void add(long x,long y){
    long i,j,k;
    t++;
    i=t;
    while(i>1 && high[x][y]<high[heap[i/2][0]][heap[i/2][1]]){
        heap[i][0]=heap[i/2][0];
        heap[i][1]=heap[i/2][1];
        i/=2;
        }
    heap[i][0]=x;
    heap[i][1]=y;
    return;
    }
void del(long x){
    long i,j,k,x1,y1;
    if(2*x>t)
        return;
    i=x;k=i;
    if(high[heap[i][0]][heap[i][1]]>high[heap[i*2][0]][heap[i*2][1]])
        k=i*2;
    if(i*2+1<=t && high[heap[i*2+1][0]][heap[i*2+1][1]]<high[heap[k][0]][heap[k][1]])
        k=i*2+1;
    if(k!=x){
        x1=heap[i][0];
        y1=heap[i][1];
        heap[i][0]=heap[k][0];
        heap[i][1]=heap[k][1];
        heap[k][0]=x1;
        heap[k][1]=y1;
        del(k);   
        }
    return;
    }
void dfs(long x,long y,long h){
    long i,j,k,x1,y1;
    for(i=0;i<=3;i++){
        x1=x+fx[i][0];
        y1=y+fx[i][1];
        if(v[x1][y1]==0){
            v[x1][y1]=1;
            if(high[x1][y1]<=h){
                sum+=h-high[x1][y1];
                dfs(x1,y1,h);
                }
            else
                add(x1,y1);      
            }
        }
    }
int main(){
    long i,j,k,n,m;
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    scanf("%ld%ld",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%ld",&high[i][j]);
    heap[1][0]=1;heap[1][1]=1;
    v[1][1]=1;
    t=1;
    if(!v[1][m]){
        add(1,m);
        v[1][m]=1;
        }
    if(!v[n][1]){
        add(n,1);
        v[n][1]=1;
        }
    if(!v[n][m]){
        add(n,m);
        v[n][m]=1;
        }
    for(i=2;i<n;i++){
        add(i,1);
        v[i][1]=1;
        add(i,m);
        v[i][m]=1;
        }
    for(j=2;j<m;j++){
        add(1,j);
        v[1][j]=1;
        add(n,j);
        v[n][j]=1;
        }
    for(i=0;i<=n+1;i++){
        v[i][0]=1;
        v[i][m+1]=1;
        }
    for(i=0;i<=m+1;i++){
        v[0][i]=1;
        v[n+1][i]=1;
        }
    while(t>0){
        dfs(heap[1][0],heap[1][1],high[heap[1][0]][heap[1][1]]);
        heap[1][0]=heap[t][0];
        heap[1][1]=heap[t][1];
        t--;
        del(1);
        }

    printf("%ld\n",sum);
    system("pause");
    return 0;
    }









/*
Description 

��һ�����ε���������n*m��������Ӧ����n*m�������尲�������档ÿһ�������嶼ǡ�ø�����һ�����񣬶������ǵĵ��������1ƽ��Ӣ�硣���ڵ�����������֮��û�п�϶��һ������������ڸ߶Ȳ��죬һЩ�������ϳ����˻�ˮ�� 

���� 
�� ���ļ�WOD.IN�ж���������̵Ĵ�С��ÿһ��������ĸ߶ȡ� 
�� �����������󳤷����Ͽ��ܵ�����ˮ���� 
�� �ѽ��д���ļ�WOD.OUT�� 
�����ͼ��ʾ�������е������ڱ�����������ˮ������������¿����� 
��ˮ��������Ӱ��ʾ�� 
 
 

Input 

�����ļ�WOD.IN�ĵ�һ��������������n,m (1 <= n <= 100, 1 <= m <= 100)����ʾ����Ĵ�С�����µ�n�У�ÿ����m��[1..10000]��Χ�ڵ���������j�еĵ�I������ʾ�����е�j�е�I�еĵ��ϵĳ�����ĸ߶ȡ�

Output 

�ѽ������Ͽ��ܲ����Ļ�ˮ�������ֵ��������Ӣ��Ϊ��λ��������ı��ļ�WOD.OUT�С�

Sample Input 


3 6
3 3 4 4 4 2
3 1 3 2 1 4
7 3 1 6 4 1


Sample Output 


5
*/
