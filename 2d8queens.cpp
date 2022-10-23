// Tameem Ahmed 24177271
// 2 Dimensional Array Program with Backtracking, GOTO
// Question Index: 2 

#include <iostream> 
using namespace std;

int main () {
    static int sol_num = 1; // add counter for the solution number when printing out each solution
    int q[8][8] = {0}; // create the chessboard and set all values equal to 0
    int r = 0, c = 0; // initializing the values of the row and column as the integer 0 
    q[r][c] = 1;//we start coding with placing 1st queen at [0][0]

nc:
    c++; // increment into next column
    if (c == 8) goto print; // if the column goes to 8, its off the chess board so we have to print the solution
    r = -1; // row equal to -1, so when we go to the next row on line 20, it begins from index 0 after r++, the top of the column 

nr:
    r++; // increments to next row
    if (r == 8) goto backtrack; // if the row is 8 it means its off the chess board so we have to backtrack to a previous column 
    
    for(int i = 0; i < c; i++){ //horizontal test by checking if a 1 (queen) is present horizontally
        if(q[r][i] == 1) goto nr;
    }
    
    for(int i = 1;r - i >= 0 && c - i >= 0; i++){ // updiagonal test by testing if a 1 (queen) is present diagonally 
        if(q[r-i][c-i] == 1) goto nr;
    }
    
    for(int i = 1; r + i < 8 && c - i >= 0; i++){ // downdiagonal test by testing if a 1 (queen) is present diagonally
        if(q[r+i][c-i] == 1) goto nr;
    }

    q[r][c] = 1; // sets a queen in that position because all the tests were passed. 
    goto nc; // goes to the next column to continue the program 

backtrack:
    c--; // goes to previous column to backtrack and change the queen into a different position 
    if (c == -1) return 0; // if the column is -1, its off the board and there are no more possible solutions so end the program.
    r = 0; // starts from index 0 so that we can check each row to find the queen so we can remove it
    while(q[r][c] != 1){ // keeps iterating to the next row until the queen is found.
        r++;
    }
    q[r][c]=0; // after the while loop, the queen was found so therefore we set q[r][c] to 0 so we remove the queen
    goto nr; // we move on to the next row so we can find the next available spot.
print:
    cout << "Solution #: " << sol_num++ << endl; // prints out the solution number 

    for(int i = 0; i < 8; i++){ // nested for-loop to print out the chess board. 
        for (int j = 0; j < 8; j++){
            cout << q[i][j] << " "; // prints out each individual row with spaces in between
        }
        cout << endl;//goes to the next line after each row is printed. 
    }

    goto backtrack;// goes to backtrack to find the next possible soltuion so we can find all the possible soltuions. not just one. 





    return 0;
}