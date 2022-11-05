// Tameem Ahmed    
// Dumb 8 Queens Problem


#include <iostream> 
using namespace std;

bool ok(int q[], int c) // modified because we are inputting a full array
{
    for(int i = 0; i < 8; i++){ // outer for-loop
        
        for (int j = 0; j < c; j++) { // inner for-loop
            if ((q[j] == q[c]) || (c - j) == abs(q[c] - q[j])) // tests, the row test and the diagonal tests are all combined here
                return false; 
        } //inner

        c--; 
    }//outer
    
    return true; 
}

void print(int q[]){
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


int main (){

int q[8], c = 7; // initializations 

for (int i0 = 0; i0 < 8; i0++) {  //this is the left most position       
    for (int i1 = 0; i1 < 8; i1++) {
        for (int i2 = 0; i2 < 8; i2++) {
            for (int i3 = 0; i3 < 8; i3++) {                       // runs like an odometer, the inner most loop runs the fastest 
                for (int i4 = 0; i4 < 8; i4++) {
                    for (int i5 = 0; i5 < 8; i5++) {
                        for (int i6 = 0; i6 < 8; i6++) {
                            for (int i7 = 0; i7 < 8; i7++) { // this is the right most position 
                                q[0] = i0; // this will change the slowest
                                q[1] = i1;
                                q[2] = i2;
                                q[3] = i3;
                                q[4] = i4;
                                q[5] = i5;
                                q[6] = i6;
                                q[7] = i7; // this will change the fastest
                                if (ok(q, c)) print(q); // tests
                            }
                        }
                    }
                }
            }
        }
    }
}//left row
            


} // main function