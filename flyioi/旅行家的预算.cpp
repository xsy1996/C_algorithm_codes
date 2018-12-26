
#include<stdio.h>
#include<stdlib.h>

double v[100],w[100];

int main(){
    
    int i,j,n,g;
    double m=0,o=0,l,c,d,e;       
    scanf("%lf%lf%lf%lf%d",&e,&c,&d,&v[1],&n);    
    for(i=2;i<=n+1;i++)
        scanf("%lf%lf",&w[i],&v[i]);       
    n=n+2;                               
    w[n]=e;                              
    w[1]=0;
    i=1;                                  
    l=c*d;                                
    while(i<=n){                           
      if(w[i+1]-w[i]>l){                
        printf("No Solution\n");             
        system("pause");
        return 0;
      }        
      g=0;                          
      for(j=i+1;w[j]-w[i]<=l && j<=n;j++)   
        if(v[j]<v[i]){
          g=j;
          break;
        }
      if(g==0){                         
        if(e-w[i]<l){                   
          m +=((e-w[i])*1.0/d-o)*v[i];
          printf("%0.2f\n",m);
          system("pause");
          return 0;
        }                 
      m += v[i]*(c-o);                  
      o=c;                           
      o -=(w[i+1]-w[i])*1.0/d;      
      i=i+1;                           
    }else{                                 
         if(o*d>=(w[g]-w[i])){                  
           o -= (w[g]-w[i])*1.0/d;
           i=g;                       
         }else{                            
              m +=(((w[g]-w[i])*1.0/d)-o)*v[i];
              o=0;                       
              i=g;                       
              }         
         }
    }   
    printf("%0.2f\n",m);                  
    system("pause");
    return 0;
}
