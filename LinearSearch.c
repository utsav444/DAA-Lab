#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, arr[size], n, flag = 0, position;

    printf("Enter 10 elements of the array: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to search: ");
    scanf("%d", &n);

    for (i = 0; i < 10; i++)
    {
        if (n == arr[i])
        {
            flag = 1;
            position = i;
            printf("Element found at %d position", i + 1);
            break;
        }
    }

    if (flag == 0)
    {
        printf("Not found");
    }

    return 0;
}
