// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void dfs(vector<int> graph[], int x, int bit, int arr[], int p)
    {
        arr[bit]++;
        for(int b: graph[x])
        {
            if(b!=p)
                dfs(graph, b, (bit+1)%2, arr, x); 
        }
    }
    int countOfNodes(vector<int> graph[], int n)
    {
        int arr[2] = {0,0};
        dfs(graph, 1, 0, arr, -1);
        return (arr[0]*(arr[0]-1))/2 + (arr[1]*(arr[1]-1))/2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends