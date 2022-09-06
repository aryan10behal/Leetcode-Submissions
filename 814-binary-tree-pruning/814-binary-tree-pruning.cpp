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
    int prune(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int x = prune(root->left);
        int y = prune(root->right);
        if(x == 0)
            root->left = NULL;
        if(y == 0)
            root->right = NULL;
        return x + y + (root->val == 1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return root;
        return prune(root) == 0?NULL:root;
    }
};