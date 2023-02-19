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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> arr;
        vector<vector<int>> ff;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        if(root!=NULL)
        {
            q.push({root,0});
            map<int,int> m,fir;
            vector<int> v;
            int lvl=0;
            while(q.size())
            {
                p=q.front();
                q.pop();

                v.push_back(p.first->val);
                if(fir.find(p.second)==fir.end())
                    fir[p.second]=v.size()-1;
                m[p.second]=v.size()-1;

                if(p.second>lvl)
                    lvl=p.second;


                if(p.first->left!=NULL)
                    q.push({p.first->left,p.second+1});
                if(p.first->right!=NULL)
                    q.push({p.first->right,p.second+1});
            }
            cout<<endl;
            int x=0,l,r;
            int i=0,toggle=0;
            while(fir.find(x)!=fir.end())
            {
                vector<int> gg;
                l=fir[x];
                r=m[x];
                if(toggle==0)
                {
                    for(int t=l;t<=r;t++)
                    {
                        gg.push_back(v[t]);
                    }
                    ff.push_back(gg);
                    toggle=1;
                }
                else
                {
                    for(int t=r;t>=l;t--)
                         gg.push_back(v[t]);
                    ff.push_back(gg);
                    toggle=0;
                }
                x++;
            }
        }  
        return ff;
    }
};