//Array elementary operations
#include<string.h>
void insert();
void delete();
void display();
void operations();
int a[10],n,pos,ele,option,i;

void main()
{
    create();
    operations();
}

void create()
{
    printf("Enter the size of the array:   ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void operations()
{
    printf("1. Insert Element\n");
    printf("2. Remove Element\n");
    printf("3. Display Array\n");
    printf("4. Exit\n");
    printf("Enter your choice:  ");
    scanf("%d",&option);
    switch(option)
    {
        case 1: insert();
        case 2: delete();
        case 3: display();
        case 4: exit(1);
        default :  printf("Enter a valid option!\n");
        operations();
    }
}

void delete()
{
    printf("Enter the position:\n");
    scanf("%d",&pos);
    for(i=pos-1;i<n;i++)
    {
        a[i] = a[i+1];
    }
    n--;
    operations();
}

void insert()
{
    printf("Enter the position:  ");
    scanf("%d",&pos);
    printf("Enter the element:  ");
    scanf("%d",&ele);
    for(i=n-1;i>=pos-1;i--)
    {
        a[i+1] = a[i];
    }
    a[pos-1] = ele;
    n++;
    operations();
}

void display()
{
    printf("The elements of the Array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d   ",a[i]);
    }
    printf("\n");
    operations();
}
