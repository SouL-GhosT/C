#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Maximum queue size

// Queue structure
struct Queue 
{
    int arr[MAX];
    int front;
    int rear;
};

// Create and initialize queue
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if queue is empty (using front pointer only)
int isEmpty(struct Queue* q) 
{
    if (q->front == -1) 
    {
        return 1;  // Empty
    }
    return 0;  // Not empty
}

// Check if queue is full (using front and rear pointers)
int isFull(struct Queue* q) 
{
    // Queue is full when rear reaches the end and front is at or near beginning
    // OR when we have filled MAX elements
    if (q->rear == MAX - 1) 
    {
        if (q->front == 0 || q->front == -1) {
            return 1;  // Full
        }
    }
    return 0;  // Not full
}

// Insert element at rear (Enqueue)
void insert(struct Queue* q, int value) 
{
    if (isFull(q)) 
    {
        printf("QUEUE IS FULL! Cannot insert.\n");
        return;
    }
    
    // If queue is empty, set front to 0
    if (isEmpty(q)) 
    {
        q->front = 0;
    }
    
    // Move rear pointer and add element
    q->rear++;
    q->arr[q->rear] = value;
    printf("Element %d inserted successfully\n", value);
}

// Delete element from front (Dequeue)
int delete(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("QUEUE IS EMPTY! Nothing to delete.\n");
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
        // Move front pointer forward
        q->front++;
    }
    
    printf("Element %d deleted successfully\n", value);
    return value;
}

// Display all elements in queue
void display(struct Queue* q) 
{
    printf("QUEUE ELEMENTS\n");
    
    if (isEmpty(q)) 
    {
        printf("Queue is EMPTY! No elements to display.\n\n");
        return;
    }
    
    printf("Front → ");
    for (int i = q->front; i <= q->rear; i++) 
    {
        printf("[%d] ", q->arr[i]);
    }
    printf("← Rear\n\n");
}

// Display main menu
void displayMenu() 
{
    printf("QUEUE OPERATIONS MENU\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Display Queue Elements\n");
    printf("4. Exit Program\n");
    printf("\nEnter your choice (1-4): ");
}

int main() 
{
    struct Queue* q = createQueue();
    int choice, value;
    
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║         QUEUE IMPLEMENTATION USING ARRAY                       ║\n");
    printf("║     (Using only Front and Rear Pointers, No Size Variable)     ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n\n"); 
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &value);
                insert(q, value);
                break;
            
            case 2:
                delete(q);
                break;
            
            case 3:
                checkEmpty(q);
                break;
            
            case 4:
                checkFull(q);
                break;
            
            case 5:
                display(q);
                break;
            
            case 6:
                peekFront(q);
                break;
            
            case 7:
                peekRear(q);
                break;
            
            case 8:
                displayQueueInfo(q);
                break;
            
            case 9:
                showPointerExplanation();
                break;
            
            case 10:
                printf("\n╔════════════════════════════════════════╗\n");
                printf("║  ✓ Thank you for using Queue Program!  ║\n");
                printf("║  Program terminated successfully.      ║\n");
                printf("╚════════════════════════════════════════╝\n\n");
                free(q);
                return 0;
            
            default:
                printf("\n╔════════════════════════════════════════╗\n");
                printf("║  ❌ Invalid choice! Please enter       ║\n");
                printf("║  a number between 1 and 10.           ║\n");
                printf("╚════════════════════════════════════════╝\n");
        }
    }
    
    return 0;
}