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
    ListNode* merge(ListNode* slow, ListNode* fast)
    {
        if(slow == NULL)
            return fast;
        if(fast == NULL)
            return slow;
        ListNode* f = NULL;
        if(slow->val < fast->val)
        {
            f = slow;
            f->next = merge(slow->next, fast);
        }
        else
        {
            f = fast;
            f->next = merge(slow, fast->next);
        }
        return f;
    }
    ListNode* sort(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* slow = head, *fast = head, *prev = head;
        while(slow && fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(!fast)
                break;
            fast = fast->next;
        }
        prev->next = NULL;
        head = sort(head);
        slow = sort(slow);
        return merge(head, slow);
    }
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};