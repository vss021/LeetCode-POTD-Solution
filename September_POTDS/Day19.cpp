
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Solution 1: Sorting and Finding Duplicates
    int findDuplicateSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1; // No duplicate found (optional)
    }

    // Solution 2: Floyd's Tortoise and Hare (Cycle Detection) Algorithm
    int findDuplicateCycleDetection(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    // Solution 3: Using HashSet
    int findDuplicateHashSet(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }
        return -1; // No duplicate found (optional)
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 4, 2, 2};
    vector<int> nums2 = {3, 1, 3, 4, 2};

    int result1_sort = solution.findDuplicateSorting(nums1);
    int result2_sort = solution.findDuplicateSorting(nums2);

    int result1_cycle = solution.findDuplicateCycleDetection(nums1);
    int result2_cycle = solution.findDuplicateCycleDetection(nums2);

    int result1_hashset = solution.findDuplicateHashSet(nums1);
    int result2_hashset = solution.findDuplicateHashSet(nums2);

    cout << "Solution 1 (Sorting): Duplicate in nums1: " << result1_sort << endl;
    cout << "Solution 1 (Sorting): Duplicate in nums2: " << result2_sort << endl;

    cout << "Solution 2 (Cycle Detection): Duplicate in nums1: " << result1_cycle << endl;
    cout << "Solution 2 (Cycle Detection): Duplicate in nums2: " << result2_cycle << endl;

    cout << "Solution 3 (HashSet): Duplicate in nums1: " << result1_hashset << endl;
    cout << "Solution 3 (HashSet): Duplicate in nums2: " << result2_hashset << endl;

    return 0;
}


