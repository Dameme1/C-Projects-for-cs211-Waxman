//Tameem Ahmed
//Recursive Towers of Hanoi
#include <iostream> 
using namespace std;

//For this to make the most sense, I would recommend drawing the three towers out and do the code manually. 
// try it for n = 3;

void move(char F, char T, char E, int n){ // F = 'tower a', T = 'tower b', E = 'tower c', n = number of rings. 

    if (n == 1){                          // we can move immediately if n == 1 (nothing smaller than one) 
    cout << " Transfer ring " << n << " From tower " << F << " To tower " << T << endl; 
    return;
    }
    move(F, E, T, (n-1));                   // eventually moves all the rings above n (or less than n) 

    cout << " Transfer ring " << n << " From tower " << F << " To tower " << T << endl;

    move(E, T, F, (n-1));              // eventually moves all the rings above n (or less than n)
    return;
}

int main(){
    int rings; 
    cout << "Enter # of rings for n towers of hanoi problem: ";

    cin >> rings;  // user enters the amount of rings

    move('a', 'b', 'c', rings);  //calls the recursive function

}

