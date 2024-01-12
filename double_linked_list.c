//Double Linked List
#include<stdio.h>
#include<stdlib.h>
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void traverse();
struct node
{
    int data;
    struct node *prev, *next;
}*head=NULL;

void main()
{
    printf("Double Linked List\n");
    operations();
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element:\n");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    operations();
}

void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter element:\n");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newnode;
        newnode-> prev = temp;
    }
    operations();
}

void delete_front()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
    operations();
}

void delete_end()
{
    struct node *temp, *temp1;
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = temp->prev;
        temp1->next = NULL;
        free(temp);
        temp = NULL;
    }
    operations();
}

void traverse()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Empty!\n");
    }
    else
    {
        temp = head;
        printf("Contents of Linked List are: ");
        while(temp != NULL)
        {
            printf("%d   ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    operations();
}

void operations()
{
    int option;
    printf("1. Insert at front\n");
    printf("2. Insert at end\n");
    printf("3. Delete at front\n");
    printf("4. Delete at end\n");
    printf("5. Display data\n");
    printf("6. Exit\n");
    printf("Choice:\t");
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
        default: printf("Enter a valid choice!\n");
                operations();
    }
}
