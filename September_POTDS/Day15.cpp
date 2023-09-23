/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() < 1) return 0;
        auto dist = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };
        
        unsigned sz = points.size();
        vector<int> minDists(sz, 0);
        
        // Initialize
        int result = 0;
        minDists[0] = INT_MAX;
        for (auto i = 1; i < sz; i++) {
            minDists[i] = dist(points[0][0], points[0][1], points[i][0], points[i][1]);
        }
        
        // Build Spanning Tree
        for (auto i = 1; i < sz; i++) {
            auto it = min_element(minDists.begin(), minDists.end());
            result += *it;
            int index = it - minDists.begin();
            *it = INT_MAX;
            for (auto j = 0; j < sz; j++) {
                if (minDists[j] == INT_MAX) continue;
                minDists[j] = min(minDists[j], dist(points[j][0], points[j][1], points[index][0], points[index][1]));
            }
        }
        return result;        
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 5}};
    Solution solution;

    int minCost = solution.minCostConnectPoints(points);

    cout << "Minimum Cost to Connect Points: " << minCost << endl;

    return 0;
}
