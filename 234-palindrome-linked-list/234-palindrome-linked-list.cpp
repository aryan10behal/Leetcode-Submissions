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
    bool find(ListNode* &head, ListNode* tail)
    {
        if(tail == NULL)
            return true;
        bool a = find(head, tail->next);
        if(a == false)
            return false;
        a &= (head->val == tail->val);
        head = head->next;
        return a;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* t = head;
        ListNode* x = head;
        return find(head, head);
    }
};