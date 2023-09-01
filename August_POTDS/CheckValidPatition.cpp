/*
2369. Check if There is a Valid Partition For The Array

You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

    The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
    The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
    The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

 
Example 1:
    Input: nums = [4,4,4,5,6]
    Output: true
    Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
    This partition is valid, so we return true.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    bool checkValid(std::vector<int>& nums, int id, int len, std::vector<int>& dp)
    {
        int n = nums.size();
        // Base case if length of subarray less than 2 then invalid
        if(len < 2)
            return false;
        
        // If subproblem calculated previously then return value
        if(dp[id] != -1)
            return dp[id];
        
        // Subarray of length 2
        if(len == 2)
        {
            // Check for 2 consecutive are equal
            return nums[id] == nums[id+1];
        }
        // Subarray of length 3
        else if(len == 3)
        {
            // Check for 3 consecutive are equal
            if(nums[id] == nums[id+1] && nums[id+1] == nums[id+2])
                return true;
                
            // Check for 3 increasing numbers
            else if(nums[id+1] - nums[id] == 1 && nums[id+2] - nums[id+1] == 1)
                return true;
            else 
                return false;
        }
        // Recursively call for length of 2 & next remaining subarray OR call for length of 3 & next remaining subarray
        return dp[id] = (checkValid(nums, id, 2, dp) && checkValid(nums, id+2, n-(id+2), dp)) ||     
                        (checkValid(nums, id, 3, dp) && checkValid(nums, id+3, n-(id+3), dp));
    } 
    
    bool validPartition(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> dp(n + 1, -1);
        
        return checkValid(nums, 0, n, dp);
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 4, 5, 6};
    
    Solution solution;
    
    bool isValidPartition = solution.validPartition(nums);
    
    if (isValidPartition) {
        std::cout << "The array can be partitioned into valid subarrays." << std::endl;
    } else {
        std::cout << "The array cannot be partitioned into valid subarrays." << std::endl;
    }
    
    return 0;
}
