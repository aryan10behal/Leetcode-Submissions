/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push(root);
        while(q.size())
        {
            int n = q.size(), i=0;
            vector<int> val(n);
            while(i<n)
            {
                val[i++] = q.front()->val;
                for(Node* x: q.front()->children)
                {
                    if(x!=NULL)
                        q.push(x);
                }
                q.pop();
            }
            ans.push_back(val);
        }
        return ans;
    }
};