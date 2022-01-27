// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void inorder(Node* root, int target, vector<string> &v, string &x, string &t)
  {
        if(root->data == target)
            t = x;
        if(root->left == NULL and root->right == NULL)
            {
                v.push_back(x);
                return;
            }
        if(root->left)
        {
            x+='l';
            inorder(root->left, target, v, x, t);
            x.pop_back();
        }
        if(root->right)
        {
            x+='r';
            inorder(root->right, target, v, x, t);
            x.pop_back();
        }
        return;
  }
    int minTime(Node* root, int target) 
    {
        string x = "x";
        string t = "";
        vector<string> v;
        inorder(root, target, v, x, t);
        int ans = 0;
        int n = t.size();
        for(string k: v)
            {
                int i = 0, j = 0, val = 0;
                while(i<n && j<k.size() && k[j]==t[i])
                {
                    i++,j++;
                }
                if(i == n || j == k.size())
                    val = n - i + k.size() - j;
                else
                    val = n-i + k.size()-j;

                ans = max(ans, val);
            }
        return ans;
        // Your code goes here
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends