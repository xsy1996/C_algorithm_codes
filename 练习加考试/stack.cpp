#include <stdio.h>
#include <stdlib.h>	
#define MaxStackSize  100	
typedef int DataType;
typedef struct
{        DataType stack[MaxStackSize];			
          int top;
} SeqStack;
//初始化StackInitiate(S)
void StackInitiate(SeqStack *S)	
{
          S->top = 0;		
}
//非空否StackNotEmpty(S)
int StackNotEmpty(SeqStack S)
{
           if(S.top <= 0)return 0;
           else return 1;
}
//入栈StackPush(S, x)
int StackPush(SeqStack *S, DataType x)
{        if(S->top >= MaxStackSize)
         {        
                   printf("堆栈已满无法插入! \n");
	   return 0;
          }
          else
     {    S->stack[S->top] = x;
	  S->top ++;
                    return 1;
           }
}
//         出栈StackPop(S, d)
int StackPop(SeqStack *S, DataType *d)
{        if(S->top <= 0)
         {        printf("堆栈已空无数据元素出栈! \n");
	    return 0;
          }
          else
          {        S->top --;*d = S->stack[S->top];
                    return 1;
          }
}
//取栈顶数据元素StackTop(SeqStack S, DataType *d)
int StackTop(SeqStack S, DataType *d)
{         if(S.top <= 0)
          {        printf("堆栈已空! \n");
	     return 0;
          }
           else
          {        *d = S.stack[S.top - 1];
	     return 1;
          }
}

int main()
{
    SeqStack myStack;
    int i,x,s,a,n;
    StackInitiate(&myStack);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&x);
      StackPush(&myStack, x);
      }
    StackTop(myStack,&a);
      printf("当前栈顶为%d\n",a);
    printf("依次出栈的元素为：\n"); 
    while(StackNotEmpty(myStack)){
      StackPop(&myStack,&a);
      printf("%d ",a);
      }
      printf("\n");
    system("pause");
    return 0;
}

