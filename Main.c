#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.c"
#include "StrList.h"

char* extractWord(){
   char* str = (char*)malloc(sizeof(char));
   *str = '\0';
   char c = getchar(); 
   while(c!=' '&&c!='\n'&&c!=EOF){
      int len = strlen(str); 
      str = (char*)realloc(str,len+2);  
      if (str == NULL) {
         printf("Memory allocation failed\n");
         exit(EXIT_FAILURE);
      }
      str[len] = c;                      
      str[len+1] = '\0';                 
      c = getchar();                      
   }

   return str;  
}



 int main() {
    StrList *list = StrList_alloc();
    char c;
    int choice = -1;
    scanf("%d", &choice);

    while (choice != 0) {

        switch (choice) {
            case 1: {
                int length = 0;
                if (scanf("%d", &length) != 1) {
                    printf("Invalid input\n");
                    break;
                }
                while((c=getchar())!='\n'&&c!=EOF);
                for (int i = 0; i < length; i++) {
                    char *str = extractWord();
                    StrList_insertLast(list, str);
                }
                break;
            }
            case 2: {
                int index = -1;
                scanf("%d", &index);
                if (index < 0 || index > StrList_size(list)) {
                    printf("Index out of bounds\n");
                    break;
                }
                while((c=getchar())!='\n'&&c!=EOF);
                char *str = extractWord();
                StrList_insertAt(list, str, index);
                break;
            }
            case 3:
                StrList_print(list);
                break;
            case 4: {
                int size = StrList_size(list);
                printf("%d\n", size);
                break;
            }
            case 5: {
                int index = -1;
                scanf("%d", &index);
                if (index < 0 || index > StrList_size(list)) {
                    printf("Index out of bounds\n");
                    continue;
                }
                StrList_printAt(list, index);
                break;
            }
            case 6:
                printf("%d\n", StrList_printLen(list));
                break;
            case 7: {
                while((c=getchar())!='\n'&&c!=EOF);
                char *str = extractWord();
                int count = StrList_count(list, str);
                printf("%d\n", count);
                break;
            }
            case 8: {
                while((c=getchar())!='\n'&&c!=EOF);
                char *str = extractWord();
                StrList_remove(list, str);
                break;
            }
            case 9: {
                int index = -1;
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            }
            case 10:
                StrList_reverse(list);
                break;
            case 11:
                while (StrList_size(list)) {
                    StrList_removeAt(list, 0);
                }
                break;
            case 12:
                StrList_sort(list);
                break;
            case 13:
                if (StrList_isSorted(list) == 1) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        scanf("%d", &choice);
    }
    
    StrList_free(list);
    
    return 0;
}
