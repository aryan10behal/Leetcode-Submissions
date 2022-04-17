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
    vector<int> v;
public:
    void F(TreeNode* root)
    {
       if(root!=NULL)
       {
         v.push_back(root->val);
           F(root->left);
           F(root->right);
       }    
    }
    TreeNode* makelist()
    {
        TreeNode* f=new TreeNode(v[0]);
        TreeNode* x=f;
        for(int i=1;i<v.size();i++)
        {
            x->right=new TreeNode(v[i]);
            x=x->right;
        }
        return f;
    }
    TreeNode* increasingBST(TreeNode* root) {
        F(root);
        sort(v.begin(),v.end());
        return makelist();
    }
};