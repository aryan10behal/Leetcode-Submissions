/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* perform(vector<int> &nums, int l, int h)
    {
        if(l>h)
            return NULL;
        int m = (l+h)/2;
        return new TreeNode(nums[m], perform(nums, l, m-1), perform(nums, m+1, h));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return perform(nums,0, nums.size()-1);
    }
};