#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,n,p,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    ptr = (int *)malloc(n*sizeof(int));
    if(ptr == NULL)
    {
        printf("malloc is unsuccessful!\n");
    }
    else
    {
        printf("malloc is successful!\n");
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
        printf("Enter the number of next elements:\n");
        scanf("%d",&p);

        ptr = realloc(ptr,(n+p)*sizeof(int));

        printf("Enter the elements:\n");
        for(i=n;i<(n+p);i++)
        {
            scanf("%d",ptr+i);
        }
        printf("The elements are:\n");
        for(i=0;i<p;i++)
        {
            printf("%d\n",*(ptr+i));
        }
        free(ptr);
    }
    return 0;
}
