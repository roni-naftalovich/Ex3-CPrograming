#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

//new
struct Node
{
    char *data;
    struct Node *next;
};

struct StrList
{
    struct Node *head;
    size_t length;
};

// Function to allocate memory for a new StrList structure
 StrList* StrList_alloc(){
    // Allocate memory for a new _StrList structure using malloc
    StrList* new_list = (StrList*)malloc(sizeof(StrList));

    // Check if memory allocation was successful
    if (new_list == NULL) {
        perror("Memory allocation failed");
        // Exit the program with failure status
        exit(EXIT_FAILURE);
    }

    // Initialize the list size to 0
    new_list->length = 0;
    // Initialize the head pointer to NULL
    new_list->head = NULL;

    
    return new_list;
}

struct Node* create_node(const char *str){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    (*new_node).data = strdup(str);
    (*new_node).next = NULL;

    return new_node;
}

void StrList_free(StrList* StrList){
    if (StrList == NULL)
    {
        return;
    }
    
    struct Node *current = StrList->head;
    struct Node *next = NULL;
    StrList->head = NULL;
    
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    StrList->length = 0;
}

size_t StrList_size(const StrList* StrList){
    return StrList->length;
}
void insertElement(StrList* list, const char* data) {
if (list == NULL)
    {
        return;
    }
    
    if (list->head == NULL)
    {
        list->head = create_node(data);
    }
    
    else
    {
        struct Node *current = list->head;
        struct Node *new_node = create_node(data);

        while (current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = new_node;
    }
   list->length++;
}

// Function to insert a new element containing a string at a specified index in the list
void insertAtIndex(struct StrList *list, const char *str, int index) {
    // Check if the index is valid
    if (index > list->length) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the string and copy it into the new node
    new_node->data = strdup(str);
    if (new_node->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }

    // If the list is empty or index is 0, insert at the beginning
    if (index == 0 || list->head == NULL) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        // Traverse the list to find the node at the previous index
        struct Node *prev = NULL;
        struct Node *current = list->head;
        for (size_t i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        // Insert the new node at the specified index
        prev->next = new_node;
        new_node->next = current;
    }

    // Increment the size of the list
    list->length++;
}

void printList(const struct StrList* list) {
    if (list == NULL || list->head == NULL) {
        printf("\n");
        return;
    }
   

    struct Node *current = list->head;

    // Traverse the list and print each element
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print the length of the list
int printListLength(const struct StrList *list) {
    if (list == NULL) {
        printf("0\n");
        return 0;
    }

    printf("%zu\n", list->length);
    return 1;
}

void printElementAtIndex(const struct StrList *list, int index) {
    if (list == NULL || list->head == NULL) {
        printf("\n");
        return;
    }

    if (index <0) {
        return;
    }

    struct Node *current = list->head;
    int currentIndex = 0;
    while (current != NULL) {
        if (currentIndex-1 == index) {
            printf("%s\n", current->data);
            return;
        }
        current = current->next;
        currentIndex++;
    }
}

void numOfChars(const struct StrList *list) {
    if (list == NULL || list->head == NULL) {
        printf("0\n");
        return;
    }

    int count = 0;
    struct Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->data, data) ==0)
        current = current->next;
    }
    printf("%d\n" , count);
}

int numOfShows(const struct StrList *list, const char* data) {
    if (list == NULL || list->head == NULL) {
        printf("0\n");
        return 0;
    }

    int count = 0;
    struct Node *current = list->head;
    while (current != NULL) {
       if(strcmp(current->data, data)==0){
        count++;
       }
        current = current->next;
    }
    printf("%d\n" , count);
    return count;
}

void removeElement(struct StrList *list, const char* data) {
     int num = numOfShows(list, data);
    if (list == NULL || list->head == NULL || num==0) {
        return;
    }
        struct Node *current= list->head;
        struct Node *last = current;
        struct Node *temp;
        while (num != 0)
        {
            if (strcmp(current->data, data) == 0)
            {
                if (last == current)
                {
                    list->head = current->next;
                    last = list->head;
                    temp = current;
                    current = list->head;

                    free(temp->data);
                    free(temp);
                }
                else
                {
                    last->next = current->next;
                    temp = current;
                    current = last->next;

                    free(temp->data);
                    free(temp);
                }

                num--;
            }
            else
            {
                last = current;
                current = current->next;
            }
        }
        list-> length--;
    }


void removeElementAt(struct StrList *list, int index){
       if (list == NULL || list->head == NULL|| index<0) {
        return;
    }
    int i;
    struct  Node *current= list->head;
    for(i=0;i<index; i++){
        current= current->next;
    }
    struct Node *node = current->next;
    current->next= node->next;

    free(node->data);
    free(node);
    
    
    }

void reverse(struct StrList *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }

    struct Node *prevNode = NULL;
    struct Node *currentNode = list->head;
    struct Node *nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    list->head = prevNode;
}

void sortList(struct StrList *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        // If the list is empty or has only one node, no need to sort
        return;
    }

    struct Node *currentNode;
    struct Node *nextNode;
    char *tempData;

    for (currentNode = list->head; currentNode->next != NULL; currentNode = currentNode->next) {
        for (nextNode = currentNode->next; nextNode != NULL; nextNode = nextNode->next) {
            if (strcmp(currentNode->data, nextNode->data) > 0) {
                tempData = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = tempData;
            }
        }

    }
}

int isSorted(struct StrList *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        // If the list is empty or has only one node
        return 1;
    }

    struct Node *currentNode = list->head;

    while (currentNode->next != NULL) {
        if (strcmp(currentNode->data, currentNode->next->data) > 0) {
            return 0;
        }
        currentNode = currentNode->next;
    }

    // If the loop completes without finding any out-of-order elements, the list is sorted
    return 1;
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
        strncpy(substring, str, j);
        substring[j] = '\0';
        insertElement(StrList, substring);
        
        j++;
        str += j;
        j = 0;
        free(substring);
    }
    
}
