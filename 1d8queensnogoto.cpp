// Tameem Ahmed 24177271
// 2 Dimensional Array Program with Backtracking, GOTO
// Question Index: 2 


#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || (c - i) == abs(q[c] - q[i])) // tests, the row test and the diagonal tests are all combined here
            return false; // if the tests return true, then we failed the test, we return false
    }
    return true; // if the tests return false, this means we have passed the tests, we return true. 
}

void print(int q[])
{
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": ";
    for (int i = 0; i < 8; i++) { // prints the raw solution
        cout << q[i];
    }
    cout << endl;
    for (int i = 0; i < 8; i++) { // prints the board
        for (int j = 0; j < 8; j++) {
            if (q[i] == j) // if the value of q[i] is equal to the row value, then print x to indicate a queen
                cout << " x ";
            else // all other positions are o's 
                cout << " o ";
        }
        cout << endl;
    }

    cout << "\n";
}

int main()
{
    int q[8], c = 0; // initialize 1d array and column
    q[0] = 0; // set the the queen in (0,0) but in a 1d array it is shown as (c,q[c])

        while (c >= 0) { // if this is false, then we are off the board from the left side, meaning there are no more solutions and we can end the program
            c++; // move to the next column
            if (c == 8) { // if the column number reaches 8, its off the board from the right side, so print a solution
                print(q); // calls the print function
                c--; // backtracks to a previous column
            } else
                q[c] = -1; // we set the row = -1, so that we can bring from the top of the column

            while (c >= 0) { // if this is false then we are off the board from the left side, meaning there are no more solutions and we can end the program
                q[c]++; // iterates thorough the column, adds 1 to the row
                if (q[c] == 8) // if the row is 8, that means we are off the board, so we must backtrack
                    c--; // goes to the previous column
                else if (ok(q, c)) // checks if that position passes through the row tests and the diagonal tests.
                    break; // if it passes, then we can move onto the next column, hence we break out into the outer loop.
            }
        }
    return 0;
}