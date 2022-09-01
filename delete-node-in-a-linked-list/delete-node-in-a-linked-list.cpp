/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node, ListNode* prevNode = NULL) {
        if (node->next == NULL) {
            prevNode->next = NULL;
            return;
        };
        
        swap(node->val, node->next->val);
        deleteNode(node->next, node);
        return;
    }
};