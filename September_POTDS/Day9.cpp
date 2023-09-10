/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //------------------------- Recursion with Backtracking -------------------------

    void backtrack(vector<int>& nums, int target, int& count) {
        if (target == 0) { // Base case: If the target becomes 0, we've found a valid combination
            count++; // Increment the count
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                // Explore all possible combinations by subtracting nums[i] from the target
                backtrack(nums, target - nums[i], count);
            }
        }
    }

    int recursionWithBacktracking(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, count); // Start the backtracking process
        return count;
    }

    // TC: O(N^T), SC: O(T), where N is the number of elements in nums, and T is the target.

    // -------------------------------Memoization----------------------------------

    int generateSum(int tg, vector<int>& nums, vector<int>& memo)
    {
        // Base case
        if(tg == 0)
        {
            return 1;
        }

        if(tg < 0){
            return 0;
        }

        // Check if the result for this state has already been computed
        if (memo[tg] != -1) {
            return memo[tg];
        }

        int cntAns = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Recursive call to find combinations
            cntAns += generateSum(tg - nums[i], nums, memo);
        }

        // Store the result in memo
        memo[tg] = cntAns;

        return cntAns;
    }

    int memoization(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1); // Initialize memoization array with -1
        return generateSum(target, nums, memo);
    }

    // TC: O(N*T), SC: O(T), where N is the number of elements in nums, and T is the target.

    // ----------------------------Tabulation (Dynamic Programming)-----------------------------

    int tabulation(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0); // Create a DP table to store the number of combinations
        dp[0] = 1; // There is one way to make a sum of 0 (by choosing nothing)

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    // Update dp[i] by adding the combinations that use nums[j]
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target]; // The final result is stored in dp[target]
    }

    // TC: O(N*T), SC: O(T), where N is the number of elements in nums, and T is the target.

    // -------------------main function----------------------------

    void printMenu() {
        cout << "Select an approach to find combinations:" << endl;
        cout << "1. Recursion with Backtracking" << endl;
        cout << "2. Memoization" << endl;
        cout << "3. Tabulation (Dynamic Programming)" << endl;
    }

    int combinationSum4(vector<int>& nums, int target, int approach) {
        switch (approach) {
            case 1:
                return recursionWithBacktracking(nums, target);
            case 2:
                // Initialize memoization array with -1
                vector<int> memo(target + 1, -1); 
                return generateSum(target, nums, memo);
            case 3:
                return tabulation(nums, target);
            default:
                cout << "Invalid option. Please choose a valid approach." << endl;
                return -1;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int target = 4;

    solution.printMenu();

    int approach;
    cout << "Enter your choice (1/2/3): ";
    cin >> approach;

    int result = solution.combinationSum4(nums, target, approach);

    if (result != -1) {
        cout << "Number of combinations: " << result << endl;
    }

    return 0;
}

