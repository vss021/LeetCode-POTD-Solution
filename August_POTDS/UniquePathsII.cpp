#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/* Method1.
 Bruteforce Solution 
*/
    int BruteForceFunction(vector<vector<int>>& Grid, int row, int col, int n, int m) {
    // Base case: If we reach the destination cell
    if (row == n - 1 && col == m - 1) {
        // If destination cell contains an obstacle, there's no way to reach it
        if (Grid[row][col] == 1) return 0;
        // If destination cell is empty, there's one way to reach it
        return 1;
    }

    // Base case: If out of bounds or obstacle encountered
    if (row == n || col == m || Grid[row][col] == 1) {
        return 0;
    }

    // Recursive case: Move right and move down
    int ways = BruteForceFunction(Grid, row + 1, col, n, m) + BruteForceFunction(Grid, row, col + 1, n, m);
    
    return ways;
}

/* ----------------------------------------------------------------------------------------
    Method2.
    Recution with Menoizetion
    Helper function for memoization
     // Time Complexity: O(n * m) -
        Each cell is visited once and computed once, and memoized
    // Space Complexity: O(n * m) - 
        Memoization table is used to store intermediate results

*/
    int MemoizedFunction(vector<vector<int>>& Grid, int row, int col, int n, int m, vector<vector<int>>& memo)
    {
        // Base case: If we reach the destination cell
        if(row == n-1 && col == m-1) {
            if(Grid[row][col] == 1) return 0;
            return 1;
        }

        // Base case: If out of bounds or obstacle encountered
        if(row == n || col == m || Grid[row][col] == 1){
            return 0;
        }

        // If the result is already memoized, return it
        if(memo[row][col] != -1) {
            return memo[row][col];
        }

        // Compute and memoize the result
        memo[row][col] = MemoizedFunction(Grid, row+1, col, n, m, memo) + MemoizedFunction(Grid, row, col+1, n, m, memo);
        return memo[row][col];
    }
// --------------------------------------------------------------------------------------------

    // Wrapper function to convert recursive solution to memoization
    int RecursiveToMemoized(vector<vector<int>>& Grid, int n, int m)
    {
        // Initialize memoization table with -1
        vector<vector<int>> memo(n, vector<int>(m, -1));
        // Call the helper function
        return MemoizedFunction(Grid, 0, 0, n, m, memo);
    }

   
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();

        /*
        // method 1. 
        // Recursion

        return RecursiveFunction(Grid, 0, 0, n, m);
        */
        return RecursiveToMemoized(Grid, n, m);
        

    }

    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        
        // return BruteForceFunction(Grid, 0, 0, n, m);
        return RecursiveToMemoized(Grid, n, m);
    }
};

int main() {
    Solution sol;

    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> Grid(n, vector<int>(m));

    cout << "Enter the grid (0 for empty, 1 for obstacle):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Grid[i][j];
        }
    }

    int paths = sol.uniquePathsWithObstacles(Grid);

    cout << "Number of unique paths with obstacles: " << paths << endl;

    return 0;
}
