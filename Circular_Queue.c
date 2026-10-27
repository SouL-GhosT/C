#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Maximum queue size

// Circular Queue structure
struct CircularQueue 
{
    int arr[MAX];
    int front;
    int rear;
};

// Create and initialize circular queue
struct CircularQueue* createCircularQueue() 
{
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if circular queue is empty (using front pointer only)
int isEmpty(struct CircularQueue* q) 
{
    if (q->front == -1) 
    {
        return 1;  // Empty
    }
    return 0;  // Not empty
}

// Check if circular queue is full (using front and rear pointers with modulo)
int isFull(struct CircularQueue* q) 
{
    // Queue is full when next position of rear equals front
    // (rear + 1) % MAX == front
    if ((q->rear + 1) % MAX == q->front) 
    {
        return 1;  // Full
    }
    return 0;  // Not full
}

// Insert element at rear (Enqueue) - with circular wrapping
void insert(struct CircularQueue* q, int value) {
    if (isFull(q)) 
    {
        printf("CIRCULAR QUEUE IS FULL!\n");
        return;
    }
    
    // If queue is empty, set front to 0
    if (isEmpty(q)) 
    {
        q->front = 0;
    }
    
    // Move rear pointer circularly and add element
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    
    printf("Element %d inserted successfully\n", value);
    printf("Rear moved to index: %d\n", q->rear);
}

// Delete element from front (Dequeue) - with circular wrapping
int delete(struct CircularQueue* q) 
{
    if (isEmpty(q)) 
    {
        printf("CIRCULAR QUEUE IS EMPTY!\n");
        printf("Nothing to delete.\n");
        return -1;
    }
    
    int value = q->arr[q->front];
    
    // If only one element in queue, reset both front and rear
    if (q->front == q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    } 
    else 
    {
        // Move front pointer circularly
        q->front = (q->front + 1) % MAX;
    }
    
    printf("Element %d deleted successfully\n", value);
    printf("Front moved to index: %d\n", q->front == -1 ? -1 : q->front);
    return value;
}

// Display all elements in circular queue
void display(struct CircularQueue* q) 
{
    printf("CIRCULAR QUEUE ELEMENTS\n");
    if (isEmpty(q)) 
    {
        printf("Circular Queue is EMPTY! No elements to display.\n\n");
        return;
    }
    printf("Front -> ");
    
    int i = q->front;
    while (1)
    {
        printf("[%d] ", q->arr[i]);
        if (i == q->rear)
        break;
        i = (i + 1) % MAX;
    }
    printf("<- Rear\n\n");
}

// Display main menu
void displayMenu() 
{
    printf("CIRCULAR QUEUE OPERATIONS MENU\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Display Queue Elements\n");
    printf("4. Exit Program\n");
    printf("\nEnter your choice (1-4): ");
}

int main() 
{
    struct CircularQueue* q = createCircularQueue();
    int choice, value;
    printf("CIRCULAR QUEUE IMPLEMENTATION USING ARRAY\n");
    
    while (1) 
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: 
            {
                printf("\nEnter the element to insert: ");
                scanf("%d", &value);
                insert(q, value);
                break;
            }
            
            case 2: 
            {
                delete(q);
                break;
            }

            case 3: 
            {
                display(q);
                break;
            }
            
            case 4: 
            {
                printf("Thank you for using Circular Queue!\n");
                printf("Program terminated successfully.\n");
                free(q);
                return 0;
            }
            
            default: 
            {
                printf("Invalid choice! Please enter a number between 1 and 11.\n");
            }
        }
    }
    
    return 0;
}