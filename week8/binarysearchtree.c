#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Value %d already exists in the tree — skipping duplicate.\n", data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


void displayTraversals(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    printf("Inorder : ");
    inorder(root);
    printf("\n");

    printf("Preorder : ");
    preorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    printf("Binary Search Tree (BST) Program\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Display traversals (inorder, preorder, postorder)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input.\n");
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    break;
                }
                root = insert(root, val);
                printf("%d inserted into BST.\n", val);
                break;
            case 2:
                displayTraversals(root);
                break;
            case 3:
                freeTree(root);
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeTree(root);
    return 0;
}
