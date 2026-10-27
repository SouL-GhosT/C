#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

int main() 
{
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    struct Node* prev = NULL;
    int choice, data, pos;
    
    printf("===== SINGLY LINKED LIST MENU =====\n");
    
    while (1) 
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Reverse List");
        printf("\n8. Display List");         
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
                newNode->next = head;   
                head = newNode;         
                printf("%d inserted at beginning.\n", data);
                break;
            
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
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
                }
                printf("%d inserted at end.\n", data);
                break;

            case 3:    
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position (1 = beginning): ");
                scanf("%d", &pos);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = NULL;
                if (pos == 1) 
                {
                    newNode->next = head;
                    head = newNode;
                } 
                else 
                {
                    temp = head;
                    for (int i = 1; i < pos - 1 && temp != NULL; i++)
                        temp = temp->next;
                    if (temp == NULL) 
                    {
                        printf("Position out of range!\n");
                        free(newNode);
                    } 
                    else 
                    {
                        newNode->next = temp->next;
                        temp->next = newNode;
                        printf("%d inserted at position %d.\n", data, pos);
                    }
                }
                break;

            case 4:
                if (head == NULL) 
                {
                    printf("List is empty!\n");
                } 
                else 
                {
                    temp = head;
                    head = head->next;  
                    printf("%d deleted from beginning.\n", temp->data);
                    free(temp);
                }
                break;

            case 5:
                if (head == NULL) 
                {
                    printf("List is empty!\n");
                } 
                else if (head->next == NULL) 
                {
                    printf("%d deleted from end.\n", head->data);
                    free(head);
                    head = NULL;
                } 
                else 
                {
                    temp = head;
                    prev = NULL;
                    while (temp->next != NULL) 
                    {
                        prev = temp;            
                        temp = temp->next;
                    }
                    printf("%d deleted from end.\n", temp->data);
                    prev->next = NULL;  
                    free(temp);
                }
                break;

            case 6:   
                if (head == NULL) 
                {
                    printf("List is empty!\n");
                } 
                else 
                {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);

                    if (pos == 1) 
                    {
                        temp = head;
                        head = head->next;
                        printf("%d deleted from position 1.\n", temp->data);
                        free(temp);
                    } 
                    else 
                    {
                        temp = head;
                        prev = NULL;
                        for (int i = 1; i < pos && temp != NULL; i++)
                        {
                            prev = temp;
                            temp = temp->next;
                        }

                        if (temp == NULL) 
                        {
                            printf("Position out of range!\n");
                        } 
                        else 
                        {
                            prev->next = temp->next;
                            printf("%d deleted from position %d.\n", temp->data, pos);
                            free(temp);
                        }
                    }
                }
                break; 

            case 7:
                if (head == NULL) 
                {
                    printf("List is empty! Nothing to reverse.\n");
                } 
                else if (head->next == NULL) 
                {
                    printf("List has only one node. Already reversed.\n");
                } 
                else 
                {
                    struct Node* curr = head;     
                    struct Node* prev_node = NULL; 
                    struct Node* next_node = NULL; 
                    while (curr != NULL) 
                    {
                        next_node = curr->next;
                        curr->next = prev_node;
                        prev_node = curr;
                        curr = next_node;
                    }
                    head = prev_node;
                    printf("List reversed successfully!\n");
                }
                break;

            case 8:
                if (head == NULL) 
                {
                    printf("List is empty!\n");
                } 
                else 
                {
                    temp = head;
                    printf("Linked List: ");
                    while (temp != NULL) 
                    {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }
                    printf("NULL\n");
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
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}