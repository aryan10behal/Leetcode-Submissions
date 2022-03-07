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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
            ListNode* bt = l1;
            ListNode* rt = l2;
            ListNode* prev = ans;
            while(bt && rt)
            {
                if(bt->val <= rt->val)
                {
                    prev->next = bt;
                    prev = bt;
                    bt = bt->next;
                }
                else
                {
                    prev->next = rt;
                    prev = rt;
                    rt = rt->next;
                }
            }
            if(bt)
            {
               prev->next = bt;
            }
            else
            {
                prev->next = rt;
            }
            return (ans->next);
    }
};