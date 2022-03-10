// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int trav(vector<vector<int>> &v, int root)
    {
        if(v[root].size() == 0)
            return 1;
        int k = 0;
        for(int i = 0;i<v[root].size();i++)
        {
            k = max(k, trav(v, v[root][i]));
        }
        return k+1;
    }
    int findHeight(int N, int arr[]){
        vector<vector<int>> v(N, vector<int>());
        int root = -1;
        for(int i = 0;i<N;i++)
        {
            if(arr[i] == -1)
                root = i;
            else
            {
                v[arr[i]].push_back(i);
            }
        }
        return trav(v, root);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends