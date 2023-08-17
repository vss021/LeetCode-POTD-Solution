#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Define possible moves: right, down, left, up
        vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1)); // Initialize the answer matrix with -1
        queue<pair<int, int>> q; // Initialize a queue for BFS traversal

        // Initialize the queue with '0' cells and set their distances to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        // Perform BFS traversal
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Explore neighboring cells
            for (auto move : moves) {
                int nextX = x + move[0];
                int nextY = y + move[1];
                
                // Check if the neighboring cell is within bounds and unprocessed
                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && ans[nextX][nextY] == -1) {
                    // Update the distance and enqueue the neighboring cell
                    ans[nextX][nextY] = ans[x][y] + 1;
                    q.push({nextX, nextY});
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example input matrix
    vector<vector<int>> inputMatrix = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the updateMatrix function to get the updated matrix
    vector<vector<int>> updatedMatrix = solution.updateMatrix(inputMatrix);

    // Print the updated matrix
    cout << "Updated Matrix:\n";
    for (const auto& row : updatedMatrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
