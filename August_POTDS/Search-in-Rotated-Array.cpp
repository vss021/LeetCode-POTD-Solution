#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Element found at index mid
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is in the left half
                } else {
                    left = mid + 1; // Target is in the right half
                }
            } else {  // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target is in the right half
                } else {
                    right = mid - 1; // Target is in the left half
                }
            }
        }

        return -1; // Element not found
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target;

    std::cout << "Enter the target value: ";
    std::cin >> target;

    int result = solution.search(nums, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}

/*
Time Complexity (TC):
The binary search algorithm is the main driver of the time complexity. 
In each iteration of the binary search, the search space is divided by 2. 
This means that the algorithm eliminates half of the remaining elements with each iteration. 
Hence, the time complexity of binary search is O(log n), where n is the number of elements in the input array nums.

Space Complexity (SC):
The space complexity of the provided solution is O(1), 
which means it uses a constant amount of extra space that doesn't depend on the size of the input. 
This is because the solution only uses a few integer variables 
(left, right, mid) and a constant amount of memory is required for function call overhead.

Overall, the time complexity is O(log n) and the space complexity is O(1), 
making the solution efficient in terms of both time and space usage.






*/