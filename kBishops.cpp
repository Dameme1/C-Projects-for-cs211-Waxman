#include <iostream> 
using namespace std;

bool ok(int q[], int c, int n){
    for(int i = 0; i < c; i++){
        if((q[c] / n) - (q[i] / n) == abs((q[c] % n) - (q[i] % n)))
        return false;
    }
    return true; 
}

int kBishops(int n, int k){
    int sol = 0;

    // dynamically allocate memory for array. 
    int *q = new int[k]; 
    int c = 0;
    q[c] = 0;

    //similar backtracking algorithm
    // Bishop loop

    while(c >= 0){
        c++;
        if(c == k){
            sol++;
            c--;
        }
        else{
           q[c] = q[c - 1];
        }
        while(c >= 0){
            q[c]++;
            if(q[c] >= (n * n)){
                c--;
            }else if(ok(q,c,n)) break;
            
        }//inner while
    }//outer while
    
    delete[] q; 
    return sol;
}//function


int main(){
int n, k;


while(true){
    cout << "Enter a value for n: ";
    cin >> n;

    if (n == -1){
        return 0;
    }

    cout << "Enter a value for k: ";
    cin >> k;

    if(k > n){
        return 0;
    }

    cout << "Number of solutions: " << kBishops(n, k) << "\n";
}
return 0;
}