// Tameem Ahmed
// 1-Dimensional 8 Queens (With GOTO's)

#include <iostream> 
#include <cmath>
using namespace std;

int main(){
static int sol_num = 0;
int q[8], c = 0;
q[0] = 0;

nc:
    c++; // increments column
    if(c == 8) goto print;
    q[c] = -1;

nr: 
    q[c]++; // increment row
    if(q[c] == 8) goto backtrack;
    for(int i = 0; i < c; i++){
        if(q[c] == q[i] || (c - i) == abs(q[c]-q[i])) goto nr;  //tests, the row test and the diagonal tests are all combined here
    }
    
    goto nc; //next column

backtrack:
    c--;
    if(c == -1) return 0; // we already know where the queen is
    goto nr;
print:
cout << "Solution #: " << ++sol_num <<endl;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(q[j] == i) cout << " X ";
            else cout << " O ";
        }
        cout << endl;
    }

goto backtrack; // next solution
}
