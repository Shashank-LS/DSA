#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    ptr = (int *)calloc(n,sizeof(int));
    if(ptr == NULL)
    {
        printf("calloc is unsuccessful!\n");
    }
    else
    {
        printf("calloc is successful!\n");
        printf("Enter the elements:\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",ptr+i);
        }
        printf("The elements are:\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",*(ptr+i));
        }
    }
    return 0;
}
