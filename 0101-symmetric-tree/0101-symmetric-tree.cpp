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
    bool check(TreeNode* a, TreeNode* b)
    {
        if(a == NULL && b == NULL)
            return true;
        if((a == NULL && b!= NULL) || (a!=NULL && b==NULL))
            return false;
        return check(a->left, b->right) && check(a->right, b->left) && a->val == b->val;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};