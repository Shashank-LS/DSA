//infix to postfix evaluation
#include<stdio.h>
#include<ctype.h>
#define size 10
int pre(char a);
void infix_postfix();
void push(char b);
char pop();
char infix[20], postfix[20], stack[20],symbol,i=0,k=0;
int top = -1;


void main()
{
    printf("Enter Infix Expression:\n");
    scanf("%s", infix);
    printf("Infix expression: %s", infix);
    infix_postfix();
}

void infix_postfix()
{
    stack[++top] = '#';
    while((symbol = infix[i++])!='\0')
    {
        printf("symbol = %c\n", symbol);
        if(isalnum(symbol))
        {
            postfix[k++] = symbol;
        }
        else if(symbol=='(')
        {
            push(symbol);
        }
        else if(symbol == ')')
        {
            while(stack[top]!='(')
            {
                postfix[k++] = pop();
            }
            char ele = pop();
        }
        else
        {
            if(pre(stack[top])>=pre(symbol))
            {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    while(stack[top]!='#')
    {
        postfix[k++] = pop();
    }
    printf("postfix: %s\n", postfix);
}

int pre(char a)
{
    if(a == '*'|| a == '/')
    {
        return 2;
    }
    else if(a == '+'|| a== '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
