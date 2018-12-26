#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long f[1001],x[1001],y[1001],top,m,n,s[500001][2];
double ss[500001];
void qsort(long l,long r){
    int i,j,k;
    double a,b;
    i=l;j=r;
    a=ss[(i+j)/2];
    while(i<=j){
        while(ss[i]<a)i++;
        while(ss[j]>a)j--;
        if(i<=j){
            k=s[i][0];
            s[i][0]=s[j][0];
            s[j][0]=k;
            k=s[i][1];
            s[i][1]=s[j][1];
            s[j][1]=k;
            b=ss[i];
            ss[i]=ss[j];
            ss[j]=b;
            i++;j--;
            }
        }
    if(i<r)qsort(i,r);
    if(l<j)qsort(l,j);
    return;
    }
long father(long a){
    if(f[a]==a)
        return a;
    else{
        f[a]=father(f[a]);
        return f[a];
        }
    }
double kruskal(int a){
    int i,j,k=0;
    double ans;
    qsort(1,top);
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=top;i++){
        if(father(s[i][1])!=father(s[i][0])){
            k++;
            f[father(s[i][1])]=father(s[i][0]);
            }
        if(k==a){
            ans=ss[i];
            break;
            }
        }
    return ans;
    }
int main(){
    int i,j,k,t;
    scanf("%d",&t);
    for(;t>=1;t--){
        top=0;
        scanf("%d%d",&m,&n);
        for(i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++){
                top++;
                ss[top]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                s[top][0]=i;
                s[top][1]=j;
                }
        if(m<2)
            printf("%0.2f\n",kruskal(n-1));
        else if(m>=n)
            printf("0.00\n");
        else
            printf("%0.2f\n",kruskal(n-m));
        }
    system("pause");
    return 0;
    }
