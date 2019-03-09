// Program to reverse a linked list in C

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in a Linked List
typedef struct node{
    int info;
    struct node *next;
} node;

// Function to allocate memory and to initialize the node
node *makenode(int info){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> info = info;
    newnode -> next = NULL;
    return newnode;
}

// Print a linked list given its head
void printll(node *head){
    while (head != NULL){
        printf("%d ", head -> info);
        head = head -> next;
    }
    printf("\n");
}

// Function to reverse the supplied linked list
void reversell(node *head){
    node *current  = head, *next = NULL, *prev = NULL;
    while (current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    printll(prev);
}

int main(void){
    node *head = makenode(10);
    head -> next = makenode(20);
    head -> next -> next = makenode(30);
    head -> next -> next -> next = makenode(40);
    head -> next -> next -> next -> next = makenode(50);
    head -> next -> next -> next -> next -> next = makenode(60);
    head -> next -> next -> next -> next -> next -> next = makenode(70);
    printf("Original Linked List is: ");
    printll(head);
    printf("Reversed Linked List is: ");
    reversell(head);
}

