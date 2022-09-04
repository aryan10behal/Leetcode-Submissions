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
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second < b.second)
            return true;
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return false;
    }
    void trav(TreeNode* root, map<int, vector<pair<int, int>>> &mp, int lvl, int depth)
    {
        if(root == NULL)
            return;
        mp[lvl].push_back({root->val, depth});
        trav(root->left, mp, lvl-1, depth+1);
        trav(root->right, mp, lvl+1, depth+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        trav(root, mp, 0, 0);
        vector<vector<int>> x;
        for(auto a: mp)
        {
            sort(a.second.begin(), a.second.end(), comp);
            vector<int> g;
            for(pair<int, int> v: a.second)
            {
                //cout<<v.first<<" "<<v.second<<endl;
                g.push_back(v.first);
            }
            x.push_back(g);
        }
        return x;
    }
};