class Solution {
public:
    struct comp {
    constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b)const noexcept
    {
        return a.second > b.second;
    }
};
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for(vector<int> x: times)
        {
            adj[x[0]-1].push_back({x[1]-1, x[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
        dist[k-1] = 0;
        q.push({k-1, 0});
        while(q.size())
        {
            pair<int, int> x = q.top();
            q.pop();
            //cout<<x.first<<" "<<x.second<<endl;
            for(pair<int, int> f:adj[x.first])
            {
                if(x.second + f.second < dist[f.first])
                {
                    dist[f.first] = x.second + f.second;
                    q.push({f.first, dist[f.first]});
                }
            }
        }
        int m = -1;
        for(int i = 0;i<n;i++)
        {
            cout<<dist[i]<<" ";
            m = max(m, dist[i]);
        }
        return m == 1e9?-1:m;
    }
};