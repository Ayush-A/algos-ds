/* Program to give one solution of N Queen Problem using Backtracking.

   Just change the value of n in #define to the dimension of chessboard, 
   and the program will output one of the feasible solution of the problem.*/

#include <stdio.h>
#define n 16

// Prints the chessboard
void printchessboard(int chessboard[][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", chessboard[i][j]);
        }
        printf("\n");
    }
}

// Checks whether we are free to place a queen in the given cell
int freecheck(int chessboard[][n], int row, int col){
    
    // Check if there is a queen preceding in the row
    for (int i = 0; i < col; i++){
        if (chessboard[row][i]){
            return 0;
        }
    }

    // Check if the upper left diagonal is not free
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (chessboard[i][j]){
            return 0;
        }
    }

    // Check if the upper right diagonal is not free
    for (int i = row, j = col; i < n && j >= 0; i++, j--){
        if (chessboard[i][j]){
            return 0;
        }
    }

    // If queen is in safe location then return 1
    return 1;
}

int nqueens(int chessboard[][n], int col){
    
    // If queen is places safely in every column
    if(col >= n){
        return 1;
    }
    for (int i =0; i < n; i++){

        // if the location is safe, place the queen
        if (freecheck(chessboard, i, col)){
            chessboard[i][col] = 1;

            // Solve for next column and place remaining queens
            if (nqueens(chessboard, col + 1)){
                return 1;
            }

            // Backtrack and change to queen's position to next safe location
            chessboard[i][col] = 0;
        }
    }
    return 0;
}

int main(void){
    int chessboard[n][n] = {0};

    // If no feasible solution is found
    if (nqueens(chessboard, 0) == 0){
        printf("Error\n");
        return 0;
    }

    // Output the solution to the N Queens problem
    printchessboard(chessboard);
}