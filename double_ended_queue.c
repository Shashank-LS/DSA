#include<stdio.h>
#define size 20
void insertrear();
void insertfront();
void delfront();
void delrear();
void display();
void operations();
int front=-1,rear=-1,ele,q[size],i;
void main()
{
    operations();
}

void operations()
{
    printf("1. Insert Front\n");
    printf("2. Insert Rear\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice:\n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
        case 1: insertfront();
        case 2: insertrear();
        case 3: delfront();
        case 4: delrear();
        case 5: display();
        case 6: exit(0);
        default: printf("Enter a valid option!\n");
        operations();
    }
}

void insertfront()
{
    if(front == 0)
    {
        printf("Queue is full at front!\n");
        operations();
    }
    else if(front==-1 && rear==-1)
    {
        front=0,rear=0;
        printf("Enter the element:  ");
        scanf("%d",&ele);
        q[front]=ele;
        operations();
    }
    else
    {
        printf("Enter element:\n");
        scanf("%d",&ele);
        q[front--]=ele;
        operations();
    }
}

void insertrear()
{
    if(rear==size-1)
    {
        printf("Queue is full at rear!\n");
        operations();
    }
    else if(front==-1 && rear==-1)
    {
        front=0,rear=0;
        printf("Enter the element:\n");
        scanf("%d",&ele);
        q[front]=ele;
        operations();
    }
    else
    {
        printf("Enter element:\n");
        scanf("%d",&ele);
        q[++rear]=ele;
        operations();
    }
}

void delfront()
{
    if(front==-1)
    {
        printf("Queue is empty!\n");
        operations();
    }
    else
    {
        printf("Deleted element is %d\n",q[front++]);
        operations();
    }
}

void delrear()
{
    if(front == rear)
    {
        printf("Queue is empty!\n");
        operations();
    }
    else
    {
        printf("Deleted element is %d\n",q[rear--]);
        operations();
    }
}

void display()
{
    if(rear==-1)
    {
        printf("Queue is empty!\n");
        operations();
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d   ",q[i]);
        }
        printf("\n");
        operations();
    }
}
