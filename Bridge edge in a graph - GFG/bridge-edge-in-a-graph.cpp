// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(int x, vector<int> &vis,  vector<int> adj[])
	{
	    for(int i: adj[x])
	    {
	        if(vis[i] == 0)
	            {
	                vis[i] = 1;
	                dfs(i, vis, adj);
	            }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> x(V, 0);
        x[c] = 1;
        for(int i: adj[c])
        {
            if(i==d)
                continue;
            else
                {
                    x[i] = 1;
                    dfs(i,x, adj);
                }
        }
        return (!x[d]);
        // Code here
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends