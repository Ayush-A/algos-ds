/*
Efficient approach to find the first missing positive integer in an array.

Time Complexity: O(n)
Extra Space Complexity: O(1) [No extra array]

Example:
Array: -2 1 3 5 7 -1
Output: First missing positive integer: 2
*/

#include <stdio.h>
#include <stdlib.h>

void find_first_positive(int arr[], int n){
    
    // Shift positive elements at start
    int i = 0, j = n - 1;
    while(i < j){
        if (arr[i] < 0 && arr[j] > 0){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
        }

        // If positive element already in front
        if (arr[i] > 0){
            i++;
            j++; // Incremented because it is decremented later (No change in j)
        }
        j--;
    }

    // Find the position where negative elements begin (For discarding unwanted data)
    for (j = 0; j < n; j++){
        if (arr[j] < 0){
            break;
        }
    }

    // Setting negative values on indexes where values are present (consider indexes start from 1)
    for (int i = 0; i < j; i++){
        if (abs(arr[i]) <= j){
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    
    // The first positive value containing index will be the first missing positive number
    for (int i = 0; i < j; i++){
        if (arr[i] > 0){
            printf("First missing positive integer is: %d\n", i + 1);
            break;
        }
    }
}

int main(void){
    int *arr, n;
    printf("Enter the length of array ( >2 ): ");
    scanf("%d", &n);
    
    // Validation
    if (n < 2){
        return 1;
    }

    // Input
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    find_first_positive(arr, n); // Function

    return 0;
}
