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
    ListNode *head = NULL;
public:
    void sortTwoList(ListNode *l1,ListNode *l2)
    {
        ListNode *prev = NULL,*node = NULL;
        while(l2 != NULL)
        {
            node = new ListNode(l2->val);
            if(head == NULL)
            {
                head = node;
                l2 = l2->next;
                prev = head;
            }
            else
            {
                while(l1 != NULL)
                {
                    if(l2->val < l1->val)
                    {
                        if(prev == NULL)
                        {
                            node->next = head;
                            head = node;
                            prev = node;
                        }
                        else
                        {
                            node->next = l1;
                            prev->next = node;
                            prev = node;
                        }
                        break;
                    }
                    prev = l1;
                    l1 = l1->next;
                }
                if(l1 == NULL)
                {
                    prev->next = node;
                    prev = node;
                }
                l2 = l2->next;
            }
            
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i=0;i<lists.size();i++)
        {
            sortTwoList(head,lists[i]);
        }
        return head;
    }
};