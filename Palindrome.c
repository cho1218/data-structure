#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#pragma warning(disable:4477)

#define MAX_STACK_SIZE 20

char numStack[MAX_STACK_SIZE];
int top;

void initStack()
{
	memset(numStack, '\0', sizeof(numStack));
	top = -1;
}

void push(char item)
{
	numStack[++top] = item;
}

char pop()
{
	return numStack[top--];
}

int main(void) {
	char item[20];	// can accept 20 alphabets
	initStack();
	char temp[20];
	memset(temp, '\0', sizeof(temp));

	// input
	printf("Enter the query for checking the palindrome : ");
	fgets(item, sizeof(item), stdin);
	item[strlen(item) - 1] = '\0';

	// push characters in item array
	for (int i = 0; i < strlen(item); i++)
	{
		push(item[i]);
	}

	// pop all elements in stack
	for (int j = 0; j < strlen(numStack); j++)
	{
		temp[j] = pop();
	}

	// compare item array and temp array
	// if they are same, strcmp() will return 0
	if (strcmp(item, temp)==0)
	{
		printf("It is a palindrome!\n");
	}
	else
	{
		printf("It is not a palindrome!\n");
	}
	return 0;
}