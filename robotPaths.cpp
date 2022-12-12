//Tameem Ahmed
//Robot Paths

#include <iostream>
using namespace std;

int path(int i, int j){
    if(i == 0 || j == 0) return 1; 
    return path(i, j - 1) + path(i - 1, j);
}

int main(){

    cout << path(4, 4) << endl;

    return 0;    
}