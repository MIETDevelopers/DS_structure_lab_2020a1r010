//Implement a list using Array and develop functions to perform insertion,
//deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
//insertion function for inserting elements at any position
int insert(int *list, int size, int item, int insertAt)
{
    int i, sizeOfList;
    sizeOfList = size;
    list = realloc(list, ((size + 1) * sizeof(int)));
    for (i = size; i >= insertAt; i--)
        list[i + 1] = list[i];      //used for shifting the elements from left to right in the list

    list[insertAt] = item;
    sizeOfList = ++size;
    return sizeOfList;
}
//insertion function for inserting elements in an empty list
int insertAtEmpty(int *list, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter the elements at the list[%d]: ", i);
        scanf("%d", (list + i));
    }
}
//function for printing list
int printList(int *list, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("arr[%d] = %d\n", i, *(list + i));
    }
}
//function for searching elements in the list
int search(int *list, int value, int size)
{
    int i, key = 0;
    for (i = 0; i < size; ++i)
    {
        if (list[i] == value)
        {
            key = 1;
            break;
        }
    }
    if (key == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
//function for deleting elements in the list
int del(int *list, int index, int size)
{
    int newSizeOfList, count;
    for (count = index; count < size - 1; count++)
        list[count] = list[count + 1];   //shifting elements from right to left
    newSizeOfList = --size;
    return newSizeOfList;
}
int main()
{
    int *list, sizeOfList;
    int size, item, count = 0;
    int choice, value, index, result;
    int insertAt;
    printf("enter the size \n");
    scanf("%d", &size);
    list = (int *)malloc(size * sizeof(int));
    insertAtEmpty(list, size);
    do
    {
        printf("Implementation of list\nchoose any operation\n");
        printf("1.Insert an element\n 2.Delete an element\n 3.Search\n 4. View list\n 5. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the position where you want to insert\n");
            scanf("%d", &insertAt);
            printf("enter the value to insert \n");
            scanf("%d", &item);
            sizeOfList = insert(list, size, item, insertAt);
            size = sizeOfList;
            printf("updated array\n");
            printList(list, size);
            break;

        case 2:
            printf("Enter the index you want to delete\n\t");
            scanf("%d", &index);
            sizeOfList = del(list, index, size);
            size = sizeOfList;
            printf("Updated array is :\n");
            printList(list, size);
            break;
        case 3:
            printf("Enter the value you want to search\n\t");
            scanf("%d", &value);
            result = search(list, value, size);
            if (result == -1 || size == 0)
                printf("Element not found or array is empty");
            else
                printf("Element found on index: %d", result);
            break;
        case 4:

            printList(list, size);
            break;
        case 5:
            printf("press enter to exit...");

            exit(0);
            break;
        default:

            printf("Wrong choice");
            break;
        }
        printf("\nPress enter to continue");
    } while (1);
    return 0;
}
