/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
 ans[i] is the number of 1's in the binary representation of i.

 */

 #include <iostream>
#include <vector>

class Solution {
public:

    // Helper function to count the number of set bits (1s) in binary representation of a number
    int countSetBits(int x)
    {
        int countOnes = 0;

        // Iterate through each bit of 'x'
        while (x)
        {
            int remainder = x % 2;

            // If the remainder is 1, increment the count of ones
            if (remainder == 1)
                countOnes++;

            // Right-shift 'x' to check the next bit
            x /= 2;
        }

        return countOnes;
    }

    // Function to count set bits for numbers from 0 to 'n'
    std::vector<int> countBits(int n) {

        if (n == 0)
            return {0};

        if (n == 1)
            return {0, 1};

        std::vector<int> result;

        result.push_back(0); // Initialize the count for 0 (0'th index)
        result.push_back(1); // Initialize the count for 1 (1'th index)

        // Calculate the count of set bits for numbers from 2 to 'n'
        for (int i = 2; i <= n; i++)
        {
            result.push_back(countSetBits(i)); // Add the count of set bits to the result
        }

        return result;
    }
};

int main() {
    Solution solution;

    int n = 5; // You can change 'n' to test different values

    std::vector<int> result = solution.countBits(n);

    // Print the count of set bits for numbers from 0 to 'n'
    std::cout << "Count of set bits for numbers from 0 to " << n << ": ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
