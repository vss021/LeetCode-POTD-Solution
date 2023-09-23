
/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Solution 1: Dynamic Programming
    int longestStrChainDP(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string& word : words) {
            int currentLength = 1;
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                currentLength = max(currentLength, dp[predecessor] + 1);
            }
            dp[word] = currentLength;
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }

    // Solution 2: Brute Force (DFS)
    int longestStrChainDFS(vector<string>& words) {
        unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string& word : words) {
            maxLength = max(maxLength, dfs(word, dp));
        }

        return maxLength;
    }

    int dfs(const string& word, unordered_map<string, int>& dp) {
        if (dp.find(word) != dp.end()) {
            return dp[word];
        }

        int currentLength = 1;
        for (int i = 0; i < word.size(); i++) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            if (dp.find(predecessor) != dp.end()) {
                currentLength = max(currentLength, dp[predecessor] + 1);
            }
        }

        dp[word] = currentLength;
        return currentLength;
    }

    int longestStrChain(vector<string>& words) {
        // Uncomment one of the following lines based on the chosen approach
        // return longestStrChainDP(words);
        return longestStrChainDFS(words);
    }
};

int main() {
    Solution solution;
    vector<string> words1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    vector<string> words2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    vector<string> words3 = {"abcd", "dbqca"};

    int result1 = solution.longestStrChain(words1);
    int result2 = solution.longestStrChain(words2);
    int result3 = solution.longestStrChain(words3);

    cout << "Result for Example 1: " << result1 << endl;
    cout << "Result for Example 2: " << result2 << endl;
    cout << "Result for Example 3: " << result3 << endl;

    return 0;
}
