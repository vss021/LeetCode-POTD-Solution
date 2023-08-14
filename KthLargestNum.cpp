#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        /*
        method 1.
        sort array and return (size-k) element
        tc => O(NlogN)
        sp => O(N)
        sort(begin(nums), end(nums));
        return nums[n-k];

        */
        /*
        method 2.
        using heap (minHeap)
            => create k size heap (priority_queue)

            if(minheap.top() < nums[i]) then
                -> pop top
                -> push current i'th element in minheap
            
            return minHeap top

            tc => o(NlogK) 
                because we only traverse one time and log(k) it minHeap insertion time

            sp => we only store k element so

            Extra space is => O(k) 
        */
        
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int> > minHeap;

        for (int i = 0; i < n; i++) {
            if (i < k) {
                minHeap.push(nums[i]);
            } else if (minHeap.top() < nums[i]) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};

int main() {
    Solution solution;

    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int kthLargest = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}
