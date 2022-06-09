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
        int c = 1, d = 0, e = 1;
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
        c+=d;
        ans = max(ans, c);
        ans = max(ans, e);
        //cout<<root->val<<" "<<c<<endl;
        return {root->val, c};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        trav(root, ans);
        return ans-1;
    }
};