#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

/* Node */
typedef struct node
{
	int val;
	struct node* prev;
	struct node* next;
} Node;

/* Linked List */
typedef struct linkedlist
{
	Node* head;
	Node* tail;

	int dataCount;
	Node* iter;
} MyLinkedList;

/* CREATE */
MyLinkedList* myLinkedListCreate();

/* GET*/
int myLinkedListGet(MyLinkedList* obj, int index);

/* ADD */
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);

/* DELETE*/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);

/* FREE */
void myLinkedListFree(MyLinkedList* obj);

#endif
