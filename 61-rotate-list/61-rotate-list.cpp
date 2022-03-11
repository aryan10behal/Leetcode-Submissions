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
    ListNode* rotateRight(ListNode* head, int k) {
        int n  = 0;
        if(head == NULL)
            return head;
        ListNode* x = head;
        while(x)
        {
            n++;
            x = x->next;
        }
        k = k%n;
        if(k == 0)
            return head;
        x = head;
        ListNode* prev=x;
        while(n!=k)
        {
            n--;
            prev = x;
            x = x->next;
        }
        prev->next = NULL;
        prev = x;
        while(x->next)
        {
            x = x->next;
        }
        x->next = head;
        return prev;
    }
};