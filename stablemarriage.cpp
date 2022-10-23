// Tameem Ahmed
// Stable Marriage, no GOTO's


#include <iostream>
using namespace std;

bool ok(int q[], int c) // test function 
{
    //preferences are ranked from 0 through 2 where 0 is the best and 2 is the worst
    
    static int mp[3][3] = { { 0, 2, 1 },     // man 0's preferences
                            { 0, 2, 1 },     // man 1's preferences
                            { 1, 2, 0 } };   // man 2's preferences 

    static int wp[3][3] = { { 2, 1, 0 },     // woman 0's preferences
                            { 0, 1, 2 },     // woman 1's preferences
                            { 2, 0, 1 } };   // woman 2's preferences


    for (int i = 0; i < c; i++){
        if(q[c] == q[i] ||  //checks if woman 'c' is assigned to someone else already 
           (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) || // checks if man 'i' likes man c's wife more than his own and vice versa (love reciprocated)
           (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]))   // checks if man 'c' likes man i's wife more than his own and vice versa (love reciprocated)
        
            return false; 
        
    }
    return true;
}

void print(int q[]){  // prints given solution
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; i++){
        cout << i << "\t" << q[i] << "\n";
    }
}

int main (){
     int q[3], c = 0; //initizalizations
    q[0] = 0; 

        while (c >= 0) { // outer while loop, position check
            c++; // increment column (man)
            if (c == 3) { // position check
                print(q);
                c--; 
            } else
                q[c] = -1; 

            while (c >= 0) { // inner while loop, position check
                q[c]++; // increment row (woman)
                if (q[c] == 3) 
                    c--; 
                else if (ok(q, c)) 
                    break;
            } // inner loop
        } // outer loop

    return 0;
} // main function
