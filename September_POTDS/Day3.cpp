/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     int recursiveSolution(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if (row == n - 1 && col == m - 1) {
            return 1;
        }
        if (row >= n || col >= m) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        return dp[row][col] = recursiveSolution(row + 1, col, m, n, dp) + recursiveSolution(row, col + 1, m, n, dp);
    }
    /*
    The time complexity is 
            O(2^(m * n)), 
    where m is the number of columns and n is the number of rows.
    
    */

    // Recursive solution with memoization
    int countPath(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = countPath(i + 1, j, m, n, dp) + countPath(i, j + 1, m, n, dp);
    }

    int uniquePathsMemoization(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countPath(0, 0, m, n, dp);
    }

    // Tabulation (bottom-up) solution
    int uniquePathsTabulation(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize the first row and first column to 1, as there's only one way to reach any cell in the first row or column.
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }

        // Fill in the DP table using bottom-up approach.
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution solution;

    int m = 3; // Number of columns
    int n = 2; // Number of rows

    int uniquePathsMemo = solution.uniquePathsMemoization(m, n);
    int uniquePathsTab = solution.uniquePathsTabulation(m, n);

    // Print the results
    cout << "Using Memoization: The number of unique paths in a " << m << "x" << n << " grid is: " << uniquePathsMemo << endl;
    cout << "Using Tabulation: The number of unique paths in a " << m << "x" << n << " grid is: " << uniquePathsTab << endl;

    return 0;
}
