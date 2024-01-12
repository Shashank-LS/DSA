#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *tail=NULL;

void insert_front();
void insert_end();
void delete_front();
void delete_end();
void traverse();
void operations();

void main()
{
    printf("Circular Double Linked List\n");
    operations();
}

void operations()
{
    int option;
    printf("1. Insert Front\n2. Insert End\n3. Delete Front\n4. Delete End\n5. Display\n6.Exit\nChoice:\t");
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
        default: printf("Enter a valid choice!\n");
                 operations();
    }
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\t");
    scanf("%d",&newnode->data);
    newnode->prev = newnode;
    newnode->next = newnode;
    if(tail == NULL)
    {
        tail = newnode;
    }
    else
    {
        struct node *temp;
        temp = tail->next;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = temp;
        temp->prev = newnode;
    }
    operations();
}

void insert_end()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\t");
    scanf("%d",&newnode->data);
    newnode->prev = newnode;
    newnode->next = newnode;
    if(tail == NULL)
    {
        tail  = newnode;
    }
    else
    {
        struct node *temp;
        temp = tail->next;
        tail-> next = newnode;
        newnode->prev = tail;
        newnode->next = temp;
        temp->prev = newnode;
        tail = newnode;
    }
    operations();
}

void delete_front()
{
    if(tail == NULL)
    {
        printf("Empty!\n");
    }
    else if(tail->next == tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *temp, *temp1;
        temp = tail->next;
        temp1 = temp->next;
        tail->next = temp1;
        temp1->prev = tail;
        free(temp);
        temp = NULL;
    }
    operations();
}

void delete_end()
{
    if(tail == NULL)
    {
        printf("Empty!\n");
    }
    else if(tail->next = tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *temp, *temp1;
        temp = tail->prev;
        temp1= tail->next;
        temp->next = temp1;
        temp1->prev = temp;
        free(temp);
        temp = NULL;
    }
    operations();
}

void traverse()
{
    if(tail == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        struct node *temp;
        temp = tail->next;
        do
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        while(temp != tail->next);
        printf("\n");
    }
    operations();
}
