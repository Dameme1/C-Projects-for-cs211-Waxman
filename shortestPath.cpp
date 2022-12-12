//Tameem Ahmed
//Shortest Path 
#include <iostream>
using namespace std;
const int rows = 5;
const int cols = 6;


int cost(int i, int j)
{
    // i is the row, j is the column
    static int weight[rows][cols] = {
        { 3, 4, 1, 2, 8, 6 },
        { 6, 1, 8, 2, 7, 4 },
        { 5, 9, 3, 9, 9, 5 },
        { 8, 4, 1, 3, 2, 6 },
        { 3, 7, 2, 8, 6, 4 }
    };

    // base case (leftmost column)
    if (j == 0) {
        return weight[i][0];
    }
    int left = cost(i, j - 1); // move left, row_index doesn't change
    int up = cost((i + (rows - 1))% rows, j - 1); // move up, (row_index + (rows-1)) % rows
    int down = cost((i + 1) % rows, j - 1); // move down, (row_index + 1) % rows
    
    int min_cost = ((left < up)? ((left < down)? left : down ): ((up < down)? up : down));

    
    min_cost = weight[i][j] + min_cost;

    return min_cost;

} // end of cost function


int main()
{
    int ex[rows], minCost; 

    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i, cols - 1); // call recursive function to get the shortest path for each exit
    }
    
    minCost = ex[0];
    for(int i = 1; i < rows; i++){
        if(ex[i] < minCost){
            minCost = ex[i];
        }
    }

    cout << "The weight of the shortest path is of length " << minCost << endl;

    return 0;
}
