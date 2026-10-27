#include <stdio.h>
#include <stdlib.h>
#define MAX 100  

struct Stack
{
    int arr[MAX];  
    int top;            
};

struct Stack* initializeStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;  
    return stack;
}

void push(struct Stack* stack, int data)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d. Stack is full.\n\n", data);
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("%d pushed into stack.\n\n", data);
    }
}

int pop(struct Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n\n");
        return -1;
    }
    else
    {
        int data = stack->arr[stack->top];
        stack->top--;
        printf("%d popped from stack.\n\n", data);
        return data;
    }
}

void displayStack(struct Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty!\n\n");
    }
    else
    {
        printf("Stack (Top to Bottom): ");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%d", stack->arr[i]);
            if (i > 0)
                printf(" | ");
        }
        printf("\n\n");
    }
}

int getSize(struct Stack* stack)
{
    return stack->top + 1;
}

void clearStack(struct Stack* stack)
{
    stack->top = -1;
    printf("Stack cleared!\n\n");
}

int main()
{
    struct Stack* stack = initializeStack();
    int choice, data;

    printf("===== STACK MENU (ARRAY IMPLEMENTATION) =====\n\n");

    while (1)
    {
        printf("1. Push (Insert)");
        printf("\n2. Pop (Delete)");
        printf("\n3. Display Stack");
        printf("\n4. Get Stack Size");
        printf("\n5. Clear Stack");
        printf("\n0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                displayStack(stack);
                break;

            case 4:
                printf("Stack size: %d\n\n", getSize(stack));
                break;

            case 5:
                clearStack(stack);
                break;

            case 0:
                free(stack);
                printf("Memory freed. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }

    return 0;
}