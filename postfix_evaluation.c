#include <stdio.h>
#include <ctype.h>
#define size 10
void evaluate();
void push(char b);
char pop();
char postfix[20],symbol;
int stack[20],top=-1,i=0,op1,op2,res;

void main()
{
    printf("Enter the postfix expression:\n");
    scanf("%s",postfix);
    printf("Entered expression is: %s", postfix);
    evaluate();
}

void evaluate()
{
    while((symbol=postfix[i++])!='\0')
    {
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(symbol)
            {
                case '+':res=op1+op2;
                        push(res);
                        break;
                case '-':res=op1-op2;
                        push(res);
                        break;
                case '*':res=op1*op2;
                        push(res);
                        break;
                case '/':res=op1/op2;
                        push(res);
                        break;
            }
        }
    }
    printf("\nResult of the entered expression is:  %d",pop());
}

void push(char b)
{
    if(top==size-1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = b;
}

char pop()
{
    return(stack[top--]);
}
