#include <stdio.h>
#include <stdlib.h>	
#define MaxStackSize  100	
typedef int DataType;
typedef struct
{        DataType stack[MaxStackSize];			
          int top;
} SeqStack;
//��ʼ��StackInitiate(S)
void StackInitiate(SeqStack *S)	
{
          S->top = 0;		
}
//�ǿշ�StackNotEmpty(S)
int StackNotEmpty(SeqStack S)
{
           if(S.top <= 0)return 0;
           else return 1;
}
//��ջStackPush(S, x)
int StackPush(SeqStack *S, DataType x)
{        if(S->top >= MaxStackSize)
         {        
                   printf("��ջ�����޷�����! \n");
	   return 0;
          }
          else
     {    S->stack[S->top] = x;
	  S->top ++;
                    return 1;
           }
}
//         ��ջStackPop(S, d)
int StackPop(SeqStack *S, DataType *d)
{        if(S->top <= 0)
         {        printf("��ջ�ѿ�������Ԫ�س�ջ! \n");
	    return 0;
          }
          else
          {        S->top --;*d = S->stack[S->top];
                    return 1;
          }
}
//ȡջ������Ԫ��StackTop(SeqStack S, DataType *d)
int StackTop(SeqStack S, DataType *d)
{         if(S.top <= 0)
          {        printf("��ջ�ѿ�! \n");
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
      printf("��ǰջ��Ϊ%d\n",a);
    printf("���γ�ջ��Ԫ��Ϊ��\n"); 
    while(StackNotEmpty(myStack)){
      StackPop(&myStack,&a);
      printf("%d ",a);
      }
      printf("\n");
    system("pause");
    return 0;
}

