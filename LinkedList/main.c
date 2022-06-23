#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#pragma warning(disable:4477)

#include "DoublyLinkedList.h"

void printList(MyLinkedList* obj)
{
	obj->iter = obj->head;
	int temp;

	while (obj->iter->next != NULL)
	{
		obj->iter = obj->iter->next;
		printf("%d ", obj->iter->val);
	}
	printf("\n");
}

int main(void)
{
	MyLinkedList* obj = myLinkedListCreate();

	myLinkedListAddAtHead(obj, 1);
	myLinkedListAddAtHead(obj, 5);
	myLinkedListAddAtHead(obj, 6); // 6->5->1

	//printList(obj);
	
	myLinkedListAddAtTail(obj, 3);
	myLinkedListAddAtTail(obj, 7);
	myLinkedListAddAtTail(obj, 2); // 6->5->1->3->7->2

	//printList(obj);

	myLinkedListAddAtIndex(obj, 1, 2); // 6->2->5->1->3->7->2
	myLinkedListAddAtIndex(obj, 3, 2); // 6->2->5->2->1->3->7->2
	myLinkedListAddAtIndex(obj, 10, 2); // error

	//printList(obj);

	printf("%d\n",myLinkedListGet(obj, 0)); // return 6
	printf("%d\n",myLinkedListGet(obj, 3)); // return 2
	printf("%d\n",myLinkedListGet(obj, 4)); // return 1

	myLinkedListDeleteAtIndex(obj, 1);	// 6->5->2->1->3->7->2
	myLinkedListDeleteAtIndex(obj, 1);	// 6->2->1->3->7->2
	myLinkedListDeleteAtIndex(obj, 1);	// 6->1->3->7->2

	//printList(obj);

	printf("%d\n", myLinkedListGet(obj, 3)); //return 7

	myLinkedListFree(obj);

	return 0;
}