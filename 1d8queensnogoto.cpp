// Tameem Ahmed 
// 2 Dimensional Array Program with Backtracking, GOTO


#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || (c - i) == abs(q[c] - q[i])) // tests, the row test and the diagonal tests are all combined here
            return false; 
    }
    return true; 
}

void print(int q[])
{
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": ";
    for (int i = 0; i < 8; i++) {       // prints the raw solution
        cout << q[i];
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {         // prints the board
        for (int j = 0; j < 8; j++) {
            if (q[i] == j) 
                cout << " x ";
            else 
                cout << " o ";
        }
        cout << endl;
    }

    cout << "\n";
}

int main()
{
    int q[8], c = 0;   //initializations
    q[0] = 0; 

        while (c >= 0) { //outer while loop, position check
            c++; // increment column
            if (c == 8) { //position check
                print(q);
                c--; 
            } else
                q[c] = -1; 
            while (c >= 0) { //inner while loop, position check
                q[c]++; // increment row
                if (q[c] == 8)
                    c--; 
                else if (ok(q, c)) 
                    break; 
            } // inner loop
        }//outer loop
    return 0;
} // main function

