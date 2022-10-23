// Tameem Ahmed 
// 8 Numbers in a Cross, 2 While Loops

#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c) // ok function, does all the tests to see if the number can be placed in a given box. 
{
    static int a[8][5] = { // gives which boxes are adjacent to the box in question. (helper array)
        // Helper array
        { -1 }, // box 0
        { 0, -1 }, // box 1
        { 0, -1 }, // box 2
        { 0, 1, 2, -1 }, // box 3
        { 0, 1, 3, -1 }, // box 4
        { 1, 4, -1 }, // box 5
        { 2, 3, 4, -1 }, // box 6
        { 3, 4, 5, 6, -1 }, // box 7
    };
    for (int i = 0; i < c; i++) { // Makes sure there are no repeats. 
        if (q[i] == q[c])
            return false; // returns false if there are repeats. 
    }
    for (int i = 0; a[c][i] != -1; i++) { // makes sure there are no consecutive numbers in any adjacent box. 
        if (abs(q[c] - q[a[c][i]]) == 1) 
            return false; // returns false if there a consecutive number in an adjacent box. 
    }
    return true;
}
void print(int q[]) // print function to print any solution, 
{ // print function
    static int sol_num = 0; // variable to count which solution number we are on currently. 
    cout << "Solution#: " << ++sol_num << endl;
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
}

int main()
{
    int q[8] = { 0 }; // declaration of the array that holds all the numbers. 
    int c = 0; // declaration of column, which will be used in the tests. 
    q[c] = 1; // putting 1 in the first box to initialize the problem 

    while (c >= 0)  // outer while loop, makes sure that we aren't at -1, if we are then we will end the program because there are no more solutions. 
    {
        c++;    // increment the column. 
        if (c == 8) // if the column number is 8, we are off the board (boxes) and we have to print. 
        {
            print(q); // calls the print function 
            c--; // backtracks to find the next solution. 
        } else
        q[c] = 0; // sets the row equal to 0 so that when we start going through the 'rows' we can start off at one. 
        while (c >= 0)  // inner while loop, makes sure that we aren't at -1, if we are then we will end the program becaues there are no more solutions. 
        {
            q[c]++; // increment the 'row' 
            if (q[c] > 8)  // if the 'row' number is greater than 8, that means that none of the numbers work and we have to back track to a previous column. 
            {
                c--; // backtrack by decrementing the column number.
                } else if (ok(q, c)) { // calls the ok function and if it is true we will break out into the main function, or we will increment the row again. 
            break; //breaks out into the outer while loop
            }
        } // inner loop
    } // outer loop

    return 0; // ends the program when c == -1, meaning there are no more solutions. 
} // main function 
