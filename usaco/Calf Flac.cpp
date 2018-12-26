/*
ID:xsy19962
TASK:calfflac
LANG:C++
*/
#include<stdio.h>
char s[30001];
int main()
{
    FILE *fin=fopen("calfflac.in","r");
    FILE *fout=fopen("calfflac.out","w");
    long len=0,i,j,k,mid,max=0,f,x,y,q,w,l;
    char a;
    while(fscanf(fin,"%c",&a)!=EOF)
    {
        len++;
        s[len]=a;
    }
    for(mid=1;mid<=len;mid++)
    {
        if((s[mid]>'Z' || s[mid]<'A') && (s[mid]<'a' || s[mid]>'z'))
            continue;
        k=1;q=mid;w=mid;
        x=mid;y=mid;
        for(i=1;i<=len;i++)
        {
            x--;
            while((s[x]>'Z' || s[x]<'A') && (s[x]<'a' || s[x]>'z') && x>0)
                x--;
            y++;
            while((s[y]>'Z' || s[y]<'A') && (s[y]<'a' || s[y]>'z') && y<=len)
                y++;
            if((s[x]==s[y] || s[x]+32==s[y] || s[y]+32==s[x]) && 2*i+1>k)
            {
                k=2*i+1;
                q=x;
                w=y;
            }
            else
                break;
        }    
        y=mid+1;
        while((s[y]>'Z' || s[y]<'A') && (s[y]<'a' || s[y]>'z') && y<=len)
            y++;
        if(s[mid]==s[y] || s[mid]+32==s[y] || s[y]+32==s[mid])
        {   
            x=mid;
            for(i=2;i<=len;i++)
            {
                x--;
                while((s[x]>'Z' || s[x]<'A') && (s[x]<'a' || s[x]>'z') && x>0)
                    x--;
                y++;
                while((s[y]>'Z' || s[y]<'A') && (s[y]<'a' || s[y]>'z') && y<=len)
                    y++;
                if((s[x]==s[y] || s[x]+32==s[y] || s[y]+32==s[x]) && 2*i>k)
                {
                    k=2*i;
                    q=x;
                    w=y;
                }
                else
                    break;
            }
        }
        if(k>max)
        {
            max=k;
            f=q;
            l=w;
        }
    }
    fprintf(fout,"%d\n",max);
    for(i=f;i<=l;i++)
        fprintf(fout,"%c",s[i]);
    fprintf(fout,"\n");
    return 0;    
}
