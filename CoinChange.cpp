#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursive approach
// TC: O(2^n), where n is the value of sum
// SC: O(n), where n is the value of sum (recursive stack)
long long int RecursiveMethod(int coins[], int n, int sum) {
    // Base case: If sum becomes 0, there is a valid combination
    if (sum == 0) {
        return 1;
    }

    // Base cases for invalid situations
    if (n < 0 || sum < 0) {
        return 0;
    }

    // Recursively explore two possibilities: excluding and including the current coin
    return RecursiveMethod(coins, n - 1, sum) + RecursiveMethod(coins, n, sum - coins[n]);
}

// Method 2: Top-Down Approach with Memoization
// TC: O(n * sum), where n is the number of coins and sum is the target sum
// SC: O(n * sum), where n is the number of coins and sum is the target sum (memoization table)
long long int Memoization(int coins[], int n, int sum, vector<vector<long long int>>& dp) {
    // Base case: If sum becomes 0, there is a valid combination
    if (sum == 0) {
        return 1;
    }

    // Base cases for invalid situations
    if (n <= 0 || sum < 0)
        return 0;

    // If the result is already calculated, return it
    if (dp[sum][n] != 0) {
        return dp[sum][n];
    }

    // Recursively explore two possibilities: excluding and including the current coin
    dp[sum][n] = Memoization(coins, n - 1, sum, dp) + Memoization(coins, n, sum - coins[n - 1], dp);
    return dp[sum][n];
}

// Method 3: Tabulation (Bottom-Up)
// TC: O(n * sum), where n is the number of coins and sum is the target sum
// SC: O(n * sum), where n is the number of coins and sum is the target sum (DP table)
long long int Tabulation(int coins[], int N, int sum) {
    // Create a DP table to store the subproblem results
    vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1, 0));

    // Base case: If sum is 0, there is one way to make the change (no coins)
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    // Fill in the DP table iteratively
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            // If the current coin value is less than or equal to the current sum,
            // add the possibilities of not using the coin and using the coin
            if (j >= coins[i - 1])
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            // Otherwise, only consider not using the current coin
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // The final answer is stored at dp[N][sum]
    return dp[N][sum];
}

// Method 4: DP Solution
// TC: O(n * sum), where n is the number of coins and sum is the target sum
// SC: O(sum), where sum is the target sum (DP array)
long long int DP(int coins[], int N, int sum) {
    // Create a DP array to store the number of ways to achieve each sum
    vector<long long int> dp(sum + 1, 0);

    // Base case: There is one way to make the sum 0 (no coins)
    dp[0] = 1;

    // Iterate over each coin and update the DP array
    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= sum; j++) {
            // Add the ways to achieve the current sum using the current coin
            dp[j] += dp[j - coins[i]];
        }
    }

    // The final answer is stored at dp[sum]
    return dp[sum];
}

int main() {
    int N, sum;

    cout << "Enter the number of coins: ";
    cin >> N;

    int coins[N];
    cout << "Enter the coin values: ";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    // Choose any one of the methods

    // Method 1
    // long long int ans = RecursiveMethod(coins, N - 1, sum);
    // cout << "Total combinations: " << ans << endl;

    // Method 2
    // vector<vector<long long int>> dp(sum + 1, vector<long long int>(N + 1, 0));
    // cout << "Total combinations: " << Memoization(coins, N, sum, dp) << endl;

    // Method 3
    // cout << "Total combinations: " << Tabulation(coins, N, sum) << endl;

    // Method 4
    cout << "Total combinations: " << DP(coins, N, sum) << endl;

    return 0;
}
