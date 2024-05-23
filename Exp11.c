#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        printf("Element dequeued successfully.\n");
    }
}

int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1; // Return a default value indicating an empty queue
    } else {
        return q->front->data;
    }
}

int main() {
    struct Queue* q = createQueue();
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                int data;
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("Front element: %d\n", peek(q));
                break;
            case 4:
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