

/*

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Solution 1: Two-Pointers
    int minOperationsTwoPointers(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int minOps = INT_MAX;

        while (right < n) {
            sum += nums[right++];

            while (sum > x && left < right) {
                sum -= nums[left++];
            }

            if (sum == x) {
                minOps = min(minOps, n - (right - left));
            }
        }

        return minOps == INT_MAX ? -1 : minOps;
    }

    // Solution 2: Sliding Window (Reverse Problem)
    int minOperationsSlidingWindow(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;

        if (target < 0) {
            return -1;
        }

        int n = nums.size();
        int left = 0, right = 0;
        int currentSum = 0;
        int minOps = INT_MAX;

        while (right < n) {
            currentSum += nums[right++];

            while (currentSum >= target && left < right) {
                if (currentSum == target) {
                    minOps = min(minOps, n - (right - left));
                }
                currentSum -= nums[left++];
            }
        }

        return minOps == INT_MAX ? -1 : minOps;
    }

    // Solution 3: Prefix Sum and Hash Map
    int minOperationsPrefixSum(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        unordered_map<int, int> prefixToIndex;
        prefixToIndex[0] = 0;
        int target = 0;
        int minOps = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            prefixToIndex[prefixSum[i + 1]] = i + 1;
        }

        if (prefixSum[n] < x) {
            return -1;
        }

        if (prefixSum[n] == x) {
            return n;
        }

        for (int i = 0; i < n; i++) {
            int remaining = prefixSum[i] - x;

            if (prefixToIndex.count(remaining) > 0) {
                minOps = min(minOps, n - (i - prefixToIndex[remaining]));
            }
        }

        return minOps == INT_MAX ? -1 : minOps;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 1, 4, 2, 3};
    int x1 = 5;
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    int x3 = 10;

    int result1_twoPointers = solution.minOperationsTwoPointers(nums1, x1);
    int result2_twoPointers = solution.minOperationsTwoPointers(nums2, x2);
    int result3_twoPointers = solution.minOperationsTwoPointers(nums3, x3);

    int result1_slidingWindow = solution.minOperationsSlidingWindow(nums1, x1);
    int result2_slidingWindow = solution.minOperationsSlidingWindow(nums2, x2);
    int result3_slidingWindow = solution.minOperationsSlidingWindow(nums3, x3);

    int result1_prefixSum = solution.minOperationsPrefixSum(nums1, x1);
    int result2_prefixSum = solution.minOperationsPrefixSum(nums2, x2);
    int result3_prefixSum = solution.minOperationsPrefixSum(nums3, x3);

    cout << "Solution 1 (Two Pointers): " << result1_twoPointers << endl;
    cout << "Solution 2 (Two Pointers): " << result2_twoPointers << endl;
    cout << "Solution 3 (Two Pointers): " << result3_twoPointers << endl;

    cout << "Solution 1 (Sliding Window): " << result1_slidingWindow << endl;
    cout << "Solution 2 (Sliding Window): " << result2_slidingWindow << endl;
    cout << "Solution 3 (Sliding Window): " << result3_slidingWindow << endl;

    cout << "Solution 1 (Prefix Sum): " << result1_prefixSum << endl;
    cout << "Solution 2 (Prefix Sum): " << result2_prefixSum << endl;
    cout << "Solution 3 (Prefix Sum): " << result3_prefixSum << endl;

    return 0;
}
