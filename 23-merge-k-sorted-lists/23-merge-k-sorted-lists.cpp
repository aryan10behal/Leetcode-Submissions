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
    ListNode* merge(ListNode* x, ListNode* y)
    {
        if(x==NULL)
            return y;
        if(y==NULL)
            return x;
        ListNode* z = new ListNode(0);
        ListNode* b = z;
         if(x->val < y->val)
            {
                z = x;
                x = x->next; 
            }
            else
            {
                z = y;
                y = y->next;
            }
        b = z;
        while(x && y)
        {
            if(x->val < y->val)
            {
                z->next = x;
                x = x->next; 
            }
            else
            {
                z->next = y;
                y = y->next;
            }
            z = z->next;
        }
        while(x)
        {
           z->next = x;
           x = x->next;
           z = z->next;
        }
        while(y)
        {
           z->next = y;
           y = y->next;
           z = z->next;
        }
        return b;
    }
    ListNode* sorting(vector<ListNode*>& lists, int l, int h)
    {
        if(l>h)
            return NULL;
        if(l==h)
            return lists[l];
        if(l+1 == h)
        {
            return merge(lists[l], lists[h]);
        }
        int mid = (l+h)/2;
        ListNode* x = sorting(lists, l, mid);
        ListNode* y = sorting(lists, mid+1, h);
        ListNode* z = merge(x, y);
        return z;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = 0, h = lists.size()-1;
        return sorting(lists, l, h);
    }
};