/* Program to solve Tower Of Hanoi problem of transferring discs from 
    rod A to C using an intermediate rod B. */

#include <stdio.h>

/* Recursive Solution to Tower of Hanoi problem.
    A is the starting rod.
    B is intermediate rod.
    C is the output rod.
*/
void towerofhanoi(int n, char A, char B, char C){
    if (n > 0){
        towerofhanoi(n - 1, A, C, B);
        printf("From %c to %c\n", A, C);
        towerofhanoi(n - 1, B, A, C);
    }
}

int main(void){
    int n, exponent;
    char ch = 'Y';
    long long int pow = 1;
    printf("Enter the number of disks in tower 'A': ");
    scanf("%d", &n);
    
    // Calculating the minimum number of steps required. (2^n - 1)
    exponent = n;
    while (exponent > 0){
        pow *= 2;
        exponent--;
    }
    printf("Number of moves required: %lld\n", pow - 1);
    printf("Do you wish to continue solving? (Y/N): ");

    /* Retain space before %c so that scanf asks for user input and doesn't take
       \n as a default input as a result of previous scanf statement. */
    scanf(" %c", &ch);
    
    if (ch == 'y' || ch == 'Y'){
        // Solve the Problem
        towerofhanoi(n, 'A', 'B', 'C');
    }
    else{
        printf("Try again later!\n");
        return 0;
    }
}
    