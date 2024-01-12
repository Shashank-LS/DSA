//Stacks elementary operations
#include<stdio.h>
#define size 10
void push();
void pop();
void display();
void isEmpty();
void isFull();
int option,a[size],top=-1,i;

void main()
{
    operations();
}

void operations()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. isEmpty\n");
    printf("5. isFull\n");
    printf("6. Exit\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1: push();
        case 2: pop();
        case 3: display();
        case 4: isEmpty();
        case 5: isFull();
        case 6: exit(1);
        default: printf("Enter a valid option!\n");
        operations();
    }
}

void push()
{
    if(top == size-1)
    {
        printf("Stack is full!\n");
        operations();
    }
    else
    {
        printf("Enter the element:\n");
        scanf("%d",&a[++top]);
        printf("Added %d!\n",a[top]);
        printf("\n");
        operations();
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
        operations();
    }
    else
    {
        printf("Deleted element is %d",a[top]);
        top = top-1;
        printf("\n");
        operations();
    }

}

void isEmpty()
{
    if(top==-1)
    {
        printf("Stack is Empty!\n");
        operations();
    }
    else
    {
        printf("Stack is not empty!\n");
        operations();
    }
}

void isFull()
{
    if(top==size-1)
    {
        printf("Stack is Full!\n");
        operations();
    }
    else
    {
        printf("Stack is not full!\n");
        operations();
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
        operations();
    }
    else
    {
        printf("The elements of the stack are:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",a[i]);
        }
        printf("\n");
        operations();
    }
}
