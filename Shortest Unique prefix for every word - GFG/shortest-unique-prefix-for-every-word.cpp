// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
struct Node{
    Node *alp[26];
    bool isword;
    int count;
    Node()
    {
        count = 0;
        isword = false;
        for(int i = 0; i<26;i++)
            alp[i] = NULL;
    }
};
class Trie{
        Node* root;   
        public:
        Trie()
        {
            root = new Node();
        }
        void insert(string s)
        {
            Node* rt = root;
            for(char x: s)
            {
                rt->count++;
                if(rt->alp[x-'a'] == NULL)
                {
                    rt->alp[x-'a'] = new Node();
                }
                rt = rt->alp[x-'a'];
            }
            rt->isword = true;
        }
        string pref(string s)
        {
            Node* rt = root;
            string val = "";
            for(char x: s)
            {
                if(rt->count == 1)
                    break;
                val+=x;
                rt = rt->alp[x-'a'];
            }
            return val;
        }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie* trie = new Trie();
        for(int i = 0;i<n;i++)
        {
            trie->insert(arr[i]);
        }
        vector<string> ans(n);
        for(int i = 0;i<n;i++)
        {
            ans[i] = trie->pref(arr[i]);
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends