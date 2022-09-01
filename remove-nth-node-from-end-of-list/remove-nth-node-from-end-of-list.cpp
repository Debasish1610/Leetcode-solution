/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int removeNode(ListNode* node, ListNode* prevNode, int n) {
        if (node == nullptr) {
            return 0;
        }
        
        int countNodeFromEnd = removeNode(node->next, node, n) + 1;
        
        if (n == countNodeFromEnd) {
            if (prevNode == NULL) return -1;
            else {
                prevNode->next = node->next;
            }
        }
        
        return countNodeFromEnd;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (removeNode(head, NULL, n) == -1) {
            return head->next;
        } else {
            return head;
        }
    }
};