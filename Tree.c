#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into BST
struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }
    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insert(root->right, data);
    }
    // If data == root->data, duplicate not inserted
    return root;
}

// Search for a value in BST
struct Node* search(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return NULL;
    } 
    if (data == root->data) 
    {
        return root;
    } 
    else if (data < root->data) 
    {
        return search(root->left, data);
    } 
    else 
    {
        return search(root->right, data);
    }
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return NULL;
    }
    
    if (data < root->data) 
    {
        root->left = deleteNode(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = deleteNode(root->right, data);
    } 
    else 
    {
        // Node to delete found
        
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        }
        
        // Case 2: One child (right child only)
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        
        // Case 2: One child (left child only)
        if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Two children
        // Find inorder successor (minimum in right subtree)
        // WITHOUT using findMin function - do it inline
        struct Node* current = root->right;
        
        // Traverse to find the leftmost node in right subtree
        while (current->left != NULL) 
        {
            current = current->left;
        }
        
        // Now current points to the minimum value in right subtree
        root->data = current->data;
        root->right = deleteNode(root->right, current->data);
    }
    
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) 
{
    if (root == NULL) 
    {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) 
{
    if (root == NULL) 
    {
        return;
    }
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() 
{
    struct Node* root = NULL;
    int choice, value;

    while (1) 
    {
        printf("\nBINARY SEARCH TREE OPERATIONS\n");
        printf("1. Insert a value\n");
        printf("2. Search a value\n");
        printf("3. Delete a value\n");
        printf("4. Display Inorder (Sorted)\n");
        printf("5. Display Preorder\n");
        printf("6. Display Postorder\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully!\n", value);
                break;
            
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) 
                {
                    printf("%d found in the tree!\n", value);
                } 
                else 
                {
                    printf("%d not found in the tree!\n", value);
                }
                break;
            
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted (if it existed)!\n", value);
                break;
            
            case 4:
                printf("\nInorder traversal (Sorted): ");
                inorder(root);
                printf("\n");
                break;
            
            case 5:
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            
            case 6:
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            
            case 0:
                printf("\nProgram terminated!\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}