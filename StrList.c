#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

typedef struct _node {
    const char* data;
    struct _node* next;
} Node;

struct _StrList {
    Node* head;
    size_t length;
};

StrList* StrList_alloc() {
    StrList* new_list = (StrList*)malloc(sizeof(StrList));
    if (new_list == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_list->length = 0;
    new_list->head = NULL;

    return new_list;
}

void StrList_free(StrList* StrList) {
    if (StrList == NULL) {
        return;
    }

    Node* current = StrList->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free((char*)current->data);
        free(current);
        current = next;
    }

    free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    return StrList->length;
}

Node *Node_alloc(const char *data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p != NULL)
    {
        p->data = data;
        p->next = next;
    }
    return p;
}
void createList(StrList* StrList, int length, char* str){
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        char* substring;
        while (str[j] != ' ' && j < strlen(str))
        {
            j++;
        }
        
        substring = (char*)malloc(j+1);
        printf("%s\n" , substring);
        strncpy(substring, str, j);
        substring[j] = '\0';

        
        Node* new_node = Node_alloc(substring,NULL);
        
    if (new_node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }


    if (StrList->head == NULL) {
        StrList->head = new_node;
    } else {
        Node* current = StrList->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    StrList->length++;
        j++;
        str += j;
        j = 0;
        free(substring);
    }
    
}


void StrList_insertLast(StrList* StrList, const char* data) {
    if (StrList == NULL) {
        return;
    }
    Node* new_node = Node_alloc(data,NULL);

    if (StrList->head == NULL) {
        StrList->head = new_node;
        
    } else {
        Node* current = StrList->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    StrList->length++;
}

void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if (StrList == NULL || index < 0 || index > StrList->length) {
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = strdup(data);
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = StrList->head;
        StrList->head = new_node;
    } else {
        Node* current = StrList->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    StrList->length++;
}

char* StrList_firstData(const StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL) {
        return NULL;
    }
    return (char*)StrList->head->data;
}

void StrList_print(const StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* current = StrList->head;
    if (current != NULL)
    {
        while (current->next != NULL)
        {
            printf("%s ", current->data);
            current = current->next;
        }
    
        printf("%s\n", current->data);
    }}

void StrList_printAt(const StrList* StrList, int index) {
    if (StrList == NULL || index < 0 || index >= StrList->length) {
        printf("Invalid index\n");
        return;
    }

    Node* current = StrList->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    printf("%s\n", current->data);
}

int StrList_printLen(const StrList* StrList) {
   
    int countChars = 0;
    Node *temp = StrList->head;

    while (temp !=NULL)
    {
        int sizeOfString = strlen(temp->data);
        countChars += sizeOfString;
        temp = temp->next;
    }

    return countChars;
}

int StrList_count(StrList* StrList, const char* data) {
    if (StrList == NULL || data == NULL) {
        return 0;
    }

    int count = 0;
    Node* current = StrList->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void StrList_remove(StrList* StrList, const char* data) {
    if (StrList == NULL || data == NULL) {
        return;
    }

    Node* current = StrList->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                StrList->head = current->next;
                free((char*)current->data);
                free(current);
                current = StrList->head;
            } else {
                prev->next = current->next;
                free((char*)current->data);
                free(current);
                current = prev->next;
            }
            StrList->length--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index) {
    if (StrList == NULL || index < 0 || index >= StrList->length) {
        return;
    }

    Node* current = StrList->head;
    Node* prev = NULL;

    if (index == 0) {
        StrList->head = current->next;
        free((char*)current->data);
        free(current);
    } else {
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free((char*)current->data);
        free(current);
    }

    StrList->length--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    if (StrList1 == NULL || StrList2 == NULL) {
        return 0;
    }

    if (StrList1->length != StrList2->length) {
        return 0;
    }

    Node* current1 = StrList1->head;
    Node* current2 = StrList2->head;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return 1;
}

StrList* StrList_clone(const StrList* StrList) {
    if (StrList == NULL) {
        return NULL;
    }

    struct _StrList* new_list = StrList_alloc();
    Node* current = StrList->head;

    while (current != NULL) {
        StrList_insertLast(new_list, current->data);
        current = current->next;
    }

    return new_list;
}

void StrList_reverse(StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL || StrList->head->next == NULL) {
        return;
    }

    Node* prevNode = NULL;
    Node* currentNode = StrList->head;
    Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    StrList->head = prevNode;
}

void StrList_sort(StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL || StrList->head->next == NULL) {
        // If the list is empty or has only one node, no need to sort
        return;
    }

    Node* currentNode;
    Node* nextNode;
    char* tempData;

    for (currentNode = StrList->head; currentNode->next != NULL; currentNode = currentNode->next) {
        for (nextNode = currentNode->next; nextNode != NULL; nextNode = nextNode->next) {
            if (strcmp(currentNode->data, nextNode->data) > 0) {
                tempData = (char*)malloc(strlen(currentNode->data) + 1);
                strcpy(tempData, currentNode->data);
                free((char*)currentNode->data);
                currentNode->data = (char*)malloc(strlen(nextNode->data) + 1);
                strcpy((char*)currentNode->data, nextNode->data);
                free((char*)nextNode->data);
                nextNode->data = (char*)malloc(strlen(tempData) + 1);
                strcpy((char*)nextNode->data, tempData);
                free(tempData);
            }
        }
    }
}

int StrList_isSorted(StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL || StrList->head->next == NULL) {
        // If the list is empty or has only one node
        return 1;
    }

    Node* currentNode = StrList->head;

    while (currentNode->next != NULL) {
        if (strcmp(currentNode->data, currentNode->next->data) > 0) {
            return 0;
        }
        currentNode = currentNode->next;
    }

    // If the loop completes without finding any out-of-order elements, the list is sorted
    return 1;
}
