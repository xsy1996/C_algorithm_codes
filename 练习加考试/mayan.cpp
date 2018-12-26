#include<stdio.h>
    FILE *fin=fopen("mayan.in","r");
    FILE *fout=fopen("mayan.out","w");
long a[101][101],n,x[101],y[101],fx[101],t=0,flag=0,xx[101],yy[101],f[101],tt;
long find()
{
    long i,j,k,q,w,e=0,v[50][50],map[50][50];
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            v[i][j]=0;
    e=0;
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            map[i][j]=a[i][j];
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
        if(map[i][j]!=0)
        {
            if(map[i][j]==map[i][j+1] && map[i][j]==map[i][j+2])
            {
                v[i][j+1]=1;
                v[i][j+2]=1;
                v[i][j]=1;
                e=1;
            }
            if( map[i][j]==map[i+1][j] && map[i][j]==map[i+2][j])
            {
                v[i][j]=1;
                v[i+1][j]=1;
                v[i+2][j]=1;
                e=1;
            }
        }
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            a[i][j]=0;
    for(i=1;i<=5;i++)
    {
        k=0;
        for(j=1;j<=7;j++)    
            if(map[i][j]!=0 && v[i][j]!=1)
            {
                k++;
                a[i][k]=map[i][j];
            }
    }
    return e;
}
void dfs(long s)
{
    long i,j,k,q,w,map[101][101];
    if(flag==1)
        return;
    q=1;
    while(q==1)
    {
        q=find();
    }
    k=0;
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            if(a[i][j]!=0)
                k=1;
    if(s==n && k==0)
    {
        flag=1;
        tt=t;
        for(i=1;i<=t;i++)
        {
            xx[i]=x[i];
            yy[i]=y[i];
            f[i]=fx[i];
        }
        return;
    }
    if(s>=n)
        return;
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            map[i][j]=a[i][j];
    t++;
    for(i=1;i<=5;i++)
        for(j=1;j<=7;j++)
            if(map[i][j]!=0)
            {
                x[t]=i;
                y[t]=j;
                if(i!=5)
                {
                for(q=1;q<=5;q++)
                    for(w=1;w<=7;w++)
                        a[q][w]=map[q][w];
                if(a[i+1][j]==0)
                {
                    k=j;
                    while(a[i+1][k]==0 && k>=1)
                        k--;
                    k++;
                    a[i+1][k]=a[i][j];
                    a[i][j]=0;
                    for(k=j;k<=7;k++)
                        a[i][k]=a[i][k+1];
                    fx[t]=1;
                    dfs(s+1);
                }
                else
                {
                    k=a[i][j];
                    a[i][j]=a[i+1][j];
                    a[i+1][j]=k;
                    fx[t]=1;   
                    dfs(s+1);
                }   
                }
                for(q=1;q<=5;q++)
                    for(w=1;w<=7;w++)
                        a[q][w]=map[q][w];
                if(a[i-1][j]==0 && i!=1)
                {
                    k=j;
                    while(a[i-1][k]==0 && k>=1)
                        k--;
                    k++;
                    a[i-1][k]=a[i][j];
                    a[i][j]=0;
                    for(k=j;k<=7;k++)
                        a[i][k]=a[i][k+1];
                    fx[t]=-1;
                    dfs(s+1);
                } 
            }
    t--;
    return;    
}
int main()
{
    long i,j,k;
    fscanf(fin,"%ld",&n);
    for(i=1;i<=5;i++)
    {
        j=1;
        fscanf(fin,"%ld",&k);
        while(k!=0)
        {
            a[i][j]=k;
            j++;
            fscanf(fin,"%ld",&k);
        }
    }   
    dfs(0);
    if(flag==0)
        fprintf(fout,"-1\n");
    else
        for(i=1;i<=tt;i++)
            fprintf(fout,"%d %d %d\n",xx[i]-1,yy[i]-1,f[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}
