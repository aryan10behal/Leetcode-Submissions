// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void trav(vector<vector<int>> &graph, int s, vector<bool> &vis)
    {
        for(int x: graph[s])
        {
            if(!vis[x])
            {
                vis[x] = true;
                trav(graph, x, vis);
            }
        }
    }
    int biGraph(int arr[], int n, int e) {
        vector<vector<int>> graph(n, vector<int>());
        for(int i = 0; i<2*e;i+=2)
        {
            graph[arr[i]].push_back(arr[i+1]);
            graph[arr[i+1]].push_back(arr[i]);
        }
        for(int i = 0;i<n;i++)
        {
            for(int j: graph[i])
            {
                vector<bool> vis(n, false);
                vis[i] = true;
                vis[j] = true;
                trav(graph, i, vis);
                for(int k = 0;k<n;k++)
                {
                    // cout<<k<<":"<<vis[k]<<" ";
                    if(!vis[k])
                    {
                        //cout<<i<<" "<<k<<endl;
                        return false;
                    }
                }
                //cout<<endl;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends