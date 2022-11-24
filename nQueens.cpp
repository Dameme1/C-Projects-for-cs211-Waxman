// Tameem Ahmed
// nQueens

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c) {  //standard ok function, checks the up diagonal, down diagonal, and the row test. 
    for (int i = 0; i < c; i++)
    if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])) 
        return false;
    return true;  
}
int nqueens(int n) {  //nqueens function
    int solutions = 0; 
    int *q = new int[n];  //allocates dynamic memory, the exact amount we need for a given 'n' from the user. 
    int c = 0; 
    q[0] = 0; 
    while (c >= 0) { 
    c++;
    if (c == n) { //now if c == n (the same as c == 8) we do solutions++. WE DO NOT PRINT. 
        solutions++;
        c--; // backtrack
        }else {
            q[c] = -1; 
        }
        while (c >= 0) { 
             q[c]++;
             if (q[c] == n){  
                  c--; // backtrack
             }else if (ok(q, c) == true) break; // runs tests
    }
}
    delete[] q;  //delete the allocated dynamic memory
    return solutions; 

}

int main() {
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n; 
    for (int i = 1; i <= n; ++i)   //outputs all possible solutions for every 'n' queens problem from 1 all the way to 'n'. 
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}