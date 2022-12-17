// Tameem Ahmed 
// Towers of Hanoi

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3]; // initialize array of size 3, where each element is a vector. 
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n; 
   cout << endl;
   
   int from = 0, to = (n % 2 == 0)? 2 : 1, candidate = 1, move = 0;  
   int close = (n % 2 == 1)? 1 : 2;                                 // The value changes depending on even or odd rings. This simulates going clockwise or counter clockwise. 
   int far = (n % 2 == 1)? 2 : 1; 

   for(int i = n + 1; i >= 1; --i) // this initializes the initial 'from' tower with all the rings.
      t[0].push_back(i);
   
   t[1].push_back(n+1); 
   t[2].push_back(n+1);
   
   while (t[1].size() < n+1) {

      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";  //outputs the moves being made. 
      
      t[to].push_back(candidate); //pushes candidate onto 'to' tower
      t[from].pop_back(); // removes candidate off of 'from' tower. 
    

      if (t[(to + close) % 3].back() > t[(to + far) % 3].back())  //checks which of the available towers has the 'smallest' ring on top. 
         from = (to + far) % 3;  
      else                                                               
         from = (to + close) % 3;
         
      candidate = t[from].back(); // sets candidate equal to the smallest ring from the new 'from' tower. 
         
      if (candidate > t[(from + close) % 3].back()) // finds the new 'to' tower
         to = (from + far) % 3;
      else
         to = (from + close) % 3;
   } // end of while loop
   return 0; 

} // end of main function
