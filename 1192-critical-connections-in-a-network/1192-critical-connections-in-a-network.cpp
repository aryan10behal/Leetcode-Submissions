class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &low, vector<int> &disc, vector<int> &vis, int v, int &time, vector<int> &parent, vector<vector<int>> &ans)
    {
        //cout<<v<<"-->"<<u<<endl;
        low[u] = disc[u] = time++;
        for(int x: adj[u])
        {
            if(vis[x] == 0)
            {
                vis[x] = 1;
                parent[x] = u;
                dfs(x, adj, low, disc, vis, u, time, parent, ans);
                low[u] = min(low[u], low[x]);
                if(low[x] > disc[u])
                {
                    vector<int> b = {u, x};
                    ans.push_back(b);
                }
            }
            else if(x != v)
            {
                //cout<<u<<" "<<v<<endl;
                low[u] = min(low[u], disc[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans, adj(n, vector<int>());
        for(vector<int> x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0), parent(n, -1);
        vector<int> disc(n, 1e9), low(n, 1e9);
        int time = 0;
        for(int i = 0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dfs(i, adj, low, disc, vis, -1, time, parent, ans);
            }
        }
        return ans;
    }
};