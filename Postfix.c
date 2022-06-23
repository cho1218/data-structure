#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#pragma warning(disable:4477)

#define MAX_STACK_SIZE 20

int numStack[MAX_STACK_SIZE];
int top = -1;

void push(int item)
{
	numStack[++top] = item;
}

int pop()
{
	return numStack[top--];
}

int main(void)
{
	char input[20];	// can accept 20 oper
	char* e;

	// input
	printf("Enter the expression : ");
	scanf("%s", input);
	e = input;

	while (*e != '\0')
	{
		// if *e is a digit
		if (isdigit(*e))
		{
			int result = *e - 48;
			push(result);
		}
		else
		{
			int num1, num2, result;
			num1 = pop();
			num2 = pop();

			// oprators
			switch (*e)
			{
			case '+':
				result = num2 + num1;
				break;
			case '-':
				result = num2 - num1;
				break;
			case '*':
				result = num2 * num1;
				break;
			case'/':
				result = num2 / num1;
				break;
			default:
				printf("input error!\n");
				break;
			}
			push(result);
		}
		e++;
	}
	// if there is only one item

	if (top == 0)
	{
		printf("The result of expression %s = %d\n", input, pop());
	}
	else
	{
		printf("error!\n");
	}

}