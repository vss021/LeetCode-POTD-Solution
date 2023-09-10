/*
Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
Example 3:

Input: n = 3
Output: 90

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;

    long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 && undelivered == 0) {
            // We have completed all orders.
            return 1;
        }

        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            // We can't pick or deliver more than N items
            // Number of deliveries can't exceed the number of pickups 
            // as we can only deliver after a pickup.
            return 0;
        }

        if (memo[unpicked][undelivered]) {
            // Return cached value, if already present. 
            return memo[unpicked][undelivered];
        }

        long ans = 0;

        // Count all choices of picking up an order.
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        // Handle integer overflow.
        ans %= MOD;

        // Count all choices of delivering a picked order.
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        // Handle integer overflow.
        ans %= MOD;

        return memo[unpicked][undelivered] = ans;
    }

public:
    // Approach 1: Recursion with Memoization
    // TC: O(n^2), SC: O(n^2)
    int countOrders(int n) {
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return totalWays(n, n);
    }

    // Approach 2: Dynamic Programming
    // TC: O(n^2), SC: O(n^2)
    int countOrdersDP(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1; // Base case

        for (int undelivered = 0; undelivered <= n; undelivered++) {
            for (int unpicked = 0; unpicked <= n; unpicked++) {
                if (undelivered > 0) {
                    dp[unpicked][undelivered] += (undelivered - 1) * dp[unpicked + 1][undelivered - 1];
                }
                if (unpicked > 0) {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered + 1];
                }
                dp[unpicked][undelivered] %= MOD;
            }
        }

        return dp[n][0];
    }
};

int main() {
    Solution solution;
    int n = 3; // Replace with your desired input

    int result = solution.countOrders(n);
    cout << "Total ways to deliver orders (Recursion with Memoization): " << result << endl;

    int resultDP = solution.countOrdersDP(n);
    cout << "Total ways to deliver orders (Dynamic Programming): " << resultDP << endl;

    return 0;
}

