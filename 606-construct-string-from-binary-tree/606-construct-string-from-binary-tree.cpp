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
    void add_to_string(int val, string &a)
    {
        if(val < 0)
        {
            a += '-';
            val = abs(val);
        }
        string x ="";
        if(val == 0)
        { a+= '0'; return;}
    
        while(val!=0)
        {
            x += (char)((val%10) + 48);
            val /=10;
        }
        for(int i = x.size()-1;i>=0;i--)
        {
            a += x[i];
        }
    }
    void make(TreeNode* root, string &a)
    {
        if(root==NULL)
        {
            a += '(';
            a += ')';
        }
        a += '(';
        add_to_string(root->val,a);
        if(!root->left && !root->right)
        {
            a += ')';
        }
        else
        {
            if(root->left)
                make(root->left,a);
            else
            {
                a += '(';
                a += ')';
            }
            if(root->right)
                make(root->right,a);
            a += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string a="";
        make(root,a);
        string b = "";
        for(int i=1;i<a.size()-1;i++)
            b+=a[i];
        return b;
    }
};