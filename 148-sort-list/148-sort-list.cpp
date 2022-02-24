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
    // ListNode* sort(ListNode* head)
    // {
    //     if(head == NULL)
    //         return NULL;
    //     if(head->next == NULL)
    //         return head;
    //     if(head->next->next == NULL)
    //     {
    //         if(head->next->val > head->val)
    //         {
    //             head->next 
    //         }
    //     }
    // }
    ListNode* sortList(ListNode* head) {
        // return sort(head);
        vector<int> arr;
        ListNode* x = head;
        while(x)
        {
            arr.push_back(x->val);
            x = x->next;
        }
        sort(arr.begin(), arr.end());
        x = head;
        int i = 0;
        while(x)
        {
            x->val = arr[i++];
            x = x->next;
        }
        return head;
    }
};