#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newnode(int key) {
    struct node* new;
    new = (node*)malloc(sizeof(node));
    new->data = key;
    new->right = NULL;
    new->left = NULL;
    return new;
}

node* insert(node* root, int key) {
    if (root == NULL) {
        return newnode(key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }
    return root;
}

void search(node* root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return;
    } else if (root->data == key) {
        printf("Key found\n");
        return;
    } else if (key < root->data)
        search(root->left, key);
    else if (key > root->data)
        search(root->right, key);
}

node* inpre(node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

node* insuc(node* root) {
    root = root->right;
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* deleteNode(node* root, int key) {
    if (root == NULL)
        return root;
    else if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest
        // in the right subtree)
        node* temp = insuc(root->right);

        // Copy the in-order successor's data to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

int main() {
    printf("Name: - Anushka Negi\n");
    printf("Roll no: - 11\n");

    int num, val;
    node* root = NULL;

    printf("How many nodes do you want in your tree: ");
    scanf("%d", &num);

    printf("Enter %d values for your tree: ", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nYour tree is: ");
    inorder(root);

    printf("\nEnter the value you want to delete from your tree: ");
    scanf("%d", &val);
    root = deleteNode(root, val);

    printf("\nAfter deletion, your tree is: ");
    inorder(root);

    printf("\nEnter the value to search in the tree: ");
    scanf("%d", &val);
    search(root, val);

    return 0;
}
