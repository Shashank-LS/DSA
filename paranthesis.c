//parenthesis
#include <stdio.h>
#define size 20
#include <string.h>

int top = -1, i;
char stack1[size], stack[size], ch;

void push(char b)
{
    stack[++top] = b;
}

char pop()
{
    top--;
}

int main(){
    printf("enter the expression: \n");
    scanf("%s", stack1);
    push('#');
    for(i=0; i < strlen(stack1); i++)
    {
        ch = stack1[i];
        if(ch == '(')
            push(ch);
        if(ch ==')')
        {
            if(stack[top]!='#')
                pop();
            else
            {
                printf("closing parentheses are not balanced\n");
                return 0;
            }
        }
    }
    if(stack[top]=='#')
        printf("parentheses are balanced\n");
    else
        printf("opening parentheses are not balanced\n");
}
