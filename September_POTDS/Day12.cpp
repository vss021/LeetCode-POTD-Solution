#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        // Create a frequency map to count the occurrences of each character
        unordered_map<char, int> charFrequency;

        // Count the character frequencies
        for (char x : s) {
            charFrequency[x]++;
        }

        // Create a max heap (priority_queue) to store character frequencies
        priority_queue<int> maxHeap;

        // If there's only one unique character, no deletions are needed
        if (charFrequency.size() == 1) {
            return 0;
        }

        // Push character frequencies into the max heap
        for (auto entry : charFrequency) {
            int frequency = entry.second;
            maxHeap.push(frequency);
        }

        int deletionCount = 0;

        // Process the max heap to resolve conflicts
        while (!maxHeap.empty()) {
            int currentTop = maxHeap.top();
            maxHeap.pop();

            // Check if there's another character with the same frequency
            if (!maxHeap.empty() && currentTop == maxHeap.top()) {
                deletionCount++;
                currentTop--;

                // If the frequency is still greater than 0, push it back into the max heap
                if (currentTop > 0) {
                    maxHeap.push(currentTop);
                }
            }
        }

        return deletionCount;
    }
};

int main() {
    Solution solution;
    string input = "aab";
    int result = solution.minDeletions(input);
    cout << "Minimum deletions required: " << result << endl;
    return 0;
}
