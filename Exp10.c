#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data) {
    struct Node* newNode = createNode(data);
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
        printf("Element popped successfully.\n");
    }
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return top->data;
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                int data;
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printf("\n\n");
    }
    return 0;
}