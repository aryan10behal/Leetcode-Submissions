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
    void trav(Node* root, unordered_map<Node*, Node*> &p, Node* parent, Node* &t, int target)
    {
        if(root==NULL)
            return;
        p[root] = parent;
        if(root->data == target)
            t = root;
        trav(root->left, p, root, t, target);
        trav(root->right, p, root, t, target);
    }
    void dfs(Node* target, unordered_map<Node*, Node*> &p, unordered_map<Node*, int> &vis, int &sum, int k)
{       
        if(target == NULL || k==-1 || vis[target] == 1)
         return;
        sum+=target->data;
        vis[target] = 1;
        dfs(p[target], p, vis, sum, k-1);
        dfs(target->left, p, vis, sum, k-1);
        dfs(target->right, p, vis, sum, k-1);
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        unordered_map<Node*, Node*> p;
        unordered_map<Node*, int> vis;
        Node* t = NULL;
        trav(root, p, NULL, t, target);
        int sum = 0;
        dfs(t, p, vis, sum, k);
        return sum;
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
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends