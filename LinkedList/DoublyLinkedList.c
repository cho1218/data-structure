#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DoublyLinkedList.h"

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
	MyLinkedList* NewLL = (MyLinkedList*)malloc(sizeof(MyLinkedList));

	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	NewLL->head = NewNode;
	NewLL->tail = NewNode;
	NewLL->dataCount = 0;
	NewLL->iter = NewLL->head;

	printf("New Linked List is created.\n");
	return NewLL;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1.
*/
int myLinkedListGet(MyLinkedList* obj, int index)
{
	if (index >= obj->dataCount)
		return -1;
	
	int iterIndex = -1;
	obj->iter = obj->head;

	while (obj->iter->next != NULL)
	{
		obj->iter = obj->iter->next;
		iterIndex++;
		if (iterIndex == index)
			return obj->iter->val;
	}
}

/** Add a node of value val before the first element of the linked list. After the insertion,
the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
	if (obj->dataCount > 1000 || val > 1000 || val < 0)
	{
		printf("data cannot be added\n");
		return;
	}
	
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	if (obj->dataCount == 0)
	{
		NewNode->val = val;
		obj->head->next = NewNode;
		obj->tail = NewNode;
		NewNode->prev = obj->head;
	}
	else
	{
		NewNode->val = val;
		NewNode->next = obj->head->next;
		NewNode->prev = obj->head;

		obj->head->next = NewNode;
		NewNode->next->prev = NewNode;
	}

	obj->dataCount++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
	if (obj->dataCount > 1000 || val > 1000 || val < 0)
	{
		printf("data cannot be added\n");
		return;
	}
	
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	NewNode->val = val;
	obj->tail->next = NewNode;
	NewNode->prev = obj->tail;
	NewNode->next = NULL;
	
	obj->tail = NewNode;
	obj->dataCount++;

}

/** Add a node of value val before the index-th node in the linked list. If index equals to
the length of linked list, the node will be appended to the end of linked list. If index is
greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
	if (obj->dataCount > 1000 || index > 1000 || index < 0 || val > 1000 || val < 0)
	{
		printf("data cannot be added\n");
		return;
	}
	
	if (index >= obj->dataCount)	// index is greater than length
	{
		printf("%d -> insertion fail\n", val);
	}
	else if (index == obj->dataCount)	// val should be inserted at end
	{
		myLinkedListAddAtTail(obj, val);
	}
	else if (index == 0)	// val should be inserted at head
	{
		myLinkedListAddAtHead(obj, val);
	}
	else
	{
		int iterIndex = -1;
		obj->iter = obj->head;
		Node* temp = NULL;

		while (obj->iter->next != NULL)
		{
			obj->iter = obj->iter->next;
			iterIndex++;
			if (iterIndex == index)
			{
				temp = obj->iter->prev;
				break;
			}
		}

		Node* NewNode = (Node*)malloc(sizeof(Node));
		memset(NewNode, 0, sizeof(Node));

		NewNode->val = val;
		temp->next = NewNode;
		NewNode->next = obj->iter;
		obj->iter->prev = NewNode;
		NewNode->prev = temp;

		obj->dataCount++;
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
	if (index < 0)
	{
		printf("data cannot be added\n");
		return;
	}
	
	if (index >= obj->dataCount)
		printf("No data at index %d\n", index);
	else if (obj->dataCount == 0)
		printf("No data in Linked List\n");
	else
	{
		int iterIndex = -1;
		obj->iter = obj->head;
		Node* temp = NULL;

		while (obj->iter->next != NULL)
		{
			obj->iter = obj->iter->next;
			iterIndex++;
			if (iterIndex == index)
			{
				temp = obj->iter->prev;
				break;
			}
		}

		temp->next = obj->iter->next;
		obj->iter->next->prev = temp;
		
		free(obj->iter);
		obj->dataCount--;
	}
}

void myLinkedListFree(MyLinkedList* obj)
{
	obj->iter = obj->head;
	Node* temp = NULL;

	while (obj->iter->next != NULL)
	{
		temp = obj->iter;
		obj->iter = obj->iter->next;
		free(temp);
	}
	free(obj->iter);
	free(obj);
}
