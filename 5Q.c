#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue Operation
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Dequeue Operation
void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Peek Operation
void peek() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front Element: %d\n", queue[front]);
    }
}

// Display Operation
void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        int i = front;
        printf("Queue Elements: ");

        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}