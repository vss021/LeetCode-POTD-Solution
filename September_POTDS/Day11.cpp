/*
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

 

Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {

public:

    vector<vector<int>>  groupThePeopleUsingMap(vector<int>&group)
    {
        vector<vector<int>> result;  // Initialize the result vector to store groups.

        unordered_map<int, vector<int>> mp;  // Create a map to associate group numbers with people.

        int n = group.size();  // Get the number of people.

        for (int i = 0; i < n; i++) {
            if (mp.find(group[i]) == mp.end()) { // Check if the group is not present in the map.
                vector<int> people;
                people.push_back(i);  // Create a new group and add the current person.
                mp[group[i]] = people;  // Store the group in the map.
            } 
            else { // Group is present in the map.
                vector<int> people = mp[group[i]];  // Get the list of people in the current group.

                if (people.size() == group[i]) { // If the group is full.
                    result.push_back(people);  // Add the group to the result.
                    mp[group[i]].clear();  // Clear the group from the map.

                    // Add the current person to a new group.
                    people.erase(begin(people), end(people));
                    people.push_back(i);
                    mp[group[i]] = people;
                } 
                else { // Group is not full.
                    people.push_back(i);  // Add the current person to the group.
                    mp[group[i]] = people;  // Update the group in the map.
                }
            }
        }

        // Add any remaining groups to the final result.
        for (auto it : mp) {
            if (!it.second.empty()) {
                result.push_back(it.second);
            }
        }

        return result;
    }

   vector<vector<int>> groupThePeopleUsingMinHeap(vector<int>& groupSizes){

       vector<vector<int>> result;

    //    min-heap creation
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Initialize the min-heap with group numbers and their corresponding indices.
        for (int i = 0; i < groupSizes.size(); i++) {
            minHeap.push({groupSizes[i], i});
        }

        vector<int> currentGroup; // To keep track of the current group.

        while (!minHeap.empty()) {
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int groupSize = entry.first;
            int index = entry.second;

            currentGroup.push_back(index); // Add the current person to the current group.

            if (currentGroup.size() == groupSize) {
                result.push_back(currentGroup); // Add the current group to the result.
                currentGroup.clear(); // Clear the current group.
            }
        }

        return result;
   } 





    
};


// Utility function to print a vector of vectors
void printResult(const vector<vector<int>>& result) {
    for (const auto& group : result) {
        for (int person : group) {
            cout << person << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<int> group = {3, 3, 3, 3, 3, 1, 3};
    
    int choice;

    cout << "Menu:" << endl;
    cout << "1. Run solution using unordered_map" << endl;
    cout << "2. Run solution using min-heap" << endl;
    cout << "3. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Running solution using unordered_map:" << endl;
                // Run the unordered_map-based solution
                printResult(solution.groupThePeopleUsingMap(group));
                break;

            case 2:
                cout << "Running solution using min-heap:" << endl;
                // Run the min-heap-based solution
                printResult(solution.groupThePeopleUsingMinHeap(group));
                break;

            case 3:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
