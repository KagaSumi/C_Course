#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
}Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserting a new node in a BST
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

// In-Order Traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

int find_height(Node* root){
    int height_l = 0;
    int height_r = 0;

    height_l += (root->left != NULL) ? find_height(root->left) + 1:0;
    height_r += (root->right != NULL) ? find_height(root->right) + 1:0;

    int height = (height_l>height_r)?height_l:height_r;
    return height;
}

int isbalanced(Node* root){
    return (find_height(root->left) != find_height(root->right))? 0: 1;//unbalanced : Balanced
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    int height = find_height(root);
    printf("Height of the tree:%d\n",height);
    printf("This tree is %s\n",(isbalanced(root))?"balanced":"unbalanced");
    
    return 0;
}
