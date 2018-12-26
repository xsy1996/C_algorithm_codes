#include<stdio.h>
long average,apprise,study;
bool manage,west;
char name[201][201],a;
long s1()
{
    if(average>80 && study>=1)
        return 8000;
    else
        return 0;
}
long s2()
{
    if(average>85 && apprise>80)
        return 4000;
    else
        return 0;
}
long s3()
{
    if(average>90)
        return 2000;
    else
        return 0;
}
long s4()
{
    if(average>85 && west)
        return 1000;
    else
        return 0;
}
long s5()
{
    if(apprise>80 && manage)
        return 850;
    else
        return 0;
}

int main()
{
    freopen("scholar.in","r",stdin);
    freopen("scholar.out","w",stdout);
    long i,j,k,n,max=0,num,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%s",name[i]);
        scanf("%d%d",&average,&apprise);
        getchar();
        scanf("%c",&a);
        if(a=='Y')
            manage=1;
        else
            manage=0;
        getchar();
        scanf("%c",&a);
        if(a=='Y')
            west=1;
        else
            west=0;
        scanf("%d",&study);
        k=s1()+s2()+s3()+s4()+s5();
        sum+=k;
        if(k>max)
        {
            max=k;
            num=i;
        }
    }
    printf("%s\n%d\n%d\n",name[num],max,sum);
    return 0;
}
