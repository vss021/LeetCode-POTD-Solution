/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 
*/

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    // Helper function to get the size of the linked list
    /*
    Time Complexity (TC):

getSize() Function: The getSize() function iterates through the entire linked list once, which takes O(N) time, where N is the number of nodes in the linked list.

splitListToParts() Function:

The code iterates through the linked list in a loop that runs k times. In each iteration, it iterates through a portion of the linked list. The total number of iterations across all loops is still proportional to N, the number of nodes in the list.
In each iteration of the outer loop, the code iterates through a portion of the linked list to determine the size of the current part. This inner loop also takes O(N) time in total.
Therefore, the overall time complexity of the splitListToParts() function is O(N + k*N), which simplifies to O(N).

Space Complexity (SC):

Result Vector: The result vector stores the pointers to the head nodes of the split linked lists. The size of this vector is k, which is the number of parts into which the list is split. Therefore, the space required for the result vector is O(k).

Helper Variables: The code uses a few helper variables such as size, baseSize, extraNodes, temp, and prev. These variables use constant space, and their space requirements are not dependent on the size of the input linked list.

No Additional Data Structures: The code does not use any additional data structures that scale with the size of the linked list.

Therefore, the overall space complexity of the code is O(k), where k is the number of parts into which the list is split.
    */
    int getSize(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    
    vector<ListNode*> splitListToParts1(ListNode* head, int k) {
        vector<ListNode*> result;
        int size = getSize(head);

        int baseSize = size / k;
        int extraNodes = size % k;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; i++) {
            result.push_back(temp);

            // Calculate the size of the current part
            int partSize = baseSize + (extraNodes > 0 ? 1 : 0);

            // Traverse the linked list to the end of the current part
            for (int j = 0; j < partSize; j++) {
                prev = temp;
                temp = temp->next;
            }

            // Set the next pointer of the previous part to nullptr
            if (prev != nullptr) {
                prev->next = nullptr;
            }

            // Decrement the count of extra nodes if applicable
            if (extraNodes > 0) {
                extraNodes--;
            }
        }

        return result;
    }

    // Function to split a linked list into k parts
    /*
    The time complexity remains O(N), 
    The space complexity is O(k), 
    which is the best you can achieve for this problem.
    */ .
    vector<ListNode*> splitListToParts2(ListNode* head, int k) {
        // Create a vector to store the split parts (initialized with nullptr)
        vector<ListNode*> result(k, nullptr);

        // Calculate the total size of the linked list
        int size = 0;
        ListNode* current = head;
        while (current) {
            size++;
            current = current->next;
        }

        // Calculate the base size and the number of extra nodes in each part
        int baseSize = size / k;
        int extraNodes = size % k;

        // Reset the current pointer to the beginning of the linked list
        current = head;

        // Iterate through each part and split the linked list
        for (int i = 0; i < k; i++) {
            result[i] = current;

            // Calculate the size of the current part
            int partSize = baseSize + (i < extraNodes ? 1 : 0);

            // Traverse to the end of the current part
            for (int j = 0; j < partSize - 1; j++) {
                current = current->next;
            }

            // Update the next pointer of the current part's end node
            if (current) {
                ListNode* next = current->next;
                current->next = nullptr;
                current = next;
            }
        }

        return result;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 3; // Number of parts to split the list into

    // Split the linked list into k parts
    vector<ListNode*> result = solution.splitListToParts(head, k);

    // Print the resulting lists
    for (ListNode* part : result) {
        printList(part);
    }

    return 0;
}
