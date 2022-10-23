// Tameem Ahmed
// 2 Dimensional Array Program with Backtracking, GOTO

#include <iostream> 
using namespace std;

int main () {
    static int sol_num = 1;       // initializations
    int q[8][8] = {0}; 
    int r = 0, c = 0;
    q[r][c] = 1;

nc:
    c++; //increment to next column
    if (c == 8) goto print; // position check
    r = -1; 
nr:
    r++; // increments to next row
    if (r == 8) goto backtrack; // position check
    
    for(int i = 0; i < c; i++){ //horizontal test 
        if(q[r][i] == 1) goto nr;
    }
    
    for(int i = 1;r - i >= 0 && c - i >= 0; i++){ // updiagonal test 
        if(q[r-i][c-i] == 1) goto nr;
    }
    
    for(int i = 1; r + i < 8 && c - i >= 0; i++){ // downdiagonal test 
        if(q[r+i][c-i] == 1) goto nr;
    }

    q[r][c] = 1; // sets a queen in that position because all the tests were passed. 
    goto nc; 
backtrack:
    c--; // decrement column
    if (c == -1) return 0; // position check
    r = 0; 
    while(q[r][c] != 1){ // keeps iterating to the next row until the queen is found.
        r++;
    }
    q[r][c]=0; // set q[r][c] to 0  --- remove the queen
    goto nr;
print:
    cout << "Solution #: " << sol_num++ << endl; // prints out the solution number 

    for(int i = 0; i < 8; i++){ // nested for-loop to print out the chess board. 
        for (int j = 0; j < 8; j++){
            cout << q[i][j] << " "; 
        }
        cout << endl;
    }

    goto backtrack; //finds the next solution





    return 0;
}
