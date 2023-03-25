class Solution {
public:
    int dfs(vector<vector<int>> &adj, int s, int p, vector<int> &vis)
    {
        int tt = 0;
        for(int x: adj[s])
        {
            if(x != p and vis[x] == 0)
            {
                vis[x] = 1;
                tt += dfs(adj, x, s, vis);
            }
        }
        return 1 + tt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int> ());
        for(vector<int> x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0);
        int c = -1;
        long long ans = 0, tt = 0;
        for(int i = i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                long long val = dfs(adj, i, -1, vis);
                ans += (n -  val)*val;
            }
        }
        return ans/2;
    }
};