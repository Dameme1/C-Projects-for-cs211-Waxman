//Tameem Ahmed
//Robot Paths

#include <iostream>
using namespace std;

int path(int i, int j){
    if(i == 0 || j == 0) return 1;  //this is the base case, there is only one path to the left most or the upper most row/column
    return path(i, j - 1) + path(i - 1, j);
}

int main(){

    cout << path(4, 4) << endl; //70

    return 0;    
}
