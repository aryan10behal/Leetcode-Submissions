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
    void inorder(TreeNode* root, vector<long long> &l, vector<long long> &r, long long lvl, long long x)
    {
        if(root == NULL)
            return;
        if(l.size() <= lvl)
        {
            l.push_back(x);
            r.push_back(x);
        }
        else
        {
            l[lvl] = min(l[lvl], x);
            r[lvl] = max(r[lvl], x);
        }
        x -= l[lvl];
        inorder(root->left, l, r, lvl+1, 2*x);
        inorder(root->right, l, r, lvl+1, 2*x+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<long long> l, r;
        long long lvl = 0, rightness = 0;
        inorder(root, l, r, lvl, rightness);
        long long ans = 0;
        for(int i=0;i<l.size();i++)
        {
            //cout<<l[i]<<" "<<r[i]<<endl;
            ans = max(ans, r[i]-l[i]+1);
        }
        return ans;
    }
};