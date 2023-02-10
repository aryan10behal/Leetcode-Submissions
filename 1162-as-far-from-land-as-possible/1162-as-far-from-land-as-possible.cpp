class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
 
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> x(n, vector<int>(n, 0));
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                    x[i][j] = -1;
                }
            }
        }
        if(q.size() == 0 or q.size() == n*n)
            return -1;
        while(q.size())
        {
            vector<int> d = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx = d[0] + dx[i];
                int yy = d[1] + dy[i];
                if(xx>=0 and yy>=0 and xx<n and yy<n and x[xx][yy] == 0)
                {
                    x[xx][yy] = d[2] + 1;
                    q.push({xx, yy, d[2]+1});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                ans = max(ans, x[i][j]);
                
        }
        return ans;
    }
};