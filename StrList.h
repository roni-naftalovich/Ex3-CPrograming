#include <stdlib.h>

struct StrList;
typedef struct StrList StrList;

StrList* StrList_alloc();
struct Node* create_node(const char *str);
void StrList_free(StrList* StrList);
size_t StrList_size(const StrList* StrList);
void insertElement (StrList *StrList , const char* data);
void insertAtIndex(struct StrList *list, const char *str, int index);
void printList(const struct StrList* list);
int printListLength(const struct StrList *list);
void printElementAtIndex(const struct StrList *list, int index);
void numOfChars(const struct StrList *list);
int numOfShows(const struct StrList *list, const char* data);
void removeElement(struct StrList *list, const char* data);
void removeElementAt(struct StrList *list, int index);
void reverse(struct StrList *list);
void sortList(struct StrList *list);
int isSorted(struct StrList *list);
void createList(StrList* StrList, int length, char* str);