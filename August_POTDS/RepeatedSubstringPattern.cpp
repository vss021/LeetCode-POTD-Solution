#include <iostream>
#include <string>
using namespace std;

/*
Given a string s, check if it can be constructed by taking a substring of it and 
appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /* Method 1. TC => O(N*N) in bust case O(NlogN) Avg. case
        int n = s.size();
        // Check all possible lengths of substrings that can form 's'.
        for (int len = 1; len <= n / 2; len++) {
            // If 'len' evenly divides 'n', consider it as a possible substring length.
            if (n % len == 0) {
                string substring = s.substr(0, len); // Get the potential substring.
                string reconstructed = ""; // Reconstruct the string using the substring.
                
                for (int i = 0; i < n / len; i++) {
                    reconstructed += substring;
                }
                
                if (reconstructed == s) {
                    return true; // If the reconstructed string matches 's', return true.
                }
            }
        }
        
        return false; // No repeating substring found.
        */

        int n=s.size();
        for(int i=n/2;i>=1;i--){                
            //commented below
            if(n%i==0){                                                             
            //i is expressing the size of the substring forming-->if length of the substring(i.e, i) divides n equally then we can say the substring can be/may be a possible solution,so we check further,else we skip.
                if(s.substr(0,n-i)==s.substr(i))return true;           //rotation approach-->if two substrings from first and last match then we can say they can repeatedly form the string.
            }
        }
        return false;
    
    }

};

int main() {
    Solution solution;

    // Test cases
    string test1 = "abab"; // Repeating substring "ab"
    string test2 = "abcabcabc"; // Repeating substring "abc"
    string test3 = "abcd"; // No repeating substring

    bool result1 = solution.repeatedSubstringPattern(test1);
    bool result2 = solution.repeatedSubstringPattern(test2);
    bool result3 = solution.repeatedSubstringPattern(test3);

    cout << "Test 1: " << (result1 ? "True" : "False") << endl;
    cout << "Test 2: " << (result2 ? "True" : "False") << endl;
    cout << "Test 3: " << (result3 ? "True" : "False") << endl;

    return 0;
}
