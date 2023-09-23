/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 
*/

#include <vector>
#include <algorithm>
#include <numeric> // for accumulate function
#include <iostream>

using namespace std;

class Solution {
public:
    // Greedy approach to find the minimum number of candies
    int minCandiesGreedy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total candies needed
        return accumulate(candies.begin(), candies.end(), 0);
    }

    // Dynamic programming approach to find the minimum number of candies
    int minCandiesDP(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right pass
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }

        // Calculate the total candies needed
        return accumulate(candies.begin(), candies.end(), 0);
    }

    // Brute-force approach to find the minimum number of candies
    int minCandiesBruteForce(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total candies needed
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    vector<int> ratings1 = {1, 0, 2};
    vector<int> ratings2 = {1, 2, 2};
    Solution solution;

    int output1 = solution.minCandiesGreedy(ratings1);
    int output2 = solution.minCandiesGreedy(ratings2);

    cout << output1 << endl; // Output: 5
    cout << output2 << endl; // Output: 4

    return 0;
}
