// C Program for Level Order Tree Traversal.

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in the tree
typedef struct node {
    struct node *left;
    int info;
    struct node *right;
} node;

// Function to allocate memory and to initialize the node
node *makenode(int info) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->info = info;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Output the level
void printlevel(node *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root -> info);
    }
    else if (level > 1) {
        printlevel(root -> left, level - 1);
        printlevel(root -> right, level - 1);
    }
}

// Return maximum height of the tree
int height(node *root) {
    if (!root) {
        return 0;
    }
    else {
        int left = height(root->left);
        int right = height(root->right);
        return (left > right) ? left + 1 : right + 1;
    }
}

// Calls printlevel function to print one level at once
void leveltraversal(node *root) {
    for (int i = 1, ht = height(root); i <= ht; i++) {
        printlevel(root, i);
    }
}

int main(void) {
    // Constructing the tree
    node *root = makenode(99);
    root -> left = makenode(12);
    root -> right = makenode(18);
    root -> left -> left = makenode(23);
    root -> left -> right = makenode(49);
    root -> left -> right -> left = makenode(50);
    root -> left -> right -> right = makenode(78);
    root -> right -> left = makenode(58);
    root -> right -> right = makenode(67);
    printf("Level ordered elements: ");

    // Print the Levels
    leveltraversal(root);
    printf("\n");
}