
/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 
Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative Approach
    ListNode* reverseBetweenIterative(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre_it = dummy;
        ListNode* it = head;

        // Traverse until left index
        for (int i = 1; i < left; i++) {
            pre_it = it;
            it = it->next;
        }

        reverseSegment(pre_it, it, right - left + 1);

        return dummy->next;
    }

    // Recursive Approach
    ListNode* reverseBetweenRecursive(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre_it = dummy;
        ListNode* it = head;

        // Traverse until left index
        for (int i = 1; i < left; i++) {
            pre_it = it;
            it = it->next;
        }

        reverseSegment(pre_it, it, right - left + 1);

        return dummy->next;
    }

    void reverseSegment(ListNode* pre_it, ListNode* it, int count) {
        ListNode* pre_R = nullptr;
        ListNode* itR = it;

        while (count > 0) {
            ListNode* forward = itR->next;
            itR->next = pre_R;
            pre_R = itR;
            itR = forward;
            count--;
        }

        pre_it->next = pre_R;
        it->next = itR;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    cout << "Original Linked List: ";
    printList(head);

    // Test the iterative approach
    ListNode* reversedIterative = solution.reverseBetweenIterative(head, left, right);
    cout << "Reversed (Iterative) Linked List: ";
    printList(reversedIterative);

    // Create a sample linked list again
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Test the recursive approach
    ListNode* reversedRecursive = solution.reverseBetweenRecursive(head, left, right);
    cout << "Reversed (Recursive) Linked List: ";
    printList(reversedRecursive);

    return 0;
}


/*

Iterative Approach:

Time Complexity (TC): O(N), where N is the number of nodes in the linked list. This is because we traverse the linked list once from the beginning to the left index and then once more for the subsegment between left and right. The reverse operation takes linear time in the size of the subsegment.
Space Complexity (SC): O(1), as we use a constant amount of extra space to store only a few pointers and variables. The space complexity is independent of the size of the input linked list.
Recursive Approach:

Time Complexity (TC): O(N), where N is the number of nodes in the linked list. The recursive approach also traverses the linked list twice in total: once to reach the left index and then once more for the subsegment between left and right. The recursive calls do not add extra time complexity because each node is visited only once.
Space Complexity (SC): O(N) in the worst case due to the recursion stack. This is because the recursion depth can be at most N nodes, corresponding to the length of the input linked list. Each function call consumes space on the stack, so the space complexity is linear in the size of the input.
*/

