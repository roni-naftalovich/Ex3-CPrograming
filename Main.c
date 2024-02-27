#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

#define MAX_INPUT 100

int main()
{
    int size;
    struct StrList *list = StrList_alloc();
    int choice;
    char *str;
    int index;

    scanf("%d", &choice);
    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            scanf(" %d", &size);
            str = (char *)malloc(MAX_INPUT * size);
            scanf(" %[^\n]s", str);
            str = realloc(str, strlen(str));
            createList(list, size, str);
            free(str);
            break;
        case 2:
            str = (char *)malloc(MAX_INPUT);
            scanf(" %d", &index);
            scanf(" %s", str);
            insertAtIndex(list, str, index);
            free(str);
            break;
        case 3:
            printList(list);
            break;
        case 4:
            printListLength(list);
            break;
        case 5:
            scanf(" %d", &index);
            printElementAtIndex(list, index);
            break;
        case 6:
            numOfChars(list);
            break;
        case 7:
            str = (char *)malloc(MAX_INPUT);
            scanf(" %s", str);
            numOfShows(list, str);
            free(str);
            break;
        case 8:
            str = (char *)malloc(MAX_INPUT);
            scanf(" %s", str);
            removeElement(list, str);
            break;
        case 9:
            scanf(" %d", &index);
            removeElementAt(list, index);
            break;
        case 10:
            reverse(list);
            break;
        case 11:
            StrList_free(list);
            break;
        case 12:
            sortList(list);
            break;
        case 13:
            if (isSorted(list) == 1)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            break;
        case 0:
            StrList_free(list);
            free(list);
        }
        scanf(" %d", &choice);
    }
}
