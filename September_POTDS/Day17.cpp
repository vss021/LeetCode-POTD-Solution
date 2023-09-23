
/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
*/




#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

class Solution {
public:
    // Class to carry three values at a time
    class tuple {
    public:
        int node; // The current node we are standing on
        int mask; // The mask of visited nodes
        int cost; // The cost of the path explored by this node

        tuple(int node, int mask, int cost) {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); // Total number of nodes

        queue<tuple> q; // Queue of class tuple type

        set<pair<int, int>> vis; // Set to keep track of visited paths (node, mask)

        int all = (1 << n) - 1; // If all nodes are visited

        // Initially, add all nodes to the queue
        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i); // 2^i
            tuple thisNode(i, maskValue, 1); // Create a tuple for each node
            q.push(thisNode); // Push the tuple into the queue
            vis.insert({i, maskValue}); // Insert into the set
        }

        // Implementing BFS
        while (!q.empty()) {
            tuple curr = q.front(); // Extracting the front tuple
            q.pop(); // Pop from the queue

            // If mask value becomes all, we have visited all nodes, so return cost - 1
            if (curr.mask == all) {
                return curr.cost - 1;
            }

            // Explore adjacent nodes
            for (auto &adj : graph[curr.node]) {
                int bothVisitedMask = curr.mask; // Current mask

                // Moving from one node to another
                bothVisitedMask = bothVisitedMask | (1 << adj);

                // Create a tuple for this path
                tuple ThisNode(adj, bothVisitedMask, curr.cost + 1);

                // If this path is not explored (not in our set)
                if (vis.find({ adj, bothVisitedMask }) == vis.end()) {
                    vis.insert({ adj, bothVisitedMask }); // Insert into set
                    q.push(ThisNode); // Insert into queue
                }
            }
        }

        // Return -1 (this condition will never come)
        return -1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 2},    // Node 1 is connected to nodes 0 and 2
        {0, 1, 3}, // Node 2 is connected to nodes 0, 1, and 3
        {2}        // Node 3 is connected to node 2
    };

    // Call the shortestPathLength function to find the shortest path length
    int shortestPath = solution.shortestPathLength(graph);

    // Print the result
    cout << "Shortest Path Length: " << shortestPath << endl;

    return 0;
}
