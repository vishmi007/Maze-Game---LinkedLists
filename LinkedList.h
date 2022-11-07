#ifndef LINKEDLIST_H
#define  LINKEDLIST_H
typedef struct LinkedListNode 
{
    void* data;
    struct LinkedListNode * next;

}LLnode;

typedef struct 
{
    LLnode * head;
    LLnode * tail;
    int count ;

}LinkedList;

typedef struct 
{
    int* arr;
    int length;
}Intarray;


typedef char* (*print)(void* );
typedef void (*freeList) (void*);
 
LinkedList* createLinkedList();
void insertStart(LinkedList *list,void* pdata);
void* removeStart(LinkedList *list);
void printLinkedList(LinkedList* list, print* printList);
void freeLinkedList(LinkedList* list, freeList* freeData);
void testPrint(LinkedList* list);

#endif
