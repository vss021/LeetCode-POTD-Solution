/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Solution 1: Two-Pointer Approach
    bool isSubsequenceTwoPointer(string s, string t) {
        int sPtr = 0, tPtr = 0;
        int sLen = s.length(), tLen = t.length();

        while (sPtr < sLen && tPtr < tLen) {
            if (s[sPtr] == t[tPtr]) {
                sPtr++;
            }
            tPtr++;
        }

        return sPtr == sLen;
    }

    // Solution 2: Dynamic Programming
    bool isSubsequenceDP(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(tLen + 1, false));

        // Initialize the first row
        for (int j = 0; j <= tLen; j++) {
            dp[0][j] = true;
        }

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= tLen; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[sLen][tLen];
    }

    // Solution 3: Recursive Approach
    bool isSubsequenceRecursive(string s, string t, int sPtr, int tPtr) {
        if (sPtr == s.length()) {
            return true;
        }
        if (tPtr == t.length()) {
            return false;
        }

        if (s[sPtr] == t[tPtr]) {
            return isSubsequenceRecursive(s, t, sPtr + 1, tPtr + 1);
        } else {
            return isSubsequenceRecursive(s, t, sPtr, tPtr + 1);
        }
    }

    bool isSubsequence(string s, string t) {
        // Uncomment one of the following lines based on the chosen approach
        // return isSubsequenceTwoPointer(s, t);
        // return isSubsequenceDP(s, t);
        return isSubsequenceRecursive(s, t, 0, 0);
    }
};

int main() {
    Solution solution;
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";

    bool result1 = solution.isSubsequence(s1, t1);
    bool result2 = solution.isSubsequence(s2, t2);

    cout << "Result for Example 1: " << result1 << endl;
    cout << "Result for Example 2: " << result2 << endl;

    return 0;
}
