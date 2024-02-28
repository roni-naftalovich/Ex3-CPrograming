#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.c"
#include "StrList.h"

#define MAX_INPUT 100



int main()
{
    StrList *list = StrList_alloc();
    int choice;
    char *str;
    int index;
    int length;

    scanf("%d", &choice);
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
          str = malloc(sizeof(char) * MAX_INPUT);
            scanf("%d ", &length);
            fgets(str, MAX_INPUT, stdin);

            int j = 0;

            for (int i = 0; i < length; i++)
            {
                char *substring;
                while (str[j] != ' ' && j < strlen(str))
                {
                    j++;
                }

                substring = (char *)malloc(j + 1);
                strncpy(substring, str, j);
                substring[j] = '\0';
                StrList_insertLast(list, substring);

                j++;
                str += j;
                j = 0;

            }
            list->length= length;
            break;
        case 2:
            scanf("%d %s", &index, str);
            StrList_insertAt(list, str, index);
            break;
        case 3:
            StrList_print(list);
            break;
        case 4:
            printf("%zu\n", StrList_size(list));
            break;
        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;
        case 6:
            printf("%d\n", StrList_printLen(list));
            break;
        case 7:
            scanf("%s", str);
            printf("%d\n", StrList_count(list, str));
            break;
        case 8:
            scanf("%s", str);
            StrList_remove(list, str);
            break;
        case 9:
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            StrList_free(list);
            exit(EXIT_SUCCESS);
            break;
        case 12:
            StrList_sort(list);
            break;
        case 13:
            if (StrList_isSorted(list) == 1)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        scanf("%d", &choice);
    }

    return 0;
}