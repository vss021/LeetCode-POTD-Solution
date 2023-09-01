#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> BruteForce_Solution(vector<int>& nums, int k) {
        // Time Complexity: O(N * k)
        // Space Complexity: O(1)

        if (k == 1) {
            return nums;
        }

        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            int mx = INT_MIN;
            for (int j = i; j < i + k; j++) {
                mx = max(nums[j], mx);
            }
            ans.push_back(mx);
        }

        return ans;
    }

    vector<int> maxHeap_Solution(vector<int>& nums, int k) {
        // Time Complexity: O(N * log(k))
        // Space Complexity: O(k)

        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap; // Store elements along with their indices

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements that are out of the current window
            while (!maxHeap.empty() && maxHeap.top().second < i - k + 1) {
                maxHeap.pop();
            }

            maxHeap.push({nums[i], i}); // Add current element to the heap

            // If the window is fully formed, add maximum element to the answer
            if (i >= k - 1) {
                ans.push_back(maxHeap.top().first);
            }
        }

        return ans;
    }

    vector<int> double_ended_queue(vector<int>& nums, int k) {
        // Time Complexity: O(N)
        // Space Complexity: O(k)

        vector<int> ans;
        deque<int> dq;  // Store indices of elements

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);  // Add current index to the deque

            // If the window is fully formed, add maximum element to the answer
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return double_ended_queue(nums, k);  // You can change this to use any method you prefer
    }
};

int main() {
    Solution solution;

    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the window size (k): ";
    cin >> k;

    vector<int> result = solution.maxSlidingWindow(nums, k);

    cout << "Maximum elements in each sliding window of size " << k << ":" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
