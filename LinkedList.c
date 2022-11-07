#include <stdio.h>
#include<stdlib.h>
#include "LinkedList.h"
/*******************************************************************
 * Implementation of a generic linked list.
 *  Implementing only the insertFirst and remove first methods to use to implement the undo method.
 * ***********************************************************************/

LinkedList* createLinkedList()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll ->head = NULL;
    ll -> tail = NULL;   /* Implementing a doubly linked list */
    ll-> count = 0; /* To keep track of the number of nodes added to the list */
    return ll;

    
}
/********************************************************************
 * Name : insertStart 
 * Import : List (LinkedList) pData (*void)
 * Export : None 
 * Purpose : To insert an element to the linked list.
 * ***********************************************/
void insertStart(LinkedList *list,void* pdata)
{
    LLnode *newNode = NULL;

    /* Create a new list node */
    newNode = (LLnode *)malloc(sizeof(LLnode)); /* manually allocate the size of the list node */
    /*Assign the passed in data as the data in the node */
    newNode -> data = pdata;
    
    newNode -> next = NULL;

/* if the list head is null means there is no data in the list */
    if(list -> head == NULL)
    {
        /* both the head and tail become the new node. */
        list -> head = newNode;
        list -> tail = newNode;

    }else    
    {
        /* if the list has elements already the next of the new node becomes the initial head */
        newNode -> next = list -> head;
        list -> head = newNode; /* the new node becomes the head */
    }

    list -> count++; /* increase the number of nodes */

}

void* removeStart(LinkedList *list)
{
    void* temp = NULL;  /* to retieve the data */
    LLnode *deleteNode = NULL; /* create a temporary  LLnode variable to pass the element */

/* if the list has elements */
    if(list -> head != NULL)
    {
        /* assign the head value to the temp deleteNode */
        deleteNode = list -> head; 
        temp = deleteNode -> data; /* Assign the value in the head to the delete node */
        list -> head = list -> head -> next; /* the head of the list now is the initial next */

        /* Remove the delete node */
        free(deleteNode);
        deleteNode = NULL; 

        list -> count --; /* decrease the number of elements in the list */
    }

    return temp;
}

void printLinkedList(LinkedList* list, print* printList)
{
    LLnode* currNode = NULL;

    if(list -> count == 0)
    {
        printf("None to show");
    }
    else
    {
        currNode = list -> head;

        while(currNode != NULL)
        {
           printf(" %s \n",(*printList)(currNode -> data));
           currNode = currNode -> next;
        }
    }
}


void freeLinkedList(LinkedList* list, freeList* freeData)
{
    LLnode* currNode;
    LLnode* upComing;
    if(list -> count != 0)
    {
        currNode = list -> head;
        while(currNode != NULL)
        {
            upComing = currNode-> next;
            (*freeData)(currNode -> data);
            free(currNode);
            currNode = upComing;


        }
    }

    free(list);
    list = NULL;

}

 /*void testPrint(LinkedList* list)
{
   

    LLnode* curr;
    curr = list->head
    while (curr != NULL)
    {
        printf("%d \n",*(int*)curr->data);
        curr = curr->next;
    }
    printf("\n"); 
 } */


