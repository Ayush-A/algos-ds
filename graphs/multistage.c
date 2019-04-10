/* Program to find the shortest path from source to destination in a MultiStage Graph

Assume that the nodes are labelled from 0 to n - 1, where we consider 0 as the source 
while n-1 as the destination. Implementation of which is given below: 
*/

#include <stdio.h>
#define n 12

// Function to print the adjacency matrix representation of graph
void printgraph(int graph[][n]){
    printf("Inputted Graph is: \n");
    for (int i = 1, l = sizeof(graph[0]) / sizeof(int); i < l; i++){
        for (int j = 1; j < l; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Print an array with the given size
void printarray(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform the computation of finding the shortest path
void findShortestPath(int graph[][n]){
    printgraph(graph);

    /* cost array stores the minimum cost of reaching to the destination 
       from current/subsequent levels while propogating backwards in the graph. 
       
       target array stores the next route node of each level depending upon the minimum cost*/
    int cost[n] = {0}, target[n];
    
    // last node will have no cost and hence it will point to itself as target
    cost[n - 1] = 0;
    target[n - 1] = n - 1;

    // min variable is used to find the minimum cost
    int min = 32767;

    //Total stages in the graph
    int stages = 5;
    int path[stages];

    // Source and Destination will be 0 and n-1 respectively
    path[0] = 0;
    path[stages - 1] = n - 1;

    // Finding the minimum cost and target of each node
    for (int i = n - 2; i >= 0; i--){
        min = 32767;
        for (int j = i + 1; j < n; j++){
            if (graph[i][j] != 0 && graph[i][j] + cost[j] < min){
                min = graph[i][j] + cost[j];
                target[i] = j;
            }
        }
        cost[i] = min;
    }

    printf("Costs are: ");
    printarray(cost, n);
    printf("Cost Targets are: ");
    printarray(target, n);

    // Finding the path
    for (int i = 1; i < stages - 1; i++){
        path[i] = target[path[i - 1]];
    }

    printf("Path is: ");
    printarray(path, stages);
}

int main(void)
{
    int graph[][n] = {{0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    findShortestPath(graph);
}
