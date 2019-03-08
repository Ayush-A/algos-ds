// C Program for Boundary Order Tree Traversal.

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in the tree
typedef struct node {
    struct node *left;
    int info;
    struct node *right;
} node;

// Function to allocate memory and to initialize the node
node* makenode(int info){
    node *newnode = (node *) malloc (sizeof(node));
    newnode -> info = info;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

// Function to print left boundary (Excluding the leaf node) [Top-Down]
void leftboundary(node *root){
    node *root1 = root;
    if (root1){
        if (root1 -> left){
            printf("%d ", root1 -> info);
            leftboundary(root1 -> left);
        }
        else if (root1 -> right){
            printf("%d ", root1 -> info);
            leftboundary(root1 -> right);
        }
        // To print the leaf node use below
        /* else {
            printf("%d ", root -> info); 
          } */
    }
}

// Function to print all the leaf elements
void leafnodes(node *root){
    if (root){
        leafnodes(root->left);
        if(!root->left && !root->right){
            printf("%d ", root -> info);
        }
        leafnodes(root->right);
    }
}

// Function to print right boundary (Excluding leaf and root) [Bottom-Up]
void rightboundary(node *root){
    if (root){
        if (root -> right){
            rightboundary(root -> right);
            printf("%d ", root -> info);
        }
        else if (root -> left){
            rightboundary(root -> left);
            printf("%d ", root -> info);
        }
    }
}

// Main program
int main(void){

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
    
    printf("Boundary elements: ");

    // Print the left boundary
    leftboundary(root);

    // Print leaf nodes
    leafnodes(root);

    // Print right boundary in bottom up manner
    rightboundary(root -> right);
    printf("\n");
}
