class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> in(n, 0), vis(n, 0);
        vector<vector<int>> adj(n, vector<int>()), adj2(n, vector<int>());
        for(vector<int> x: pre)
        {
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
            adj2[x[0]].push_back(x[1]);
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(in[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
        // cout<<q.size()<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<vis[i]<<" ";
        // }
        // cout<<endl;
        if(q.size() == 0)
            return false;
        while(q.size())
        {
            int x = q.front();
            q.pop();
            for(int y: adj[x])
            {
                if(vis[y] == 0)
                {
                    int f = 1;
                    for(int z: adj2[y])
                    {
                        if(vis[z] == 0)
                        {
                            f = 0;
                            break;
                        }
                    }
                    if(f == 1)
                    {
                        //cout<<y<<endl;
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
                return false;
        }
        return true;
    }
};