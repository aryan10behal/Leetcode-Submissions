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
    int n;
    vector<int> v;
    Solution(ListNode* head) {
        srand(time(0));
        n = 0;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        n = v.size();
    }
    
    int getRandom() {
        int x = rand()%n;
        return v[x];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */