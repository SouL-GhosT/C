#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;  
    struct Node* next;  
};

int main() 
{
    struct Node* head = NULL;   
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    struct Node* prev_node = NULL;
    int choice, data, pos;
    printf("===== DOUBLY LINKED LIST MENU =====\n\n");
    while (1) 
    {
        printf("1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Display List (Forward)");
        printf("\n8. Display List (Backward)");
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
                newNode->prev = NULL;   
                newNode->next = head;    
                if (head != NULL)
                {
                    head->prev = newNode;  
                }
                head = newNode; 
                printf("%d inserted at beginning.\n\n", data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->prev = NULL;
                newNode->next = NULL;
                if (head == NULL)
                {
                    head = newNode;
                }
                else
                {
                    temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;  
                    temp->next = newNode;      
                    newNode->prev = temp;     
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
                newNode->prev = NULL;
                newNode->next = NULL;
                if (head == NULL)
                {
                    if (pos == 1)
                    {
                        head = newNode;
                        printf("%d inserted at position 1.\n\n", data);
                    }
                    else
                    {
                        printf("Position out of range!\n\n");
                        free(newNode);
                    }
                }
                else if (pos == 1)
                {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                    printf("%d inserted at position 1.\n\n", data);
                }
                else
                {
                    temp = head;
                    for (int i = 1; i < pos - 1 && temp != NULL; i++)
                        temp = temp->next;
                    if (temp == NULL)
                    {
                        printf("Position out of range!\n\n");
                        free(newNode);
                    }
                    else
                    {
                        newNode->next = temp->next;
                        newNode->prev = temp;
                        if (temp->next != NULL)
                            temp->next->prev = newNode;

                        temp->next = newNode;
                        printf("%d inserted at position %d.\n\n", data, pos);
                    }
                }
                break;

            case 4:
                if (head == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else
                {
                    temp = head;
                    printf("%d deleted from beginning.\n\n", head->data);

                    head = head->next;

                    if (head != NULL)
                        head->prev = NULL;

                    free(temp);
                }
                break;

            case 5:
                if (head == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else if (head->next == NULL)
                {
                    printf("%d deleted from end.\n\n", head->data);
                    free(head);
                    head = NULL;
                }
                else
                {
                    temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;  
                    printf("%d deleted from end.\n\n", temp->data);

                    prev_node = temp->prev;
                    prev_node->next = NULL;  
                    free(temp);
                }
                break;

            case 6:
                if (head == NULL)
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
                        temp = head;
                        printf("%d deleted from position 1.\n\n", head->data);
                        head = head->next;
                        if (head != NULL)
                            head->prev = NULL;
                        free(temp);
                    }
                    else
                    {
                        temp = head;
                        for (int i = 1; i < pos && temp != NULL; i++)
                            temp = temp->next;
                        if (temp == NULL)
                        {
                            printf("Position out of range!\n\n");
                        }
                        else
                        {
                            printf("%d deleted from position %d.\n\n", temp->data, pos);
                            if (temp->prev != NULL)
                                temp->prev->next = temp->next;
                            if (temp->next != NULL)
                                temp->next->prev = temp->prev;
                            free(temp);
                        }
                    }
                }
                break;

            case 7:
                if (head == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else
                {
                    printf("Doubly Linked List (Forward): NULL <-> ");
                    temp = head;

                    while (temp != NULL)
                    {
                        printf("%d <-> ", temp->data);
                        temp = temp->next;
                    }

                    printf("NULL\n\n");
                }
                break;

            case 8:
                if (head == NULL)
                {
                    printf("List is empty!\n\n");
                }
                else
                {
                    temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;

                    printf("Doubly Linked List (Backward): NULL <-> ");

                    while (temp != NULL)
                    {
                        printf("%d <-> ", temp->data);
                        temp = temp->prev;
                    }

                    printf("NULL\n\n");
                }
                break;

            case 0:
                while (head != NULL)
                {
                    temp = head;
                    head = head->next;
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