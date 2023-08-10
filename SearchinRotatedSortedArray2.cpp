#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (target == nums[mid]) {
                return true;  // Target found at index mid
            } else if (nums[start] < nums[mid]) {
                // Left portion of the range is sorted
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;  // Adjust end to search the left subarray
                } else {
                    start = mid + 1;  // Adjust start to search the right subarray
                }
            } else if (nums[mid] < nums[start]) {
                // Right portion of the range is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;  // Adjust start to search the right subarray
                } else {
                    end = mid - 1;  // Adjust end to search the left subarray
                }
            } else {
                // Duplicates found, move start to skip duplicate elements
                start += 1;
            }
        }
        
        return false;  // Target not found in the array
    }
};

int main() {
    Solution solution;

    // User input: Enter the number of elements in the rotated sorted array
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // User input: Enter the elements of the rotated sorted array
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // User input: Enter the target value to search
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    // Call the search function and display the result
    bool result = solution.search(nums, target);
    if (result) {
        cout << "Target found in the array." << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
