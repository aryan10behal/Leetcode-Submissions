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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int flag = 0;
        while(slow && fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                return NULL;
            fast = fast->next;
            if(slow == fast)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return NULL;
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};