#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box is data type 
   box bb, wb, *board[8][8]; // bb and wb are boxes.  board is an 8x8 array of pointers to boxes.
                             

   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {   // makes the 'wb' white and the 'bb' black. 
         wb[i][j] = ' ';
         bb[i][j] = char(219);
      }
   
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},    //manually create the black queen template
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },  //manually create the white queen template
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   for(i=0; i<8; i++)    //creates alternating pattern of white and black boxes. 
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
   
    for(i = 0; i < 8; i++){
        for(j=0; j<8; j++){
            if(((i+j)%2 == 0) && q[j] == i){  //this will put a white queen on the black boxes
                board[i][j] = &wq;
            }
            if(((i+j)%2 != 0) && q[j] == i){  //this will put a black queen on the white boxes
                board[i][j] = &bq;
            }            
        }
    }

   cout << "Solution #" << ++solution << ":\n ";
   
   for (i=0; i<7*8; i++)  //upper border
      cout << '_';
   cout << "\n";

   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               cout << (*board[i][j])[k][l]; //[i][j] gives a pointer in that position, so *([i][j]) gives the 'box' that is being pointed to
         cout << char(179) << "\n";                 // [k][l] is then used to iterate through each position in each 'box.' hence we print the board 
      } 

   cout << " ";   // lower border
    for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;

    while (c >= 0) {  // NEXT COL:
        c++;                // Move to the next column
        if (c > 7) {          // If you have passed the last column, a solution is found
            print(q);      // Call the print function and backtrack
            c--;
        }
        else q[c] = -1;   // set to -1 so in inner loop you can start q[c] from 0
        while (c >= 0) {  // NEXT ROW:
            q[c]++;           // Move to the next row
            if (q[c] > 7) c--;  // If you have passed the end of the row, backtrack
            else              // Otherwise, call the ok function.
                if (ok(q, c)) break; // If ok (returns true), a queen is filled in the row
        }
    }
    return 0;
} 