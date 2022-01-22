// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    struct node{
	        int val;
	        node* left;
	        node* right;
	        node(int x)
	        {
	            val = x;
	            left = NULL;
	            right = NULL;
	        }
	    };
           
         struct CompareHeight {
            bool operator()(node* const& p1, node* const& p2)
            {
                // return "true" if "p1" is ordered
                // before "p2", for example:
                return p1->val > p2->val;
            }
        }; 
        void inorder(node* root, vector<string> &x, string &z)
        {
            if(root == NULL)
                return;
            if(root->left == NULL && root->right == NULL)
            {
                x.push_back(z);
                return;
            }
            //cout<<z<<endl;
            if(root->left)
                {
                    z+='0';
                    inorder(root->left, x, z);
                    z.pop_back();
                }
            //cout<<root->val<<endl;
            if(root->right)
                {
                    z+='1';
                    inorder(root->right, x, z);
                    z.pop_back();
                }
            return;
        }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<node*, vector<node*>, CompareHeight> pq;
		    for(int x: f)
		    {
		        pq.push(new node(x));
		    }
		    while(pq.size()!=1)
		    {
		        node* a = pq.top();
		        pq.pop();
		        node* b = pq.top();
		        pq.pop();
		        node* x = new node(a->val + b->val);
		        x->left = a;
		        x->right = b;
		        //cout<<a->val<<endl;
		        pq.push(x);
		    }
		    vector<string> ans;
		    string z = "";
		    //cout<<pq.top()->val<<endl;
		    inorder(pq.top(), ans, z);
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends