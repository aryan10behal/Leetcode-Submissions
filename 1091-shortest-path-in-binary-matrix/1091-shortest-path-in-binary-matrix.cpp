class Solution {
public:
    bool p(int x, int y, int m, int n)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0)
            return -1;
        int m = grid.size(), n = grid[0].size();
        int x_dir[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int y_dir[8] = {0, 1, 0, -1, -1, 1 , -1, 1};
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(q.size())
        {
            pair<int, int> x = q.front();
            q.pop();
            for(int i = 0;i<8;i++)
            {
                int k = x.first + x_dir[i];
                int l = x.second + y_dir[i];
                if(p(k, l, m, n) && grid[k][l] == 0 && dist[x.first][x.second] + 1 < dist[k][l])
                {
                    dist[k][l] = dist[x.first][x.second] + 1;
                    q.push({k, l});
                }
            }
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j = 0;j<n;j++)
        //        cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }
        return dist[m-1][n-1] == 1e9?-1:dist[m-1][n-1];
    }
};