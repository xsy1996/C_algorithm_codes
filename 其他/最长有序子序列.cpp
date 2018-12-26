#include<stdio.h>
#include<stdlib.h>
int a[50001],dl[50001],n,suma,sumk;

void covera(int x,int l,int r){
    int m=(l+r)/2;
    if((m==1 && dl[m]>=x) || (m==suma && dl[m]>=x))
        dl[m]=x;
    else if(dl[m-1]<=x && dl[m]>x)
        dl[m]=x;
    else if(dl[m]<=x && dl[m+1]>x)
        dl[m+1]=x;
    else if(dl[m]>x)
        covera(x,l,m);
    else
        covera(x,m,r);
    return;
    }

void coverk(int x,int l,int r){
    int m=(l+r)/2;
    if((m==1 && dl[m]<=x) || (m==sumk && dl[m]<=x))
        dl[m]=x;
    else if(dl[m-1]>=x && dl[m]<x)
        dl[m]=x;
    else if(dl[m]>=x && dl[m+1]<x)
        dl[m+1]=x;
    else if(dl[m]<x)
        coverk(x,l,m);
    else
        coverk(x,m,r);
    return;
    }

void anabatic(){
    int i,j,k;
    suma=1;
    dl[1]=a[1];
    for(i=2;i<=n;i++){
        if(a[i]<dl[suma])
            covera(a[i],1,suma);
        else{
            suma++;
            dl[suma]=a[i];
            }
        }
    return;
    }
 
void katabatic(){
    int i,j,k;
    sumk=1;
    dl[1]=a[1];
    for(i=2;i<=n;i++){
        if(a[i]>dl[sumk])
            coverk(a[i],1,sumk);
        else{
            sumk++;
            dl[sumk]=a[i];
            }
        }
    return;
    }
   
int main(){
    freopen("sl.in","r",stdin);
    freopen("sl.out","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    anabatic();
    katabatic();
    if(suma>sumk)
        printf("%d\n",n-suma);
    else
        printf("%d\n",n-sumk);
  //  system("pause");
    return 0;
    }
