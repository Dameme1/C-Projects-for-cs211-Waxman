//Tameem Ahmed
//Shortest Path 

#include <iostream>
#include <string> 
using namespace std;
const int rows = 5;
const int cols = 6;

/*
The difference between this program and its 'non-memo' version is that this allows us to 'cout' the actual path instead of only its weight. 
we do this with this addition of memoization and an array called 'path' that keeps track of how many ways there are to get to a single box. 
*/

string path[rows][cols]; 
int cost(int i, int j)
{
   
    static int weight[rows][cols] = {
        { 3, 4, 1, 2, 8, 6 },
        { 6, 1, 8, 2, 7, 4 },
        { 5, 9, 3, 9, 9, 5 },
        { 8, 4, 1, 3, 2, 6 },
        { 3, 7, 2, 8, 6, 4 }
    };

    static int memo[rows][cols] = {0};

    if(memo[i][j] > 0) return memo[i][j];
    
    if (j == 0) {
        path[i][j] = to_string(i);
        return weight[i][0];
    }

    int left = cost(i, j - 1); 
    int up = cost((i + (rows - 1))% rows, j - 1); 
    int down = cost((i + 1) % rows, j - 1); 
    
    int min_cost = ((left < up)? ((left < down)? left : down ): ((up < down)? up : down)); //finds the smallest of the three costs. 

    if(min_cost == up){ //if the min_cost is from the upper-left box
        path[i][j] = path[(i + (rows - 1)) % rows][j - 1] + to_string(i); //we take the path in the upper-left box, then add 'i' to it, which is the row of the
                                                                                // current box (path[i][j]
    }
    else if(min_cost == left){ //if the min_cost is from the left box
        path[i][j] = path[i][j - 1] + to_string(i);
    }
    else{ // if the min_cost is from the lower-left box. 
        path[i][j] = path[(i + 1) % rows][j - 1] + to_string(i);
    }
    

    memo[i][j] = weight[i][j] + min_cost; // add the answer to memo

    return memo[i][j]; // return memo. 

} // end of cost function


int main()
{
    int ex[rows], minCost, minRow; 

    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i, cols - 1); // call recursive function to get the shortest path for each exit
    }
    
    minCost = ex[0];
    for(int i = 1; i < rows; i++){ //finds which row has the lowest weight
        if(ex[i] < minCost){
            minCost = ex[i];
            minRow = i;  //sets minRow equal to the 'i' (row) that has the lowest weight
        }
    }

    cout << "The weight of the shortest path is of length " << minCost << endl; // we print out the lowest weight. 
    cout << "The rows of the shortest path is: " << path[minRow][cols - 1] << endl; // we print out the path for the box with the lowest weight
    return 0;
}
