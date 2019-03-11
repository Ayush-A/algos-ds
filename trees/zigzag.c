// C Program for Zig-Zag Tree Traversal.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node *left;
    int info;
    struct node *right;
}node;

// Returns the height of tree
int height(node *root){
    if (root){
        int left = height(root -> left);
        int right = height(root -> right);
        return (left < right) ? right + 1 : left + 1;
    }
    else{
        return 0;
    }
}

// Function to allocate memory and to initialize the node
node *makenode(int info){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> info = info;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

// Print each level either left -> right or right -> left depending on flag value
void printlevel(node *root, int level, bool flag){
    if (!root){
        return;
    }
    if (level == 1){
        printf("%d ", root -> info);
    }
    else if (level > 1){
        if (flag){
            printlevel(root -> left, level - 1, flag);
            printlevel(root -> right, level - 1, flag);
        }
        else{
            printlevel(root -> right, level - 1, flag);
            printlevel(root -> left, level - 1, flag);
        }
    }
}

// Initiate the process 
void zigzag(node *root) {
    bool flag = false;
    for (int i = 1, ht = height(root); i <= ht; i++){
        printlevel(root, i, flag);
        flag = !flag;
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
    printf("Zig-Zag ordered elements: ");

    // Print the Levels
    zigzag(root);
    printf("\n");
}
