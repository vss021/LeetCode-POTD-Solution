#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

 
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // Create a map to store the count of roads for each city
        unordered_map<int, int> cityCount;

        // Create a 2D array to represent the connections between cities
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));

        // Populate the cityCount and isConnected based on the roads
        for (const auto& road : roads) {
            int city1 = road[0];
            int city2 = road[1];

            // Increment road count for each city
            cityCount[city1]++;
            cityCount[city2]++;

            // Mark the connection between cities
            isConnected[city1][city2] = true;
            isConnected[city2][city1] = true;
        }

        int maxRank = 0;

        // Iterate through each pair of cities to find the maximal network rank
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = cityCount[i] + cityCount[j];

                // If there is a direct connection between cities i and j, reduce rank
                if (isConnected[i][j])
                    rank--;

                // Update the maximal network rank
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};

int main() {
    Solution solution;

    int n, m;
    cout << "Enter the number of cities (n): ";
    cin >> n;

    cout << "Enter the number of roads (m): ";
    cin >> m;

    vector<vector<int>> roads(m, vector<int>(2));
    cout << "Enter the roads (city pairs):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    int result = solution.maximalNetworkRank(n, roads);
    cout << "Maximal Network Rank: " << result << endl;

    return 0;
}

