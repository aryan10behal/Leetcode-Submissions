// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    void trav(Node* root, int target, Node* &x, unordered_map<Node*, Node*> &parent, Node* p)
    {
        if(root==NULL)
            return;
        parent[root] = p;
        if(root->data == target)
            {
                x = root;
                return;
            }
        trav(root->left, target, x, parent, root);
        trav(root->right, target, x, parent, root);
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        unordered_map<Node*, Node*> parent;
        Node* x;
        parent[root] = NULL;
        unordered_map<Node*, int> vis;
        trav(root, target, x, parent, NULL);
        queue<pair<Node*, int>> pq;
        int ans = 0;
        pq.push({x, k});
        vis[x] = 1;
        while(pq.size())
        {
            pair<Node*, int> p = pq.front();
            pq.pop();
            //cout<<p.first->data<<" ";
            ans+=p.first->data;
            if(p.second>0)
            {
                if(parent[p.first] and !vis[parent[p.first]])
                {
                    vis[parent[p.first]] = 1;
                    pq.push({parent[p.first], p.second-1});
                }
                if(p.first->left and !vis[p.first->left])
                {
                    vis[p.first->left] = 1;
                    pq.push({p.first->left, p.second-1});
                }
                if(p.first->right and !vis[p.first->right])
                {
                    vis[p.first->right] = 1;
                    pq.push({p.first->right, p.second-1});
                }
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends