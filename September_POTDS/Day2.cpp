/*
ou are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int solveRec(std::string& s, std::unordered_map<std::string, int>& mp, int index) {
        if (index >= s.size()) return 0;
        
        std::string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++) {
            currStr.push_back(s[cutIdx]);
            
            int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
            int nextExtra = solveRec(s, mp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = std::min(minExtra, totalExtra);
        }
        return minExtra;
    }

    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        std::unordered_map<std::string, int> mp;
        for (std::string& word : dictionary) mp[word]++;
        
        return solveRec(s, mp, 0);
    }
};

int main() {
    Solution solution;

    std::string inputString = "abcdefg";
    std::vector<std::string> dictionary = {"abc", "de", "fg"};

    int result = solution.minExtraChar(inputString, dictionary);

    std::cout << "The minimum number of extra characters to be deleted is: " << result << "\n";

    return 0;
}

/*
Time Complexity (TC):

The minExtraChar function calls the solveRec function, which uses recursion to explore all possible substrings of the input string s and calculate the minimum number of extra characters to be deleted.
In the worst case, the algorithm explores all possible substrings, and the number of recursive calls grows exponentially with the length of the input string.
Therefore, the time complexity is exponential, specifically O(2^n), where 'n' is the length of the input string s. This is because, for each character in the string, you have two choices: include it in the current substring or exclude it.
Space Complexity (SC):

The space complexity is determined by the depth of the recursive call stack, which is influenced by the length of the input string.
In the worst case, the maximum depth of the recursive call stack can be as large as the length of the input string 'n'.
Therefore, the space complexity is O(n) due to the recursive call stack.
In summary:

Time Complexity (TC): O(2^n)
Space Complexity (SC): O(n)
*/