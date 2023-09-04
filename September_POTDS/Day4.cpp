/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false; // If the list is empty or has only one node, there can be no cycle.
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;       // Move slow one step.
            fast = fast->next->next; // Move fast two steps.

            if (slow == fast) {
                return true; // If they meet, there is a cycle.
            }
        }

        return false; // If we reach this point, there is no cycle.
    }
};

int main() {
    Solution solution;

    // Create a linked list without a cycle
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);

    bool hasCycle1 = solution.hasCycle(list1);
    std::cout << "List 1 has a cycle: " << std::boolalpha << hasCycle1 << std::endl;

    // Create a linked list with a cycle
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = list2->next; // Create a cycle

    bool hasCycle2 = solution.hasCycle(list2);
    std::cout << "List 2 has a cycle: " << std::boolalpha << hasCycle2 << std::endl;

    // Clean up memory (optional)
    delete list1;
    delete list2;

    return 0;
}
