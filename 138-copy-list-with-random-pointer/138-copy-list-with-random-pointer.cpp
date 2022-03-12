/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        map<Node*, Node*> corres;
        Node* x = head;
        Node* a = new Node(head->val);
        corres[x] = a;
        x = x->next;
        Node* prev = a;
        while(x!=NULL)
        {
            Node* y = new Node(x->val);
            corres[x] = y;
            prev->next = y;
            prev = y;
            x = x->next;     
        }
        x = head;
        prev = a;
        while(x!=NULL)
        {
            prev->random = corres[x->random];
            prev = prev->next;
            x = x->next;
        }
        return a;
    }
};