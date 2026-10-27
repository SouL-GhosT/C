#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

int main() 
{
    struct Node* start = NULL; 
    struct Node* last = NULL;    
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    int choice, data, pos;

    printf("===== CIRCULAR LINKED LIST MENU =====\n\n");

    while (1) 
    {
        printf("1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Display List");
        printf("\n0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (start == NULL)
                {
                    start = newNode;
                    last = newNode;
                    newNode->next = start;
                }
                else
                {
                    newNode->next = start;
                    start = newNode;
                    last->next = start;
                }
                printf("%d inserted at beginning.\n\n", data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (start == NULL)
                {
                    start = newNode;
                    last = newNode;
                    newNode->next = start;
                }
                else
                {
                    last->next = newNode;
                    last = newNode;
                    last->next = start;
                }
                printf("%d inserted at end.\n\n", data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position (1 = beginning): ");
                scanf("%d", &pos);
                if (pos <= 0)
                {
                    printf("Invalid position!\n\n");
                    break;
                }
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (start == NULL)
                {
                    if (pos == 1)
                    {
                        start = newNode;
                        last = newNode;
                        newNode->next = start;
                        printf("%d inserted at position %d.\n\n", data, pos);
                    }
                    else
                    {
                        printf("Position out of range!\n\n");
                        free(newNode);
                    }
                }
                else if (pos == 1)
                {
                    newNode->next = start;
                    start = newNode;
                    last->next = start;
                    printf("%d inserted at position 1.\n\n", data);
                }
                else
                {
                    temp = start;
                    for (int i = 1; i < pos - 1; i++)
                    {
                        temp = temp->next;
                        if (temp == start)
                        {
                            printf("Position out of range!\n\n");
                            free(newNode);
                            goto skip3;
                        }
                    }

                    newNode->next = temp->next;
                    temp->next = newNode;
                    
                    if (newNode->next == start)
                        last = newNode;

                    printf("%d inserted at position %d.\n\n", data, pos);
                    skip3:;
                }
                break;

            case 4:
                if (start == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else if (start == last)
                {
                    printf("%d deleted from beginning.\n\n", start->data);
                    free(start);
                    start = NULL;
                    last = NULL;
                }
                else
                {
                    temp = start;
                    start = start->next;
                    last->next = start;
                    printf("%d deleted from beginning.\n\n", temp->data);
                    free(temp);
                }
                break;

            case 5:
                if (start == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else if (start == last)
                {
                    printf("%d deleted from end.\n\n", start->data);
                    free(start);
                    start = NULL;
                    last = NULL;
                }
                else
                {
                    temp = start;
                    while (temp->next != last)
                        temp = temp->next;

                    printf("%d deleted from end.\n\n", last->data);
                    free(last);
                    last = temp;
                    last->next = start;
                }
                break;

            case 6:
                if (start == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else
                {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);

                    if (pos <= 0)
                    {
                        printf("Invalid position!\n\n");
                        break;
                    }

                    if (pos == 1)
                    {
                        if (start == last)
                        {
                            printf("%d deleted from position 1.\n\n", start->data);
                            free(start);
                            start = NULL;
                            last = NULL;
                        }
                        else
                        {
                            temp = start;
                            start = start->next;
                            last->next = start;
                            printf("%d deleted from position 1.\n\n", temp->data);
                            free(temp);
                        }
                    }
                    else
                    {
                        temp = start;
                        struct Node* prev = NULL;
                        
                        for (int i = 1; i < pos; i++)
                        {
                            prev = temp;
                            temp = temp->next;
                            if (temp == start)
                            {
                                printf("Position out of range!\n\n");
                                goto skip6;
                            }
                        }

                        if (temp == last)
                        {
                            last = prev;
                        }

                        prev->next = temp->next;
                        printf("%d deleted from position %d.\n\n", temp->data, pos);
                        free(temp);
                        skip6:;
                    }
                }
                break;

            case 7:
                if (start == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else
                {
                    printf("Circular Linked List: ");
                    temp = start;
                    
                    do
                    {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    } while (temp != start);

                    printf("(%d) [back to start]\n\n", start->data);
                }
                break;

            case 0:
                if (start != NULL)
                {
                    temp = start;
                    struct Node* nodeToDelete;
                    
                    while (temp->next != start)
                    {
                        nodeToDelete = temp;
                        temp = temp->next;
                        free(nodeToDelete);
                    }
                    free(temp);  
                }
                printf("Memory freed. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }

    return 0;
}