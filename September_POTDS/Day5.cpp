/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

*/

#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Create a mapping from original nodes to their corresponding new nodes
        std::unordered_map<Node*, Node*> nodeMap;

        // Create new nodes and map them to original nodes
        Node* newHead = new Node(head->val);
        nodeMap[head] = newHead;

        Node* originalCurr = head;
        Node* newCurr = newHead;

        // Copy the next pointers
        while (originalCurr->next) {
            newCurr->next = new Node(originalCurr->next->val);
            originalCurr = originalCurr->next;
            newCurr = newCurr->next;
            nodeMap[originalCurr] = newCurr;
        }

        // Copy the random pointers using the mapping
        originalCurr = head;
        newCurr = newHead;
        while (originalCurr) {
            if (originalCurr->random) {
                newCurr->random = nodeMap[originalCurr->random];
            }
            originalCurr = originalCurr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};

// Function to print the cloned linked list
void printList(Node* head) {
    while (head) {
        std::cout << "Node " << head->val << " -> ";
        if (head->random) {
            std::cout << "Random Node " << head->random->val;
        } else {
            std::cout << "Random Node: nullptr";
        }
        std::cout << std::endl;
        head = head->next;
    }
}

int main() {
    Solution solution;
    Node* head = nullptr;

    // Input: 1 -> 2 -> 3
    // Random pointers: 1 -> 3, 2 -> 1, 3 -> 2
    // Expected Output: Cloned list with the same structure and random pointers
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    Node* clonedHead = solution.copyRandomList(head);

    std::cout << "Original Linked List with Random Pointers:" << std::endl;
    printList(head);

    std::cout << "Cloned Linked List with Random Pointers:" << std::endl;
    printList(clonedHead);

    return 0;
}


/*
Time Complexity (TC):

Copying Next Pointers: In the first while loop, the code iterates through the original linked list and creates a new node for each node in the original list. This loop has a linear time complexity O(N), where N is the number of nodes in the original linked list.

Copying Random Pointers: In the second while loop, the code iterates through the original linked list again to copy the random pointers. This loop also has a linear time complexity O(N) because it goes through each node once.

Overall, the time complexity of the solution is O(N), where N is the number of nodes in the original linked list.

Space Complexity (SC):

Node Mapping: The solution uses an unordered_map to map each original node to its corresponding new node. The space required for this mapping is O(N), as there can be a one-to-one mapping for each node in the original list.

New Linked List: The solution creates a new linked list with the same number of nodes as the original list. Therefore, the space required for the new linked list is also O(N).

Auxiliary Space: Apart from the space used for the mapping and the new linked list, there is also some auxiliary space used for variables and temporary pointers. However, this space is relatively small and constant with respect to the size of the input.

Overall, the space complexity of the solution is O(N) due to the space used for the node mapping and the new linked list.
*/