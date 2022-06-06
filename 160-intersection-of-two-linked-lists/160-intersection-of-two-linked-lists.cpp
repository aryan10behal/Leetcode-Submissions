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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x = 0, y = 0;
        ListNode* a = headA, *b = headB;
        while(a)
        {
            x++;
            a=a->next;
        }
        while(b)
        {
            y++;
            b=b->next;
        }
        if(x>y)
        {
            while(x>y)
            {
                headA = headA->next;
                x--;
            }
        }
        else
        {
             while(y>x)
            {
                headB = headB->next;
                y--;
            }
        }
        while(headA && headB)
        {
            if(headA==headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};