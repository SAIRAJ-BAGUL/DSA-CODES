#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;
    if (front == NULL) {
        rear = newNode;
    } else {
        front->prev = newNode;
    }
    front = newNode;
    printf("Inserted at front: %d\n", value);
}

void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted from front: %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty\n");
         return;
    }
    struct Node* temp = rear;
    printf("Deleted from rear: %d\n", temp->data);
    rear = rear->prev;
    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    free(temp);
}
void display() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
    printf("\n--- Deque Menu ---\n");
    printf("1. Insert Front\n");
    printf("2. Insert Rear\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}