#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push() {
    int value;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value you want to push: ");
    scanf("%d", &value);
    if (newNode == NULL) {
	printf("Memory allocation failed.\n");
	return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed to stack.\n", value);
}

void pop() {
    if (isEmpty()) {
	printf("Stack is UnderFlow !!!!!\n");
	return;
    } else {
	struct node *temp = top;
	int poppedValue = top->data;
	top = top->next;
	free(temp);
	printf("Element %d popped from stack.\n", poppedValue);
    }
}

void display() {
    if (isEmpty()) {
	printf("Stack is empty.\n");
	return;
    } else {
	struct node *temp = top;
	while (temp != NULL) {
	    printf("%d -> ", temp->data);
	    temp = temp->next;
	}
	printf("NULL\n");
    }
}

int main() {
    clrscr();
    int ch;
    while (1) {
	printf("\nStack Operations: ");
	printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	switch (ch) {
	    case 1:
		push();
		break;
	    case 2:
		pop();
		break;
	    case 3:
		display();
		break;
	    case 4:
		return 0;
	    default:
		printf("Enter a valid choice.\n");
	}
    }
    return 0;
}
