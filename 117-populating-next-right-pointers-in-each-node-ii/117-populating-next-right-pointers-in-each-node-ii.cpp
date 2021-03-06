/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node*prev = root;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            int x = q.size();
            Node* prev = q.front();
            while(x--)
            {
                if(prev != q.front())
                {
                    prev->next = q.front();
                    prev = q.front();
                }
                if(x == 0)
                {
                    q.front()->next = NULL;
                }
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return root;
    }
};