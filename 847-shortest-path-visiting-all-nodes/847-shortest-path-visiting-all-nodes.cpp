class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), steps = 0, endmask = (1<<n) - 1;
        if(n == 1)
            return 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(endmask, 0));
        for(int i = 0;i<n;i++)
        {
            q.push({i, (1<<i)});
            vis[i][(1<<i)] = 1;
        }
        while(q.size())
        {
            queue<pair<int, int>> n_queue;
            while(q.size())
            {
                pair<int, int> p = q.front();
                q.pop();
                int node = p.first;
                int mask = p.second;
                for(int x: graph[node])
                {
                    int check_mask = (mask | (1<<x));
                    if(check_mask == endmask)
                        return 1+steps;
                    if(vis[x][check_mask] == 0)
                    {
                        vis[x][check_mask] = 1;
                        n_queue.push({x, check_mask});
                    }
                }
            }
            steps++;
            q = n_queue;
        }
        return 0;
    }
};