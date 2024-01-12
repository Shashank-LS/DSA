//circular single linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*tail=NULL;
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void traverse();
void operations();

void main()
{
    printf("Circular Single Linked List\n");
    operations();
}

void operations()
{
    printf("1. Insert Front\n");
    printf("2. Insert End\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Choice:\t");
    int option;
    scanf("%d",&option);
    switch(option)
    {
        case 1: insert_front();
                break;
        case 2: insert_end();
                break;
        case 3: delete_front();
                break;
        case 4: delete_end();
                break;
        case 5: traverse();
                break;
        case 6: exit(1);
                break;
        default: printf("Enter a valid expression!\n");
                 operations();
    }
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("Enter element:\n");
    scanf("%d",&newnode->data);
    newnode->link = newnode;
    if(tail==NULL)
    {
        tail = newnode;
    }
    else
    {
        newnode->link = tail->link;
        tail->link = newnode;
    }
    operations();
}

void insert_end()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("Enter element:\n");
    scanf("%d",&newnode->data);
    newnode->link = newnode;
    if(tail==NULL)
    {
        tail = newnode;
    }
    else
    {
        newnode->link = tail->link;
        tail->link = newnode;
        tail = newnode;
    }
    operations();
}

void delete_front()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("Empty!\n");
    }
    else if(tail->link = tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        temp = tail->link;
        tail->link = temp->link;
        free(temp);
        temp = NULL;
    }
    operations();
}

void delete_end()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("Empty!\n");
    }
    else if(tail->link = tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        temp = tail->link;
        while(temp->link != tail)
        {
            temp = temp->link;
        }
        temp->link = tail->link;
        free(tail);
        tail = temp;
        free(temp);
        temp = NULL;
    }
    operations();
}

void traverse()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("Empty!\n");
    }
    else
    {
        temp = tail->link;
        do
        {
            printf("%d\t",temp->data);
            temp = temp->link;
        }
        while(temp != tail->link);
        printf("\n");
    }
    operations();
}
