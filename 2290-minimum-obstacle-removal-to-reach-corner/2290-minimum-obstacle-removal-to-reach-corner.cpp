class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int x_dir[4] = {0,1,0,-1};
        int y_dir[4] = {-1,0,1,0};
        vector<vector<int>> cost(m, vector<int>(n, 1e9));
        cost[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(q.size())
        {
            pair<int, int> x = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int a = x.first + x_dir[i];
                int b = x.second + y_dir[i];
                if((a>=0 and a<m and b>=0 and b<n) and cost[x.first][x.second] + grid[a][b] < cost[a][b])
                {
                        cost[a][b] = cost[x.first][x.second] + grid[a][b];
                        q.push({a,b});
                }
            }
        }

        return cost[m-1][n-1];
    }
};