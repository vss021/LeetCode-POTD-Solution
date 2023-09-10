/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to generate Pascal's Triangle using brute force
    vector<vector<int>> generatePascalsTriangleBruteForce(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize each row with 1s.

            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }

    // Function to generate Pascal's Triangle using a single vector
    vector<vector<int>> generatePascalsTriangleSingleVector(int numRows) {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize each row with 1s.

            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }

    // Function to generate Pascal's Triangle using the combinations formula
    vector<vector<int>> generatePascalsTriangleCombinations(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1);

            for (int j = 0; j <= i; ++j) {
                row[j] = binomialCoefficient(i, j);
            }

            triangle.push_back(row);
        }

        return triangle;
    }

private:

    int binomialCoefficient(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        } else {
            return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
        }
    }
};

// Helper function to print Pascal's Triangle
void printPascalsTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    int numRows = 5;  // Number of rows to generate in Pascal's Triangle

    // Generate Pascal's Triangle using brute force
    vector<vector<int>> triangleBruteForce = solution.generatePascalsTriangleBruteForce(numRows);
    cout << "Pascal's Triangle (Brute Force Method):\n";
    printPascalsTriangle(triangleBruteForce);

    // Generate Pascal's Triangle using a single vector
    vector<vector<int>> triangleSingleVector = solution.generatePascalsTriangleSingleVector(numRows);
    cout << "Pascal's Triangle (Single Vector Method):\n";
    printPascalsTriangle(triangleSingleVector);

    // Generate Pascal's Triangle using the combinations formula
    vector<vector<int>> triangleCombinations = solution.generatePascalsTriangleCombinations(numRows);
    cout << "Pascal's Triangle (Combinations Method):\n";
    printPascalsTriangle(triangleCombinations);

    return 0;
}


/*
Method 1: Generate Pascal's Triangle using Brute Force (TC: O(N^2), SC: O(N^2))

Time Complexity (TC): The outer loop runs for numRows iterations, and for each row, there is an inner loop that iterates over the elements in that row. Since each row has an average of N/2 elements (where N is the row number), the total number of iterations in the inner loop is roughly 1/2 * numRows * numRows, which simplifies to O(N^2) in Big O notation.
Space Complexity (SC): The space complexity is O(N^2) because we are storing all elements of the generated Pascal's Triangle in a 2D vector.
Method 2: Generate Pascal's Triangle using a Single Vector (TC: O(N^2), SC: O(N^2))

Time Complexity (TC): Similar to the brute force method, the time complexity is O(N^2) because we still have to generate all elements in the triangle.
Space Complexity (SC): The space complexity is O(N^2) because we are storing all elements of the generated Pascal's Triangle in a 2D vector. While we use a single vector for each row, the total number of elements is still the same.
Method 3: Generate Pascal's Triangle using the Combinations Formula (TC: O(N^2), SC: O(N^2))

Time Complexity (TC): This method also has a time complexity of O(N^2) because we need to compute binomial coefficients for each element in the triangle, and there are roughly N^2 elements in total.
Space Complexity (SC): The space complexity is O(N^2) because we are storing all elements of the generated Pascal's Triangle in a 2D vector.
All three methods have the same time and space complexity of O(N^2) because they generate the same number of elements in Pascal's Triangle, and each element requires a constant amount of computation and storage.

*/
