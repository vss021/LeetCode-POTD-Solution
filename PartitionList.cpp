#include <iostream>
/* 
Q. 
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes 
greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
*/
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* less = new ListNode(0);
        ListNode* ltail = less;

        ListNode* greaterEqual = new ListNode(0);
        ListNode* geTail = greaterEqual;

        while (head != nullptr) {
            if (head->val < x) {
                ListNode* temp = new ListNode(head->val);
                ltail->next = temp;
                ltail = temp;
            } else {
                ListNode* temp = new ListNode(head->val);
                geTail->next = temp;
                geTail = temp;
            }
            head = head->next;
        }

        ltail->next = greaterEqual->next;
        ListNode* result = less->next;

        // Clean up memory allocated for the temporary nodes
        delete less;
        delete greaterEqual;

        return result;
    }
};

// Function to create a linked list from user input
ListNode* createLinkedListFromInput() {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    std::cout << "Enter values for the linked list (-1 to terminate): ";
    int val;
    while (std::cin >> val && val != -1) {
        if (head == nullptr) {
            head = new ListNode(val);
            current = head;
        } else {
            current->next = new ListNode(val);
            current = current->next;
        }
    }
    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createLinkedListFromInput();

    int x;
    std::cout << "Enter a value for partitioning: ";
    std::cin >> x;

    Solution solution;
    ListNode* partitioned = solution.partition(head, x);

    // Print the partitioned linked list
    std::cout << "Partitioned Linked List: ";
    printList(partitioned);

    // Clean up memory allocated for the linked list
    while (partitioned != nullptr) {
        ListNode* temp = partitioned;
        partitioned = partitioned->next;
        delete temp;
    }

    return 0;
}
