#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Node *insertion(struct Node *root, int data) {
    if (root == NULL) {
        return create(data);
    } else if (root->data > data) {
        root->left = insertion(root->left, data);
    } else if (root->data < data) {
        root->right = insertion(root->right, data);
    }
    return root;
}

bool isPalindrome(char *str) { // checking if it is a pallindrome or not . 
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int countPalindrome(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    char *str = (char *)malloc(12); // Dynamically creating an string
    sprintf(str, "%d", root->data); // sprintf converts the integer to string .

    int count = isPalindrome(str);
    free(str); //deleting the data from the string .

    count += countPalindrome(root->left);
    count += countPalindrome(root->right);
    return count;
}

int main() {
    struct Node *root = NULL;
    root = insertion(root,191); // palindrome
    root = insertion(root,141); // palindrome
    root = insertion(root,27);
    root = insertion(root,434); // palindrome
    root = insertion(root,12521); // palindrome
    root = insertion(root,21);
    root = insertion(root,7); // palindrome
    root = insertion(root,22); // palindrome

    printf("The number of palindromes is: %d\n", countPalindrome(root));

    return 0;
}
