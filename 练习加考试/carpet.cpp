#include<stdio.h>
long x1[100001],y1[100001],x2[100001],y2[100001];
int main()
{
    FILE *fin=fopen("carpet.in","r");
    FILE *fout=fopen("carpet.out","w");
    long x,y,n,i,j,k,ans=-1;
    fscanf(fin,"%ld",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%ld%ld%ld%ld",&x1[i],&y1[i],&x2[i],&y2[i]);
        x2[i]+=x1[i];y2[i]+=y1[i];
    }
    fscanf(fin,"%ld%ld",&x,&y);
    for(i=1;i<=n;i++)
        if(x1[i]<=x && y1[i]<=y && x2[i]>=x && y2[i]>=y)
            ans=i;
    fprintf(fout,"%ld\n",ans);
    fclose(fin);
    fclose(fout);
    return 0;
}
