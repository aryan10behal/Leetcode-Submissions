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
    pair<int, int> trav(TreeNode* root, int &ans)
    {
        if(root == NULL)
            return {-1001, 0};
        pair<int, int> a = trav(root->left, ans);
        pair<int, int> b = trav(root->right, ans);
        int d = 0, e = 1;
        if(a.first == root->val)
        {
            d = a.second;
            e += a.second;
        }
        if(b.first == root->val)
        {
            d = max(d, b.second);
            e += b.second;
        }
        ans = max(ans, e);
        return {root->val, d+1};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        trav(root, ans);
        return ans-1;
    }
};