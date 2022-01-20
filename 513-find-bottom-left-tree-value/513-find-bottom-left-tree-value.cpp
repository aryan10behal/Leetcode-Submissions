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
    void trav(TreeNode* root, long long height, long long &ans, long long &f)
    {
        if(root==NULL)
            return;
        if(root->left == NULL && height>f)
        {
                ans = root->val;
                f  = height;
        }
        else
            trav(root->left, height+1, ans, f);
        trav(root->right, height+1, ans, f);
    }
    int findBottomLeftValue(TreeNode* root) {
        long long height = 0, ans = -1e14, f = -1;
        trav(root, height, ans, f);
        return ans;
    }
};