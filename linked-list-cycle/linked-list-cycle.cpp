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
    bool hasCycle(ListNode *head) {
        ListNode *oneStepForward = head, *twoStepForward = head;
        while(twoStepForward != NULL && twoStepForward->next != NULL) {
            twoStepForward = twoStepForward->next->next;
            oneStepForward = oneStepForward->next;
            
            if (twoStepForward == oneStepForward) return true;
        }
        
        return false;
    }
};