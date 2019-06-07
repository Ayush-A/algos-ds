#include <iostream>
using namespace std;
struct node{
    int info;
    node *next;
} *head = NULL;

// Insert Node at the end of a linked list
void insert(int info){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> info = info;
    newnode -> next = NULL;
    if (head == NULL){
        head = newnode;
    }
    else{
        node *p = head;
        while (p -> next != NULL){
            p = p -> next;
        }
        p -> next = newnode;
    }
}

// Print the linked list
void printll(){
    if (head == NULL){
        cout<<"No element\n";
    }
    else{
        node *p = head;
        while (p != NULL){
            cout<< p -> info << " ";
            p = p -> next;
        }
        free(p);
    }
    cout<<"\n";
} 

// Removing duplicates from a given linked list
void rmdup(){
    node *element = head, *nextelement;

    // Using an element as base and iterating through the other elements - O(n^2)
    while (element != NULL){
        nextelement = element;
        while (nextelement -> next != NULL){
            if (element -> info == nextelement -> next -> info){
                nextelement -> next = nextelement -> next -> next;
            }
            else{
                nextelement = nextelement -> next;
            }
        }
        element = element -> next;
    }
}

int main(void){
    insert(5); insert(1); insert(1); insert(8);
    insert(1); insert(4); insert(2); insert(1);
    insert(4); insert(1); insert(2);
    printll();
    rmdup();
    cout<<"After removing duplicates: " << endl;
    printll();
    return 0;
}
