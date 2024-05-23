#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (pq->front == NULL || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        struct Node* temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
        printf("Element dequeued successfully.\n");
    }
}

int peek(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
        return -1; // Return a default value indicating an empty queue
    } else {
        return pq->front->data;
    }
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();
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
                int data, priority;
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(pq, data, priority);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                printf("Front element: %d\n", peek(pq));
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