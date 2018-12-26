#include<stdio.h>
long k[51][200001],f[101],l[101],q[200001],n,m,p,s[200001];
long long ans=0;
int main()
{
    FILE *fin=fopen("hotel.in","r");
    FILE *fout=fopen("hotel.out","w");
    long i,j,a,b,c;
    fscanf(fin,"%ld%ld%ld",&n,&m,&p);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%ld%ld",&a,&b);
        l[a+1]++;
        k[a+1][l[a+1]]=i;
        s[i]=a+1;
        if(b<=p)
        {
            l[0]++;
            q[l[0]]=i;
        }
    }
    for(i=1;i<=n;i++)
    {
        while(q[f[0]]<i && f[0]<=l[0])
            f[0]++;
        if(f[0]>l[0])
            break;
        while(k[s[i]][f[s[i]]]<q[f[0]] && f[s[i]]<=l[s[i]])
            f[s[i]]++;
        if(k[s[i]][f[s[i]]]==i && f[s[i]]<=l[s[i]])
            f[s[i]]++;
        ans+=l[s[i]]-f[s[i]]+1;
    }
    fprintf(fout,"%I64d\n",ans);
    fclose(fin);
    fclose(fout);
    return 0;
}
