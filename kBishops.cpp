#include <iostream> 
using namespace std;

/*
The difference for 8 queens and k-bishops is that you can have multiple bishops in one row or one column. 
So, the original data representation using a 1d array does NOT work
so instead we take a 2d array, and flatten it into a 1d array. 
so now, each element in an array of length 'k' (k is the amount of bishops) can go all the way up to (n*n) - 1
for example, a 8 by 8 board, with 5 bishops will allow each element in the array go from 0 to 63. 
so 'c' represents which bishop, and 'q[c]' represents the 'coords' of where that bishop is. 
*/

//q[c] % n = row
//q[c] / n = column


bool ok(int q[], int c, int n){     //same as the ok function for 8 queens, but without the row check. 
    for(int i = 0; i < c; i++){
        if((q[c] / n) - (q[i] / n) == abs((q[c] % n) - (q[i] % n)))
        return false;
    }
    return true; 
}

int kBishops(int n, int k){
    int sol = 0;
    int *q = new int[k]; // dynamically allocate memory
    int c = 0;
    q[c] = 0; // set the first bishop in the top left. 

    

    while(c >= 0){
        c++;
        if(c == k){ //reach the end of the array, increment solution. 
            sol++;
            c--;
        }
        else{
           q[c] = q[c - 1]; //start from the position of the previous bishop (prevents duplicate solutions)
        }
        while(c >= 0){
            q[c]++;
            if(q[c] >= (n * n)){ // (n*n) is past the bottom right corner of the board, so we must backtrack. 
                c--;
            }else if(ok(q,c,n)) break;
            
        }//inner while
    }//outer while
    
    delete[] q; //release the allocated memory
    return sol;
}//function


int main(){
    int n, k;


    while(true){
        cout << "Enter a value for n: ";
        cin >> n;

        if (n == -1){
            return 0;
        } // if

        cout << "Enter a value for k: ";
        cin >> k;

        if(k > n){
            return 0;
        }// if

        cout << "Number of solutions: " << kBishops(n, k) << "\n";
    }//while loop
    
    return 0;
    
}//main function
