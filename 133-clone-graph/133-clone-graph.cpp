/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void clone(Node* a, Node* node, map<Node*, Node*> &m)
    {
        for(int i = 0;i<node->neighbors.size(); i++)
        {
            if(m.find(node->neighbors[i]) == m.end())
            {
                Node* x = new Node(node->neighbors[i]->val);
                a->neighbors.push_back(x);
                m[node->neighbors[i]] = x;
                clone(x, node->neighbors[i], m);
            }
            else
            {
                a->neighbors.push_back(m[node->neighbors[i]]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        map<Node*, Node*> m;
        Node* a = new Node(node->val);
        m[node] = a;
        clone(a, node, m);
        return a;
    }
};