//Tameem Ahmed
//Shortest Path 
#include <iostream>
using namespace std;
const int rows = 5;
const int cols = 6;
/*
The main gist of this program is to find the path from left to right that results in the lowest 'weight'
this works recursively because the weight of any single box is itself plus the box to the left, upper-left, or lower-left.
*/
int cost(int i, int j)
{
    static int weight[rows][cols] = {  //this is the array we have to get our path through
        { 3, 4, 1, 2, 8, 6 },
        { 6, 1, 8, 2, 7, 4 },
        { 5, 9, 3, 9, 9, 5 },
        { 8, 4, 1, 3, 2, 6 },
        { 3, 7, 2, 8, 6, 4 }
    };

   
    if (j == 0) { // base case, this is the left most column. 
        return weight[i][0];
    }
    int left = cost(i, j - 1); // //this finds the cost of the box on the left
    int up = cost((i + (rows - 1))% rows, j - 1); // this finds the cost of the box on the upper left
    int down = cost((i + 1) % rows, j - 1); // move down, (row_index + 1) % rows //this finds the cost of the box on the lower left
    
    int min_cost = ((left < up)? ((left < down)? left : down ): ((up < down)? up : down)); 
    // ^^ this the same as min(min(left,up),down). it just finds which one is the smallest. 

    
    min_cost = weight[i][j] + min_cost; //adds up the weights 

    return min_cost;

} // end of cost function


int main()
{
    int ex[rows], minCost; 

    for (int i = 0; i < rows; i++) { // call recursive function to get the shortest path for each row in the rightmost column
        ex[i] = cost(i, cols - 1); 
    }
    
    minCost = ex[0];
    for(int i = 1; i < rows; i++){ //sets minCost equal to the lowest weight of all the rows in the rightmost column
        if(ex[i] < minCost){
            minCost = ex[i];
        }
    }

    cout << "The weight of the shortest path is of length " << minCost << endl;

    return 0;
}
