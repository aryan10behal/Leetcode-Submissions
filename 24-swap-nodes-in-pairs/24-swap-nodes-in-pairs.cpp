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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* m = head, *n = head->next, *x = new ListNode(1);
        if(n==NULL)
            return head;
        head = n;
        while(m && n)
        {
            x->next = n;
            m->next = n->next;
            n->next = m;
            x=m;
            m = m->next;
            if(m == NULL)
                break;
            n = m->next;
        }
        return head;
    }
};