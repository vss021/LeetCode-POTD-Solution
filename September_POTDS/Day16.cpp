/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Binary Search with DFS approach
    bool canReachDest(vector<vector<int>>& heights, int maxEffort, int rows, int cols, vector<vector<bool>>& visited, int row, int col) {
        if (row == rows - 1 && col == cols - 1) {
            return true;
        }
        
        visited[row][col] = true;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (const auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                int effort = abs(heights[newRow][newCol] - heights[row][col]);
                if (effort <= maxEffort && canReachDest(heights, maxEffort, rows, cols, visited, newRow, newCol)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int left = 0, right = 1e6;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            
            if (canReachDest(heights, mid, rows, cols, visited, 0, 0)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    

    // Dijkstra's Algorithm approach
    int minimumEffortPathDijkstra(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        
        using PII = pair<int, int>;
        priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
        
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;
        
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();
            
            int row = pos.first;
            int col = pos.second;
            
            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }
            
            for (const auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
                    if (newEffort < efforts[newRow][newCol]) {
                        efforts[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return -1; // Should not reach here.
    }

    // Dynamic Programming approach
    int minimumEffortPathDynamicProgramming(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        
        dp[0][0] = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int effort = 0; effort <= 1e6; effort++) {
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    for (const auto& dir : dirs) {
                        int newRow = r + dir[0];
                        int newCol = c + dir[1];
                        
                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                            int curEffort = abs(heights[newRow][newCol] - heights[r][c]);
                            dp[newRow][newCol] = min(dp[newRow][newCol], max(effort, curEffort));
                        }
                    }
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    Solution solution;

    // Binary Search approach
    int minEffortBinarySearch = solution.minimumEffortPathBinarySearch(heights);
    cout << "Minimum Effort Path (Binary Search): " << minEffortBinarySearch << endl;

    // Dijkstra's Algorithm approach
    int minEffortDijkstra = solution.minimumEffortPathDijkstra(heights);
    cout << "Minimum Effort Path (Dijkstra's Algorithm): " << minEffortDijkstra << endl;

    // Dynamic Programming approach
    int minEffortDynamicProgramming = solution.minimumEffortPathDynamicProgramming(heights);
    cout << "Minimum Effort Path (Dynamic Programming): " << minEffortDynamicProgramming << endl;

    return 0;
}
