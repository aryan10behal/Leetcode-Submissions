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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* a = new ListNode(0);
        ListNode* b = a;
        while(head)
        {
            int val = head->val;
            ListNode* x = head;
            int c = 0;
            while(head)
            {
                if(val == head->val)
                    c++;
                else
                    break;
                head = head->next;
            }
            if(c == 1)
            {
                a->next = x;
                a = a->next;
                a->next = NULL;
            }
        }
        return b->next;
    }
};