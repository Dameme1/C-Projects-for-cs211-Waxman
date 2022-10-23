// Tameem Ahmed 
// 8 Numbers in a Cross, 2 While Loops

#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c) //  
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
            return false; 
    }
    for (int i = 0; a[c][i] != -1; i++) { // makes sure there are no consecutive numbers in any adjacent box. 
        if (abs(q[c] - q[a[c][i]]) == 1) 
            return false; 
    }
    return true;
}
void print(int q[]) // print function to print any solution, 
{ // print function
    static int sol_num = 0; 
    cout << "Solution#: " << ++sol_num << endl;
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
}

int main()
{
    int q[8] = { 0 }; //initializations
    int c = 0; 
    q[c] = 1;

    while (c >= 0)  // outer while loop, position check
    {
        c++;    // increment the column. 
        if (c == 8) // position check 
        {
            print(q); 
            c--; 
        } else
        q[c] = 0; 
        while (c >= 0)  // inner while loop, position check
        {
            q[c]++; // increment the 'row' 
            if (q[c] > 8)  // position check
            {
                c--; 
                } else if (ok(q, c)) { 
            break; 
            }
        } // inner loop
    } // outer loop

    return 0; 
} // main function 
