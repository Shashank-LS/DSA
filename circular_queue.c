#include<stdio.h>
#define size 5
void operations();
void insert();
void delete();
void display();
void create();
int q[size],i,option,rear=-1,front=-1,data;

void main()
{
    operations();
}

void operations()
{
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter choice:  ");
    scanf("%d",&option);
    switch(option)
    {
        case 1: insert();
        case 2: delete();
        case 3: display();
        case 4: exit(0);
        default : printf("Enter a valid option!\n\n");
        operations();
    }
}

void insert()
{
    if((rear-front)==size-1 || (front-rear)==1)
    {
        printf("The queue is full!\n");
        operations();
    }
    else
    {
        printf("Enter the number:   ");
        scanf("%d",&data);
        rear = (rear+1)%size;
        q[rear] = data;
        operations();
    }
}

void delete()
{
    if(rear==-1)
    {
        printf("The Queue is empty!\n");
        operations();
    }
    else
    {
        printf("The deleted element is %d",q[front+1]);
        front = (front+1)%size;
        operations();
    }
}

void display()
{
    if(rear==-1)
    {
        printf("The Queue is empty!\n");
        operations();
    }
    else
    {
        printf("The elements of the queue are:\n");
        for(i=front+1;i<=rear;i++)
        {
            printf("%d   ",q[i]);
        }
        printf("\n");
        operations();
    }

}
