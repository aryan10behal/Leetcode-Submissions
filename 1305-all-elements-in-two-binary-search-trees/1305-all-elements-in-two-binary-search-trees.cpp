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
    void inorder(TreeNode* root,vector<int> &x)
    {
        if(!root)
            return;
        if(root->left)
            inorder(root->left,x);
        x.push_back(root->val);
        if(root->right)
            inorder(root->right,x);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b,c;
        inorder(root1,a);
        inorder(root2,b);
        int x = a.size(),y = b.size();
        int i=0,j=0;
        while(i<x && j<y)
        {
           if(a[i]<b[j])
           {
               c.push_back(a[i]);
               i++;
           }
            else
            {
               c.push_back(b[j]);
               j++;
            }
        }
        while(i<x)
        {
               c.push_back(a[i]);
               i++;
        }
        while(j<y)
        {
            c.push_back(b[j]);
               j++;
        }
        return c;
    }
};